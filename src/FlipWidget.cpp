// *************************************************************************************************
//
// QFlipWidget v0.1
//
// Copyright (C) 2009 Josh Lareau (joshlareau@gmail.com)
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
//
// *************************************************************************************************

#include "../include/FlipWidget.h"

//Qt
#include <QTimeLine>
#include <QGraphicsProxyWidget>
#include <QGLFormat>

//QtTools
#include "RoundRectItem.h"

//std
#include <math.h>

QFlipWidget::QFlipWidget( QRectF bounds, QWidget* frontWidget, QWidget* backWidget, bool useOpenGL, QWidget* parent )
:
m_bounds( (-bounds.width() / 2.0), (-bounds.height() / 2.0), bounds.width(), bounds.height() ),
m_frontWidget( frontWidget ),
m_backWidget( backWidget ),
m_useOpenGL( useOpenGL ),
QGraphicsView( parent ),
m_flipped( false ),
m_flipLeft( false ),
m_animatedStyle( NORMAL ),
m_flipDirection( HORIZONTAL ),
m_flyAwayDistance( 10 ),
m_xrot( 0.0 ),
m_yrot( 0.0 ),
m_frontBorderSize( 0 ),
m_backBorderSize( 0 ),
m_frontRoundedBorder( false ),
m_backRoundedBorder( false ),
m_frontBorderBrush( this->palette().window() ),
m_backBorderBrush( this->palette().window() )
{
    setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    setCacheMode( CacheBackground );
    setViewportUpdateMode( FullViewportUpdate );
    setRenderHints( QPainter::Antialiasing | QPainter::SmoothPixmapTransform );

    if( m_useOpenGL )
    {
        setViewport( new QGLWidget( QGLFormat( QGL::SampleBuffers ) ) );
    }

    //Create the timeline to control the flip animation
    static const int DEFAULT_DURATION = 750;
    m_flipTimeLine = new QTimeLine( DEFAULT_DURATION, this );
    connect( m_flipTimeLine, SIGNAL( valueChanged( qreal ) ), this, SLOT( updateFlipStep( qreal ) ) );

    //Create a QGraphicsItem to embded the front widget
    m_frontItem = new RoundRectItem( m_bounds, m_frontBorderBrush, m_frontWidget );
    m_frontItem->setBorderWidth( m_frontBorderSize );
    m_frontItem->setRoundBorder( m_frontRoundedBorder );
    m_frontItem->setBorderBrush( m_frontBorderBrush );

    //Create a QGraphicsItem to embded the back widget
    m_backItem = new RoundRectItem( m_bounds, m_backBorderBrush, m_backWidget );
    m_backItem->setTransform( QTransform().rotate( 180, Qt::YAxis ) );
    m_backItem->setParentItem( m_frontItem );
    m_backItem->setBorderWidth( m_backBorderSize );
    m_backItem->setRoundBorder( m_backRoundedBorder );
    m_backItem->setBorderBrush( m_backBorderBrush );

    //Create the scene and add the items
    m_scene = new QGraphicsScene( m_frontItem->boundingRect(), this );
    this->setScene( m_scene );
    m_scene->addItem( m_frontItem );
    m_scene->addItem( m_backItem );
}

void QFlipWidget::SetFlipDirection( FLIP_DIRECTION direction )
{
    m_flipDirection = direction;
}

QFlipWidget::FLIP_DIRECTION QFlipWidget::GetFlipDirection()
{
    return m_flipDirection;
}

void QFlipWidget::SetFlipAnimation( ANIMATIONS type )
{
    m_animatedStyle = type;
}

QFlipWidget::ANIMATIONS QFlipWidget::GetFlipAnimation()
{
    return m_animatedStyle;
}

void QFlipWidget::SetFlipDuration( int duration )
{
    if( NULL != m_flipTimeLine )
    {
        m_flipTimeLine->setDuration( duration );
    }
}

int QFlipWidget::GetFlipDuration()
{
    if( NULL != m_flipTimeLine )
    {
        return m_flipTimeLine->duration();
    }
    else
    {
        return 0;
    }
}

void QFlipWidget::SetFlyAwayDistance( int distance )
{
    m_flyAwayDistance = distance;
}

int QFlipWidget::GetFlyAwayDistance()
{
    return m_flyAwayDistance;
}

bool QFlipWidget::isFlipped()
{
    return m_flipped;
}

bool QFlipWidget::isOpenGL()
{
    return m_useOpenGL;
}

bool QFlipWidget::isFlippedLeft()
{
    return m_flipLeft;
}

 void QFlipWidget::SetBorderPixmap( WIDGET_SIDE side, const QPixmap & pixmap )
 {
    if( side == BACK )
    {
        m_backItem->setPixmap( pixmap );
    }
    else if( side == FRONT )
    {
        m_frontItem->setPixmap( pixmap );
    }
 }

void QFlipWidget::SetBorder( WIDGET_SIDE side, bool useBorder, int borderSize, bool roundedCorners, QBrush& borderBrush )
{
    if( side == BACK )
    {
        if( useBorder )
        {
            m_backBorderSize = borderSize;
            m_backRoundedBorder = roundedCorners;
            m_backBorderBrush = borderBrush;
        }
        else
        {
            m_backBorderSize = 0;
            m_backRoundedBorder = false;
            m_backBorderBrush = QBrush();
        }

        m_backItem->setBorderWidth( m_backBorderSize );
        m_backItem->setRoundBorder( m_backRoundedBorder );
        m_backItem->setBorderBrush( m_backBorderBrush );
    }
    else if( side == FRONT )
    {
        if( useBorder )
        {
            m_frontBorderSize = borderSize;
            m_frontRoundedBorder = roundedCorners;
            m_frontBorderBrush = borderBrush;
        }
        else
        {
            m_frontBorderSize = 0;
            m_frontRoundedBorder = false;
            m_frontBorderBrush = QBrush();
        }

        m_frontItem->setBorderWidth( m_frontBorderSize );
        m_frontItem->setRoundBorder( m_frontRoundedBorder );
        m_frontItem->setBorderBrush( m_frontBorderBrush );
    }
}

void QFlipWidget::resizeEvent( QResizeEvent *event)
{
    QGraphicsView::resizeEvent( event );

    QRectF bounds( (-event->size().width() / 2.0), (-event->size().height() / 2.0), event->size().width(), event->size().height() );

    fitInView( bounds, Qt::KeepAspectRatio );

    if( m_frontItem->isVisible() )
    {
        m_frontItem->setRect( bounds );
    }

    if( m_backItem->isVisible() )
    {
        m_backItem->setRect( bounds );
    }
}

void QFlipWidget::updateFlipStep(qreal val)
{
    qreal finalxrot = m_xrot - m_xrot * val;
    qreal finalyrot;
    if( m_flipLeft )
    {
        finalyrot = m_yrot - m_yrot * val - 180 * val;
    }
    else
    {
        finalyrot = m_yrot - m_yrot * val + 180 * val;
    }

    qreal scale = 1 - sin( 3.14 * val ) * 0.3;

    //Flip Direction
    QTransform transform;
    if( m_flipDirection == HORIZONTAL )
    {
        transform.rotate( finalyrot, Qt::YAxis );
        transform.rotate( finalxrot, Qt::XAxis );
        m_backItem->setTransform( QTransform().rotate( 180, Qt::YAxis ) );
    }
    else if( m_flipDirection == VERTICAL )
    {
        transform.rotate( finalyrot, Qt::XAxis );
        transform.rotate( finalxrot, Qt::YAxis );
        m_backItem->setTransform( QTransform().rotate( 180, Qt::XAxis ) );
    }

    //Animation style
    if( m_animatedStyle == NORMAL )
    {
        transform.scale( scale, scale );
    }
    else if( m_animatedStyle == TURNSTILE )
    {
        transform.scale( 1, 1 );
    }
    else if( m_animatedStyle == FLYAWAY )
    {
        for( int fly = 0; fly != m_flyAwayDistance; ++fly )
        {
            transform.scale( scale, scale );
        }
    }

    m_frontItem->setTransform( transform );
}

void QFlipWidget::Flip( bool flipLeft )
{
    m_flipLeft = flipLeft;

    if( NULL == m_flipTimeLine )
    {
        return;
    }

    if( m_flipTimeLine->state() == QTimeLine::Running )
    {
        return;
    }

    if( m_flipTimeLine->currentValue() == 0 )
    {
        m_flipTimeLine->setDirection( QTimeLine::Forward );
        m_flipTimeLine->start();
        m_flipped = true;
    }
    else
    {
        m_flipTimeLine->setDirection( QTimeLine::Backward );
        m_flipTimeLine->start();
        m_flipped = false;
    }
}
