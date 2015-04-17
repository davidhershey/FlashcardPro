#include "statsview.h"
#include "scoreplot.h"
#include <QtWidgets>

StatsView::StatsView(Deck *_deck, QStackedWidget* pages_in,QWidget *parent)
{
    pages= pages_in;
    deck = _deck;
    vbox = new QVBoxLayout;

    QLabel *title = new QLabel;
    title->setText(deck->deck_name);
    title->setAlignment(Qt::AlignCenter);
    vbox->addWidget(title);

//    QLabel *scoreLabel = new QLabel;
//    scoreLabel->setText("Deck Score: " + QString::number(deck->getDeckScore()));
//    scoreLabel->setAlignment(Qt::AlignCenter);
//    vbox->addWidget(scoreLabel);
    ScorePlot *sp = new ScorePlot(deck);
    vbox->addWidget(sp);

    QLabel *hardest = new QLabel;
    vbox->addWidget(hardest);
    hardest->setText("Hardest Question:\n" + deck->getHardest()->fstr);
    hardest->setAlignment(Qt::AlignCenter);

    QPushButton *back = new QPushButton("Return to Deck Options");
    vbox->addWidget(back);
    connect(back,SIGNAL(clicked()),this,SLOT(goBack()));

    this->setLayout(vbox);
}

StatsView::~StatsView()
{

}

void StatsView::goBack()
{
    int nextIndex = pages->currentIndex()-1;
    pages->removeWidget(pages->currentWidget());
    pages->setCurrentIndex(nextIndex);
}

