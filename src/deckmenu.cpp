#include "deckmenu.h"
#include <QtWidgets>
#include "studyarea.h"
#include "statsview.h"
#include "builder.h"
#include "scoreplot.h"
DeckMenu::DeckMenu(Deck* _deck,QStackedWidget* pages_in, QWidget *parent)
{
    pages = pages_in;
    deck = _deck;

    QVBoxLayout *vbox = new QVBoxLayout;

    QFont naxa;
    QFontDatabase db;
    naxa = db.font("Nexa Bold","Normal",40);

    _deck->menu = this;

    QVBoxLayout* rightLayout = new QVBoxLayout();

    rightLayout->addSpacerItem(new QSpacerItem(this->width(), this->height()/4));

    title = new QLabel(deck->deck_name);
    title->setFont(naxa);
    title->setAlignment(Qt::AlignHCenter);
    rightLayout->addWidget(title, 0, Qt::AlignCenter);

    quick_stats = new QLabel();
    quick_stats->setStyleSheet("color : blue;");
    quick_stats->setFont(naxa);
    quick_stats->setText("Current Deck Score:\n" + QString::number(deck->getDeckScore()));
    quick_stats->setAlignment(Qt::AlignHCenter);
    rightLayout->addWidget(quick_stats, 0, Qt::AlignCenter);


    ScorePlot *sp = new ScorePlot(deck);
    rightLayout->addWidget(sp);

    rightLayout->addSpacerItem(new QSpacerItem(this->width(), this->height()/8));
    QPushButton *study = new QPushButton("Study Deck");
    rightLayout->addWidget(study, 0, Qt::AlignCenter);
    connect(study,SIGNAL(clicked()),this,SLOT(study()));

    QPushButton *edit = new QPushButton("Edit Deck");
    rightLayout->addWidget(edit, 0, Qt::AlignCenter);
    connect(edit,SIGNAL(clicked()), this, SLOT(edit()));

    QPushButton *stats = new QPushButton("View Deck Statistics");
    rightLayout->addWidget(stats, 0, Qt::AlignCenter);
    connect(stats,SIGNAL(clicked()),this,SLOT(stats()));

    QPushButton *back = new QPushButton("Back to Decks");
    rightLayout->addWidget(back, 0, Qt::AlignCenter);
    connect(back,SIGNAL(clicked()),this,SLOT(back()));
    rightLayout->addSpacerItem(new QSpacerItem(this->width(), this->height()/4));

    this->setLayout(rightLayout);
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
