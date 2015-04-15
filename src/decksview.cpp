#include "decksview.h"
#include "decklabel.h"
#include "builder.h"

DecksView::DecksView(QStackedWidget* pages_in)
    :QFrame()
{
    pages = pages_in;
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* topBar = new QHBoxLayout();


    QFont naxa;
    QFontDatabase db;
    naxa = db.font("Nexa Light","Normal",64);
    QLabel* title = new QLabel("Your Decks");
    title->setFont(naxa);
    title->setAlignment(Qt::AlignHCenter);
    title->setMaximumHeight(50);

    backButton = new QPushButton("Switch User");
    backButton->setMinimumSize(100, 30);
    backButton->setMaximumSize(200, 30);
    connect(backButton, SIGNAL(clicked()), this, SLOT(goBack()));

    topBar->addWidget(backButton, 0, Qt::AlignLeft);
    topBar->addSpacerItem(new QSpacerItem((title->width()/2) - backButton->width(), title->height(),QSizePolicy::Expanding));
    topBar->addWidget(title, 0, Qt::AlignHCenter);
    topBar->addSpacerItem(new QSpacerItem((title->width()/2), title->height(), QSizePolicy::Expanding));
    topBar->setAlignment(mainLayout, Qt::AlignTop);

    decksLayout = new QGridLayout();
    loadLabel = new DeckLabel(NULL, pages);
    connect(loadLabel, SIGNAL(clicked()), this, SLOT(chooseCreateLoad()));
    decksLayout->addWidget(loadLabel, 0, 0);
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(1);
    scrollArea->setLayout(decksLayout);
    scrollArea->setStyleSheet("background-color: rgb(191, 197, 255); border: 0pt");

    mainLayout->addLayout(topBar);
    mainLayout->addWidget(scrollArea);
    setMinimumSize(700,500);
    setLayout(mainLayout);
}

DecksView::~DecksView()
{

}

void DecksView::loadDeck()
{
    QString fileName =QFileDialog::getOpenFileName(this, tr("Pick a Deck"),
                                                   "*",
                                                   tr("Text File (*.txt)"));

    if (fileName.isEmpty() || fileName.isNull())
      return;
    else
    {

        QFile myFile(fileName);
        myFile.open(QIODevice::ReadOnly);
        int fileHandle = myFile.handle();
        FILE* fh = fdopen(fileHandle, "rb");
        Deck* insDeck = new Deck(fh);
        addNewDeckLabel(insDeck);

        qDebug() << insDeck->num_cards;
    }
}

void DecksView::goBack()
{
    pages->setCurrentIndex(0);
}

void DecksView::addNewDeckLabel(Deck* insDeck)
{
    decks.push_back(insDeck);
    DeckLabel* insLabel = new DeckLabel(insDeck, pages);
    connect(insLabel, SIGNAL(clicked()) , insLabel, SLOT(openDeck()));
    int i = decks.size()-1;
    QWidget* last = decksLayout->itemAtPosition(int(i/5),i%5)->widget();
    decksLayout->addWidget(insLabel,int(i/5),i%5);
    ++i;
    decksLayout->addWidget(last,int(i/5),i%5);
}

void DecksView::chooseCreateLoad()
{
    QDialog* chooseDialog = new QDialog();
    QVBoxLayout* layout = new QVBoxLayout();
    QPushButton* createButton = new QPushButton("Create New Deck");
    QPushButton* loadButton = new QPushButton("Load Deck");
    QPushButton* cancButton = new QPushButton("Cancel");
    connect(createButton, SIGNAL(clicked()), this, SLOT(goToCreator()));
    connect(loadButton, SIGNAL(clicked()), this, SLOT(loadDeck()));
    connect(createButton, SIGNAL(clicked()), chooseDialog, SLOT(accept()));
    connect(loadButton, SIGNAL(clicked()), chooseDialog, SLOT(accept()));
    connect(cancButton, SIGNAL(clicked()), chooseDialog, SLOT(reject()));
    layout->addWidget(createButton);
    layout->addWidget(loadButton);
    layout->addWidget(cancButton);
    chooseDialog->setLayout(layout);
    chooseDialog->exec();
    return;
}

void DecksView::goToCreator()
{
    builder* build = new builder(pages, this);
    pages->addWidget(build);
    pages->setCurrentIndex(2);
}
