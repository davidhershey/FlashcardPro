#include "deckmenu.h"
#include <QtWidgets>
#include "studyarea.h"

DeckMenu::DeckMenu(Deck* _deck,QStackedWidget* pages_in, QWidget *parent)
{
    pages = pages_in;
    deck = _deck;
    QVBoxLayout *vbox = new QVBoxLayout;

    QLabel *title = new QLabel(deck->deck_name);
    vbox->addWidget(title);

    QPushButton *study = new QPushButton("Study Deck");
    vbox->addWidget(study);
    connect(study,SIGNAL(clicked()),this,SLOT(study()));

    QPushButton *edit = new QPushButton("Edit Deck");
    vbox->addWidget(edit);

    QPushButton *stats = new QPushButton("View Deck Statistics");
    vbox->addWidget(stats);

    QPushButton *save = new QPushButton("Save Deck Progress");
    vbox->addWidget(save);

    QPushButton *back = new QPushButton("Back to Decks");
    vbox->addWidget(back);
    connect(back,SIGNAL(clicked()),this,SLOT(back()));

    this->setLayout(vbox);
}

DeckMenu::~DeckMenu()
{

}

void DeckMenu::study()
{
    StudyArea* area = new StudyArea(deck, pages);
    int index = pages->addWidget(area);
    pages->setCurrentIndex(index);
}

void DeckMenu::edit()
{

}

void DeckMenu::stats()
{

}

void DeckMenu::back()
{
    int nextIndex = pages->currentIndex()-1;
    pages->removeWidget(pages->currentWidget());
    pages->setCurrentIndex(nextIndex);
}




