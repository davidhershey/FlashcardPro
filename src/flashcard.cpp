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


#include "FlipWidget.h"
#include <QtWidgets>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QColorDialog>
#include <QLineEdit>
#include <QToolButton>
#include <QColor>
#include <QFileDialog>
#include "flashcard.h"

#include "imagebox.h"

Flashcard::Flashcard(QString ftext, QString btext, int cscore, QWidget *parent) :
    QWidget(parent),
    m_leftToRight( false ),
    m_roundedCorners( false),
    m_borderWidth( 0 ),
    m_frontBorder( false ),
    cardScore (cscore),
    fstr(ftext),
    bstr(btext),
    front(true),
    right(0),
    wrong(0)
{
    //--Flashcard
    QVBoxLayout* mainDialogLayout = new QVBoxLayout( this );

    //--Front Widget
    QWidget* frontWidget = new QWidget;

    QVBoxLayout* frontWidgetLayout = new QVBoxLayout( frontWidget );
    ImageBox* frontLabel = new ImageBox;
    frontLabel->setStyleSheet("QLabel { background-color : white; color : black; }");
    frontLabel->setText(ftext);
    frontLabel->setAlignment(Qt::AlignCenter);
    frontLabel->setWordWrap(true);
    QFont naxa;
    QFontDatabase db;
    naxa = db.font("Nexa Light","Normal",22);
    frontLabel->setFont(naxa);

    frontWidgetLayout->addWidget(frontLabel);

    //--BackWidget
    QWidget* backWidget = new QWidget;

    QVBoxLayout* backWidgetLayout = new QVBoxLayout( backWidget );
    ImageBox* backLabel = new ImageBox;
    backLabel->setStyleSheet("QLabel { background-color : white; color : black; }");
    backLabel->setText(btext);
    backLabel->setAlignment(Qt::AlignCenter);
    backLabel->setWordWrap(true);
    backLabel->setFont(naxa);
    backWidgetLayout->addWidget(backLabel);

    //--FlipWidget
    static const bool USE_OPEN_GL = false;
    m_flip = new QFlipWidget( this->rect(), frontWidget, backWidget, USE_OPEN_GL );

    mainDialogLayout->addWidget( m_flip );

    //--SIGNALS and SLOTS

    connect( frontLabel, SIGNAL(clicked()), this, SLOT(Flip()) );
    connect( backLabel, SIGNAL(clicked()), this, SLOT(Flip()) );
}

void Flashcard::Flip( bool leftToRight )
{
    m_flip->Flip( m_leftToRight );
    if(front) front=false;
    else front=true;
}

void Flashcard::Speed( int speed )
{
     m_flip->SetFlipDuration( speed );
}

void Flashcard::FlyAwayDistance( int distance )
{
    m_flip->SetFlyAwayDistance( distance );
}

void Flashcard::Horizontal()
{
    m_flip->SetFlipDirection( QFlipWidget::HORIZONTAL );
}

void Flashcard::Vertical()
{
     m_flip->SetFlipDirection( QFlipWidget::VERTICAL );
}

void Flashcard::LeftToRight()
{
    m_leftToRight = true;
}

void Flashcard::RightToLeft()
{
    m_leftToRight = false;
}

void Flashcard::Normal()
{
    m_flip->SetFlipAnimation( QFlipWidget::NORMAL );
}

void Flashcard::Turnstile()
{
     m_flip->SetFlipAnimation( QFlipWidget::TURNSTILE );
}

void Flashcard::FlyAway()
{
    m_flip->SetFlipAnimation( QFlipWidget::FLYAWAY );
}



Flashcard::~Flashcard()
{

}

int Flashcard::getScore()
{
    return cardScore;
}

void Flashcard::correct()
{
    cardScore++;
    right++;
}

void Flashcard::incorrect()
{
    cardScore = 0;
    wrong++;
}

bool Flashcard::isFront()
{
    return front;
}

int Flashcard::getWrong()
{
    return wrong;
}
