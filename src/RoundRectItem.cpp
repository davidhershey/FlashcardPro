// *************************************************************************************************
//
// RoundRectItem v0.1
// Based on the RoundRectItem class from the Qt examples. (See Nokia Copyright below)
// Modifications Copyright (C) 2009 Josh Lareau (joshlareau@gmail.com)
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

/****************************************************************************
**
** Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Qt Software Information (qt-info@nokia.com)
**
** This file is part of the example classes of the Qt Toolkit.
**
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License versions 2.0 or 3.0 as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file.  Please review the following information
** to ensure GNU General Public Licensing requirements will be met:
** http://www.fsf.org/licensing/licenses/info/GPLv2.html and
** http://www.gnu.org/copyleft/gpl.html.  In addition, as a special
** exception, Nokia gives you certain additional rights. These rights
** are described in the Nokia Qt GPL Exception version 1.3, included in
** the file GPL_EXCEPTION.txt in this package.
**
** Qt for Windows(R) Licensees
** As a special exception, Nokia, as the sole copyright holder for Qt
** Designer, grants users of the Qt/Eclipse Integration plug-in the
** right for the Qt/Eclipse Integration to link to functionality
** provided by Qt Designer and its related libraries.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
**
****************************************************************************/

#include "../include/roundrectitem.h"

//Qt
#include <QtGui/QtGui>

RoundRectItem::RoundRectItem( const QRectF & rect, const QBrush & brush, QWidget* embeddedWidget )
    : 
QGraphicsRectItem( rect ),
m_brush( brush ),
m_opacity( 1 ),
m_proxyWidget( 0 ),
m_borderWidth( 0 ),
m_roundBorder( false )
{ 
    if( embeddedWidget ) 
    {
        m_proxyWidget = new QGraphicsProxyWidget( this );
        m_proxyWidget->setFocusPolicy( Qt::StrongFocus );
        m_proxyWidget->setWidget( embeddedWidget );
        m_proxyWidget->setGeometry( boundingRect().adjusted( m_borderWidth, m_borderWidth, -m_borderWidth, -m_borderWidth ) );
    }
}

void RoundRectItem::paint( QPainter* painter, const QStyleOptionGraphicsItem*, QWidget * )
{
    QTransform x = painter->worldTransform();

    QLineF unit = x.map( QLineF( 0, 0, 1, 1 ) );
    if( unit.p1().x() > unit.p2().x() || unit.p1().y() > unit.p2().y() ) 
    {
        if( m_proxyWidget && m_proxyWidget->isVisible() ) 
        {
            m_proxyWidget->hide();
            m_proxyWidget->setGeometry( rect() );
        }
        return;
    }

    if( m_proxyWidget && !m_proxyWidget->isVisible() ) 
    {
        m_proxyWidget->show();
        m_proxyWidget->setFocus();
    }

    if( m_proxyWidget && m_proxyWidget->pos() != QPoint() )
    {
        m_proxyWidget->setGeometry( boundingRect().adjusted( m_borderWidth, m_borderWidth, -m_borderWidth, -m_borderWidth ) );
    }

    painter->setOpacity( opacity() );
    painter->setPen( Qt::NoPen );
    painter->setBrush( QColor(0, 0, 0, 64 ) );

    if( m_roundBorder )
    {
        painter->drawRoundRect( rect().translated( 2, 2 ) );
    }
    else
    {
        painter->drawRect( rect().translated( 2, 2 ) );
    }

    painter->setBrush( m_brush );
    painter->setPen( QPen( Qt::black, 1 ) );

    if( m_roundBorder )
    {
        painter->drawRoundRect( rect() );
    }
    else
    {
        painter->drawRect( rect() );
    }

    if( !m_pixmap.isNull() ) 
    {
        painter->scale( 1.95, 1.95 );
        painter->drawPixmap( -m_pixmap.width() / 2, -m_pixmap.height() / 2, m_pixmap );
    }
}

void RoundRectItem::setBorderBrush( const QBrush& brush )
{
    m_brush = brush;
}

void RoundRectItem::setBorderWidth( qreal width )
{
    m_borderWidth = width;
}

void RoundRectItem::setRoundBorder( bool round )
{
    m_roundBorder = round;
}

QRectF RoundRectItem::boundingRect() const
{
    qreal penW = 0.5;
    qreal shadowW = 2.0;
    return rect().adjusted( -penW, -penW, penW + shadowW, penW + shadowW );
}

void RoundRectItem::setPixmap( const QPixmap & pixmap )
{
    m_pixmap = pixmap;
    if( scene() && isVisible() )
    {
        update();
    }
}

qreal RoundRectItem::opacity() const
{
    RoundRectItem *parent = parentItem() ? (RoundRectItem*)parentItem() : 0;
    return m_opacity + ( parent ? parent->opacity() : 0 );
}

void RoundRectItem::setOpacity( qreal opacity )
{
    m_opacity = opacity;
    update();
}
