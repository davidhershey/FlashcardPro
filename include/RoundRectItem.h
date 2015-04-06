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

#include <QtCore>
#include <QtGui>
#include <QtWidgets>

class QGraphicsProxyWidget;

/**
    A RoundRectItem is a QGraphicsRectItem that you can place in a QGraphicsScene.
    It is used to embded widgets, and you can specify a background behind the widget,
    which can either be a QBrush or a QPixmap.
*/
class RoundRectItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:

    /**
        Construct me with the size of the rectangle, the background brush, and an optional QWidget you want to embed.
    */
    RoundRectItem( const QRectF & rect, const QBrush & brush, QWidget* embeddedWidget = 0 );

    /**
        Returns the bounding rectangle of this item.
    */
    QRectF boundingRect() const;

    /**
        Sets a QPixmap as the background.
    */
    void setPixmap( const QPixmap & pixmap );

    /**
        Returns the current opacity of this item.
    */
    qreal opacity() const;

    /**
        Set the opacity of the item. The less opaque, the more the background brush or pixmap will show through the embedded widget.
        Note that 1.0 is the maximum opacity.
    */
    void setOpacity( qreal opacity );

    /**
        Sets the extent to which the background envelopes the embedded widget.
        Defaults to zero, or no border.
    */
    void setBorderWidth( qreal width );

    /**
        If the background is larger than the widget (border width is not zero) then you can choose to make the corners rounded or squared.
    */
    void setRoundBorder( bool round );

    /**
        Sets the border brush.
    */
    void setBorderBrush( const QBrush& brush );

protected:
    void paint( QPainter* painter, const QStyleOptionGraphicsItem*, QWidget* );

private:
    QBrush m_brush;
    QPixmap m_pixmap;
    qreal m_opacity;

    qreal m_borderWidth;
    bool m_roundBorder;

    QGraphicsProxyWidget* m_proxyWidget;
};
