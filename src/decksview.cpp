#include "decksview.h"
#include "decklabel.h"
#include "builder.h"

DecksView::DecksView(QStackedWidget* pages_in, User *_user)
    :QFrame()
{
    user = _user;
    pages = pages_in;
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* topBar = new QHBoxLayout();


    QFont naxa;
    QFontDatabase db;
    naxa = db.font("Nexa Light","Normal",64);
    QLabel* title = new QLabel("Your Decks");
    title->setFont(naxa);
    title->setAlignment(Qt::AlignHCenter);
    title->setMaximumHeight(120);
    title->setMinimumHeight(120);

    backButton = new QPushButton("Back");
    backButton->setMinimumSize(100, 30);
    backButton->setMaximumSize(200, 30);
    connect(backButton, SIGNAL(clicked()), this, SLOT(goBack()));

    topBar->addWidget(backButton, 0, Qt::AlignLeft);
    topBar->addSpacerItem(new QSpacerItem((title->width()/2), title->height(),QSizePolicy::Expanding));
    topBar->addWidget(title, 0, Qt::AlignHCenter);
    topBar->addSpacerItem(new QSpacerItem((title->width()/2), title->height(), QSizePolicy::Expanding));
    topBar->setAlignment(mainLayout, Qt::AlignTop);

    decksLayout = new QGridLayout();
    loadLabel = new DeckLabel(NULL, pages);
    connect(loadLabel, SIGNAL(clicked()), this, SLOT(chooseCreateLoad()));
    decksLayout->addWidget(loadLabel, 0, 0);

    QSplitter *splitter = new QSplitter();
    QFrame *rightWidget = new QFrame();
    rightWidget->setLayout(decksLayout);
    rightWidget->setStyleSheet("QFrame { background-color: rgb(191, 197, 255); }");
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(1);
    scrollArea->setWidget(rightWidget);
    splitter->addWidget(scrollArea);

    mainLayout->addLayout(topBar);
    mainLayout->addWidget(splitter);
    setMinimumSize(700,500);
    setLayout(mainLayout);
    getUserDecks();
}

DecksView::~DecksView()
{

}

void DecksView::getUserDecks()
{
    QStringList list =  user->getDeckFiles();
    for (QStringList::iterator it = list.begin();it != list.end(); ++it) {
        QString fileName = *it;
        QFile myFile(fileName);
        myFile.open(QIODevice::ReadOnly);
        int fileHandle = myFile.handle();
        qDebug() << fileName;
        FILE* fh = fdopen(fileHandle, "rb");
        Deck* insDeck = new Deck(fh,user);
        addNewDeckLabel(insDeck);
    }

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
        Deck* insDeck = new Deck(fh,user);
        addNewDeckLabel(insDeck);

        qDebug() << insDeck->num_cards;
    }
}

void DecksView::goBack()
{
    int index = pages->currentIndex();
    pages->removeWidget(this);
    pages->setCurrentIndex(index - 1);
}

void DecksView::addNewDeckLabel(Deck* insDeck)
{
    decks.push_back(insDeck);
    DeckLabel* insLabel = new DeckLabel(insDeck, pages);
    insDeck->label = insLabel;

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
    builder* build = new builder(pages, this,user);
    int go = pages->addWidget(build);
    pages->setCurrentIndex(go);
}
