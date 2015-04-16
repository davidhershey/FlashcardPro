#include "deckmenu.h"
#include <QtWidgets>
#include "studyarea.h"
#include "statsview.h"
#include "builder.h"

DeckMenu::DeckMenu(Deck* _deck,QStackedWidget* pages_in, QWidget *parent)
{
    pages = pages_in;
    deck = _deck;

    QVBoxLayout *vbox = new QVBoxLayout;

    QFont naxa;
    QFontDatabase db;
    naxa = db.font("Nexa Bold","Normal",40);

    _deck->menu = this;

    QHBoxLayout* topLayout = new QHBoxLayout();
    title = new QLabel(deck->deck_name);
    title->setFont(naxa);
    topLayout->addWidget(title);
    title->setAlignment(Qt::AlignLeft);

    quick_stats = new QLabel();
    quick_stats->setStyleSheet("color : blue;");
    quick_stats->setFont(naxa);
    quick_stats->setText("Current Deck Score:\n" + QString::number(deck->getDeckScore()));
    topLayout->addWidget(quick_stats);

    vbox->addLayout(topLayout);

    QPushButton *study = new QPushButton("Study Deck");
    vbox->addWidget(study);
    connect(study,SIGNAL(clicked()),this,SLOT(study()));

    QPushButton *edit = new QPushButton("Edit Deck");
    vbox->addWidget(edit);
    connect(edit,SIGNAL(clicked()), this, SLOT(edit()));

    QPushButton *stats = new QPushButton("View Deck Statistics");
    vbox->addWidget(stats);
    connect(stats,SIGNAL(clicked()),this,SLOT(stats()));

    QPushButton *save = new QPushButton("Save Deck Progress");
    vbox->addWidget(save);
    connect(save, SIGNAL(clicked()), this, SLOT(saveDeckCallback()));

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
    StudyArea* area = new StudyArea(deck, pages, this);
    int index = pages->addWidget(area);
    pages->setCurrentIndex(index);
}

void DeckMenu::edit()
{
    builder* edit = new builder(pages, deck);
    int index = pages->addWidget(edit);
    pages->setCurrentIndex(index);
}

void DeckMenu::stats()
{
    StatsView *sv = new StatsView(deck,pages);
    int index = pages->addWidget(sv);
    pages->setCurrentIndex(index);
}

void DeckMenu::back()
{
    int nextIndex = pages->currentIndex()-1;
    pages->removeWidget(pages->currentWidget());
    pages->setCurrentIndex(nextIndex);
}

void DeckMenu::saveDeckCallback()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Selected Deck"),
                                                    QDir::homePath() + QDir::separator() + "*",
                                                    "");
   deck->saveDeck(fileName);
}

void DeckMenu::updateMenu()
{
    quick_stats->setText("Current Deck Score:\n" + QString::number(deck->getDeckScore()));
}
