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

#ifndef FLIPWIDGET_H
#define FLIPWIDGET_H

//Qt
#include <QGraphicsView>

class QTimeLine;
class QGraphicsProxyWidget;
class RoundRectItem;

/**
    You can flip this widget over to show another widget.
    One possible use might be for showing the settings or configuration
    of a widget without having to show a dialog. It also just looks cool.

    @example
    @code

    QListWidget* frontWidget = new QListWidget;
    QListWidgetItem* listItem1 = new QListWidgetItem( "front side item", frontWidget );

    QWidget* backWidget = new QWidget;
    backWidget->setLayout( new QVBoxLayout );
    backWidget->layout()->addWidget( new QPushButton( "back side button" ) );

    //We want to display this flip widget in a dock widget
    QDockWidget* dock = new QDockWidget;
    QFlipWidget* flip = new QFlipWidget( dock->rect(), frontWidget, backWidget );
    dock->setWidget( flip );

    //We can optionally specify a border for the front and back widgets
    static const bool USE_BORDER = true;
    static const int BORDER_SIZE = 25;
    static const int ROUNDED_CORNERS = false;
    flip->SetBorder( QFlipWidget::FRONT, USE_BORDER, BORDER_SIZE, ROUNDED_CORNERS, QBrush( QColor( "red" ) ) );
    flip->SetBorder( QFlipWidget::BACK, USE_BORDER, BORDER_SIZE, ROUNDED_CORNERS, QBrush( QColor( "green" ) ) );

    //We can change these if the defaults are not acceptable
    flip->SetFlipDirection( QFlipWidget::HORIZONTAL );
    flip->SetFlipAnimation( QFlipWidget::NORMAL );
    flip->SetFlipDuration( 750 );
    @endcode
    @end
*/
class QFlipWidget : public QGraphicsView
{
    Q_OBJECT

public:

    /**
        Specifies the front or back side of this widget.
    */
    enum WIDGET_SIDE
    {
        FRONT = 0,
        BACK
    };

    /**
        Specifies the types of animations that can occur when flipping the widget.
    */
    enum ANIMATIONS
    {
        NORMAL = 0,	/** The widget appears to rotate in 3D space, moving away and then back towards the screen. */
        TURNSTILE,	/** The widget rotates as if connected to a turning vertical or horizontal bar. */
        FLYAWAY		/** The widget disappears some distance into the monitor before zooming back. Use SetFlyAwayDistance to control the distance. */
    };

    /**
        Specifies the direction to flip the widget.
    */
    enum FLIP_DIRECTION
    {
        HORIZONTAL = 0,
        VERTICAL
    };

    /**
        Construct me with a front and back widget, and the bounding rectangle that will contain the flip.
        You can optionally specify that you want the rendering to be done with OpenGL, which may be faster in some cases.
    */
    QFlipWidget( QRectF bounds, QWidget* frontWidget, QWidget* backWidget, bool useOpenGL = false, QWidget* parent = NULL );

    /**
        The direction to flip, either vertical or horizontal.
        Defaults to HORIZONTAL if not set.
    */
    void SetFlipDirection( FLIP_DIRECTION direction );

    /**
        Gets the current flip direction.
    */
    FLIP_DIRECTION GetFlipDirection();

    /**
        Sets the animation preference.
        Defaults to NORMAL if not set.
    */
    void SetFlipAnimation( ANIMATIONS type );

    /**
        Gets the current flip animation.
    */
    ANIMATIONS GetFlipAnimation();

    /**
        If the animation style is set to FLYAWAY, this specifies the distance.
    */
    void SetFlyAwayDistance( int distance );

    /**
        Gets the current fly away distance.
    */
    int GetFlyAwayDistance();

    /**
        Sets the animation time in milliseconds.
        Defaults to 750ms if not set.
    */
    void SetFlipDuration( int duration );

    /**
        Gets the flip animation duration in milliseconds.
    */
    int GetFlipDuration();

    /**
        Sets a border around either the front or back widget.
    */
    void SetBorder( WIDGET_SIDE side, bool useBorder, int borderSize = 0, bool roundedCorners = false, QBrush borderBrush = QBrush() );

    /**
        Sets a pixmap as the border background.
    */
    void SetBorderPixmap( WIDGET_SIDE side, const QPixmap & pixmap );

    /**
        Checks to see if the widget is flipped.
    */
    bool isFlipped();

    /**
        Checks to see in what direction the flip will occur.
    */
    bool isFlippedLeft();

    /**
        Checks to see if OpenGL is being used.
    */
    bool isOpenGL();

public slots:

    /**
        Flips the widget over to show the other widget.
        If the back widget is showing, then the front will be shown, etc...
        You can choose if you want the widget to flip from left to right or right to left.
    */
    void Flip( bool flipLeft = true );

private slots:

    /**
        @internal
        Used by the flip timeline.
        Does the work of flipping the widgets.
    */
    void updateFlipStep( qreal val );

protected:

    /**
        @internal
        Handles redrawing the front or back widget when this widget is resized.
    */
    void resizeEvent( QResizeEvent* event );

private:

    /**
        @internal
        The bounding rect to contain the flip.
    */
    QRectF m_bounds;

    /**
        @internal
        The QGraphicsItem shown on the front of the widget.
    */
    RoundRectItem* m_frontItem;

    /**
        @internal
        The QGraphicsItem shown on the back of the widget.
    */
    RoundRectItem* m_backItem;

    /**
        @internal
        The widget to show on the front.
        Embedded inside m_frontItem.
    */
    QWidget* m_frontWidget;

    /**
        @internal
        The widget to show on the back.
        Embedded inside m_backItem.
    */
    QWidget* m_backWidget;

    /**
        @internal
        The scene that contains the front and back items.
    */
    QGraphicsScene* m_scene;

    /**
        @internal
        The timeline used to animate the flip sequence.
    */
    QTimeLine* m_flipTimeLine;

    /**
        @internal
        The animation style.
    */
    ANIMATIONS m_animatedStyle;

    /**
        @internal
        The direction to flip, either vertical or horizontal.
        Defaults to horizontal.
    */
    FLIP_DIRECTION m_flipDirection;

    /**
        @internal
        If the animation style is set to FLYAWAY, this specifies the distance.
    */
    int m_flyAwayDistance;

    /**
        @internal
        Temporary x rotation used during the flip animation.
    */
    qreal m_xrot;

    /**
        @internal
        Temporary y rotation used during the flip animation.
    */
    qreal m_yrot;

    /**
        @internal
        Set when the widget flip is complete.
    */
    bool m_flipped;

    /**
        @internal
        Controls the direction of the flip: left to right or right to left.
    */
    bool m_flipLeft;

    /**
        @internal
        Flag to turn on or off OpenGL rendering.
        Defaults to false.
    */
    bool m_useOpenGL;

    /**
        @internal
        Border size. If not zero, a border will be drawn around the widget.
        Defaults to zero.
    */
    int m_frontBorderSize;
    int m_backBorderSize;

    /**
        Border type. The corners can be rounded or square.
        Defaults to square.
        Note that m_borderSize must be non-zero for the border to show up.
    */
    bool m_frontRoundedBorder;
    bool m_backRoundedBorder;

    /**
        The color and brush of the border.
        Defaults to the current window palette.
        Note that m_borderSize must be non-zero for the border to show up.
    */
    QBrush m_frontBorderBrush;
    QBrush m_backBorderBrush;
};
#endif
