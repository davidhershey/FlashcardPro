#include "../include/flashcard.h"

Flashcard::Flashcard(QWidget *parent)
{
    int h = 150;
    int w = 150;
    this->setBackgroundRole(QPalette::Base); // some from http://qt-project.org/doc/qt-4.8/widgets-imageviewer.html
    this->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    this->setFixedHeight(h);
    this->setFixedWidth(w);
    this->setScaledContents(false);
    this->setFrameStyle(QFrame::Box | QFrame::Plain);
}

Flashcard::~Flashcard()
{

}

