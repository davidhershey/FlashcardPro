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

    QFont naxa, naxa2;
    QFontDatabase db;
    naxa = db.font("Nexa Bold","Normal",40);
    naxa2 = db.font("Nexa Light", "Normal", 18);

    _deck->menu = this;

    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* topBar = new QHBoxLayout();


    title = new QLabel(deck->deck_name);
    title->setFont(naxa);
    title->setAlignment(Qt::AlignHCenter);
    title->setFixedHeight(70);

    QPushButton *backButton = new QPushButton("Back");
    backButton->setFont(naxa2);
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
    study->setFont(naxa2);
    study->setMinimumWidth(175);
    connect(study,SIGNAL(clicked()),this,SLOT(study()));

    QPushButton *edit = new QPushButton("Edit Deck");
    mainLayout->addWidget(edit, 0, Qt::AlignCenter);
    edit->setFont(naxa2);
    edit->setMinimumWidth(175);
    connect(edit,SIGNAL(clicked()), this, SLOT(edit()));

    QPushButton *deleteDeck = new QPushButton("Delete Deck");
    mainLayout->addWidget(deleteDeck, 0, Qt::AlignCenter);
    deleteDeck->setFont(naxa2);
    deleteDeck->setMinimumWidth(175);

    connect(deleteDeck,SIGNAL(clicked()), this, SLOT(deleteDeck()));

//    mainLayout->addSpacerItem(new QSpacerItem(this->width(), this->height()/5));

    this->setLayout(mainLayout);
}

DeckMenu::~DeckMenu()
{

}

void DeckMenu::study()
{
    if(pages == NULL) return;
    StudyArea* area = new StudyArea(deck, pages, this);
    int index = pages->addWidget(area);
    pages->setCurrentIndex(index);
}

void DeckMenu::edit()
{
    if(pages == NULL) return;
    builder* edit = new builder(pages, deck);
    int index = pages->addWidget(edit);
    pages->setCurrentIndex(index);
}

void DeckMenu::deleteDeck()
{
    confirm = new QDialog();
    QVBoxLayout* layout = new QVBoxLayout();
    QLabel *label = new QLabel(tr("Are you sure you want to delete this deck?"));
    QPushButton* yes = new QPushButton("Yes");
    QPushButton* no = new QPushButton("No");

    QFont naxa;
    QFontDatabase db;
    naxa = db.font("Naxa Light", "Normal", 18);

    label->setFont(naxa);
    yes->setFont(naxa);
    no->setFont(naxa);


    QHBoxLayout* layout2 = new QHBoxLayout();
    layout->addWidget(label);
    layout->addLayout(layout2);
    layout2->addWidget(yes);
    layout2->addWidget(no);
    connect(yes, SIGNAL(clicked()), this, SLOT(yes()));
    connect(no, SIGNAL(clicked()), this, SLOT(no()));
    confirm->setLayout(layout);
    confirm->exec();
    return;


}

void DeckMenu::yes(){
    if(pages == NULL) return;
    deck->SELFDESTRUCT();
    back();
    confirm->close();
}

void DeckMenu::no(){
    confirm->close();
}

void DeckMenu::stats()
{
    if(pages == NULL) return;
    StatsView *sv = new StatsView(deck,pages);
    int index = pages->addWidget(sv);
    pages->setCurrentIndex(index);
}

void DeckMenu::back()
{
    if(pages == NULL) return;
    int nextIndex = pages->currentIndex()-1;
    pages->removeWidget(pages->currentWidget());
    pages->setCurrentIndex(nextIndex);
}

void DeckMenu::saveDeckCallback()
{
    if(pages == NULL) return;
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
