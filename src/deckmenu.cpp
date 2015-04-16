#include "deckmenu.h"
#include <QtWidgets>
#include "studyarea.h"
#include "statsview.h"
#include "builder.h"

DeckMenu::DeckMenu(Deck* _deck,QStackedWidget* pages_in,QWidget *parent)
{
    pages = pages_in;
    deck = _deck;

    QVBoxLayout *vbox = new QVBoxLayout;

    QFont naxa;
    QFontDatabase db;
    naxa = db.font("Nexa Bold","Normal",40);

    _deck->menu = this;

    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* topBar = new QHBoxLayout();


    title = new QLabel(deck->deck_name);
    title->setFont(naxa);
    title->setAlignment(Qt::AlignHCenter);
    title->setFixedHeight(70);

    QPushButton *backButton = new QPushButton("Back");
    connect(backButton,SIGNAL(clicked()),this,SLOT(back()));

    topBar->addWidget(backButton, 0, Qt::AlignLeft);
    topBar->addSpacerItem(new QSpacerItem((title->width()/2) - (backButton->width()/2), title->height(),QSizePolicy::Expanding));
    topBar->addWidget(title, 0, Qt::AlignHCenter);
    topBar->addSpacerItem(new QSpacerItem((title->width()/2), title->height(), QSizePolicy::Expanding));
    topBar->setAlignment(mainLayout, Qt::AlignTop);

    mainLayout->addLayout(topBar);

    quick_stats = new QLabel();
    quick_stats->setStyleSheet("color : blue;");
    quick_stats->setFont(naxa);
    quick_stats->setText("Current Deck Score:\n" + QString::number(deck->getDeckScore()));
    quick_stats->setAlignment(Qt::AlignHCenter);
    mainLayout->addWidget(quick_stats, 0, Qt::AlignCenter);

    sp = new ScorePlot(deck);
    mainLayout->addWidget(sp);
    sp->setMinimumSize(this->width()*.8, 300);

    QPushButton *study = new QPushButton("Study Deck");
    mainLayout->addWidget(study, 0, Qt::AlignCenter);
    connect(study,SIGNAL(clicked()),this,SLOT(study()));

    QPushButton *edit = new QPushButton("Edit Deck");
    mainLayout->addWidget(edit, 0, Qt::AlignCenter);
    connect(edit,SIGNAL(clicked()), this, SLOT(edit()));

    QPushButton *deleteDeck = new QPushButton("Delete Deck");
    mainLayout->addWidget(deleteDeck, 0, Qt::AlignCenter);
    connect(deleteDeck,SIGNAL(clicked()), this, SLOT(deleteDeck()));

//    mainLayout->addSpacerItem(new QSpacerItem(this->width(), this->height()/5));

    this->setLayout(mainLayout);
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

void DeckMenu::deleteDeck()
{
    deck->SELFDESTRUCT();
    back();
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
    sp->hide();
    sp = new ScorePlot(deck);
    sp->show();
}
