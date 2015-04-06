//Study Area
#include "studyarea.h"
#include "flashcard.h"
#include <QtWidgets>
#include <QtGui>

StudyArea::StudyArea(Deck *_deck, QWidget *parent) : QGraphicsView(parent)
{
    grid = new QGridLayout;
    deck = _deck;
    curCard = _deck->getTop();
    grid->addWidget(curCard,1,0,1,2);

    QPushButton *back = new QPushButton("Back to Deck Selection");
    grid->addWidget(back,0,0,1,1);

    QPushButton *right = new QPushButton;
    right->setFixedSize(65,65);
    QPixmap pm(":/images/check-button.png");
    QIcon ic(pm);
    right->setIcon(ic);
    QSize iconSize(65, 65);
    right->setIconSize(iconSize);
    grid->addWidget(right,2,0,1,1,Qt::AlignLeft);
    connect(right,SIGNAL(clicked()),this,SLOT(correct()));

    QPushButton *wrong = new QPushButton;
    wrong->setFixedSize(65,65);
    QPixmap pm2(":/images/xbutton.png");
    QIcon ic2(pm2);
    wrong->setIcon(ic2);
    wrong->setIconSize(iconSize);
    grid->addWidget(wrong,2,1,1,1,Qt::AlignRight);
    connect(wrong,SIGNAL(clicked()),this,SLOT(incorrect()));

    grid->setRowStretch(0,0);
    grid->setRowStretch(1,1);
    grid->setRowStretch(2,0);
    this->setLayout(grid);
}

StudyArea::~StudyArea()
{

}

void StudyArea::correct()
{
    curCard->correct();
    deck->shuffle();
    grid->removeWidget(curCard);
    curCard->hide();
    curCard = deck->getTop();
    grid->addWidget(curCard,1,0,1,2);
    curCard->show();

}

void StudyArea::incorrect()
{
    curCard->incorrect();
    deck->shuffle();
    grid->removeWidget(curCard);
    curCard->hide();
    curCard = deck->getTop();
    grid->addWidget(curCard,1,0,1,2);
    curCard->show();
}

