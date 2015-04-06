// *************************************************************************************************
//
// QFlipWidget Demo v0.1
//
// Copyright (C) 2009 Josh Lareau (joshlareau@gmail.com)
//
// This application is free software; you can redistribute it and/or
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

#ifndef DEMO_H
#define DEMO_H

#include <QDialog>

class QFlipWidget;
class QLineEdit;

class Flashcard : public QWidget
{
    Q_OBJECT

public:
    Flashcard(QString ftext, QString btext, int cscore, QWidget *parent = 0);
    ~Flashcard();
    int getScore();
    void correct();
    void incorrect();

public slots:

    void Flip( bool leftToRight = true );

private slots:

    void Horizontal();
    void Vertical();
    void LeftToRight();
    void RightToLeft();

    void Normal();
    void Turnstile();
    void FlyAway();

    void Speed( int speed );
    void FlyAwayDistance( int distance );

 private:
    QFlipWidget* m_flip;
    bool m_leftToRight;
    bool m_roundedCorners;
    QBrush m_brush;
    int m_borderWidth;
    bool m_frontBorder;
    QLineEdit* m_colorEdit;
    QLineEdit* m_pathEdit;
    QString fstr;
    QString bstr;
    int cardScore;
};
#endif // DEMO_H
