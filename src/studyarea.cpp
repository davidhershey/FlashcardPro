//Study Area
#include "studyarea.h"
#include "flashcard.h"
#include <QtWidgets>
#include <QtGui>

StudyArea::StudyArea(Deck *_deck, QStackedWidget* pages_in, QWidget *parent) : QGraphicsView(parent)
{
    scores = new QLabel;
    grid = new QGridLayout;
    deck = _deck;
    pages = pages_in;
    curCard = _deck->getTop();
    grid->addWidget(curCard,1,0,1,3);

    QPushButton *back = new QPushButton("Back to Deck Selection");
    connect(back, SIGNAL(clicked()), this, SLOT(goBack()));
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
    grid->addWidget(wrong,2,2,1,1,Qt::AlignRight);
    connect(wrong,SIGNAL(clicked()),this,SLOT(incorrect()));

    scores->setText("Card Score: " + QString::number(curCard->getScore()));
    grid->addWidget(scores,2,1,1,1,Qt::AlignCenter);

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
    if (!curCard->isFront()) curCard->Flip();
    curCard = deck->getTop();
    grid->addWidget(curCard,1,0,1,3);
    curCard->show();
    scores->setText("Card Score: " + QString::number(curCard->getScore()));

}

void StudyArea::incorrect()
{
    curCard->incorrect();
    deck->shuffle();
    grid->removeWidget(curCard);
    curCard->hide();
    if (!curCard->isFront()) curCard->Flip();
    curCard = deck->getTop();
    grid->addWidget(curCard,1,0,1,3);
    curCard->show();
    scores->setText("Card Score: " + QString::number(curCard->getScore()));

}

void StudyArea::goBack()
{
    pages->removeWidget(pages->currentWidget());
    pages->setCurrentIndex(3);
}
