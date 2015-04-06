#include "studyarea.h"

StudyArea::StudyArea(Deck* deck_in)
    :QFrame()
{
    deck = deck_in;
    current_card = 0;
    if(!deck->cards.size())
    {
        qDebug() << "Error: no cards in deck! Exiting study area constructor.";
        return;
    }

    //add first card to graphics scene
    grid = new QGridLayout(this);
    grid->addWidget(deck->cards.at(current_card),0,0,2,1);
//    scene->addItem(deck->cards.at(current_card));
//    QGraphicsView* view = new QGraphicsView(scene);
//    view->show();

    //Set up layout of window
    //prev button, card, next button
    prevButton = new QPushButton("Prev");
    grid->addWidget(prevButton,1,0,1,1);
    nextButton = new QPushButton("Next");
    grid->addWidget(nextButton,1,1,1,1);
    connect(prevButton, SIGNAL(clicked()), this, SLOT(prevCard()));
    connect(nextButton, SIGNAL(clicked()), this, SLOT(nextCard()));
//    QVBoxLayout* innervlayout = new QVBoxLayout();
//    innervlayout->addWidget(view);
//    QHBoxLayout* innerhlayout = new QHBoxLayout();
//    innerhlayout->addWidget(prevButton);
//    innerhlayout->addWidget(nextButton);
//    QVBoxLayout* vlayout = new QVBoxLayout();
//    vlayout->addLayout(innervlayout);
//    vlayout->addLayout(innerhlayout);
//    setLayout(vlayout);
}

StudyArea::~StudyArea()
{

}

void StudyArea::prevCard()
{
    if(current_card <= 0)
    {
        //COULD CHANGE THIS TO WRAP AROUND TO END OF DECK
        qDebug() << "No previous card!";
        return;
    }
    grid->removeWidget(deck->cards.at(current_card--));
    grid->addWidget(deck->cards.at(current_card),0,0,1,2);
}

void StudyArea::nextCard()
{
    if(current_card+1 >= deck->cards.size())
    {
        //ADD WHAT HAPPENS AT END OF DECK HERE
        qDebug() << "No next card!";
        return;
    }
    grid->removeWidget(deck->cards.at(current_card++));
    grid->addWidget(deck->cards.at(current_card),0,0,1,2);
}
