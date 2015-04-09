#include "decksview.h"
#include "decklabel.h"
#include "deckmenu.h"
#include "builder.h"

DecksView::DecksView(QStackedWidget* pages_in)
    :QFrame()
{
    pages = pages_in;
    QVBoxLayout* mainLayout = new QVBoxLayout();

    decksLayout = new QGridLayout();
    loadLabel = new DeckLabel(NULL, pages);
    loadLabel->setStyleSheet("background-color: white; border: 1px solid");
    connect(loadLabel, SIGNAL(clicked(Deck*)), this, SLOT(chooseCreateLoad()));
    decksLayout->addWidget(loadLabel, 0, 0);

    backButton = new QPushButton("Switch User");
    connect(backButton, SIGNAL(clicked()), this, SLOT(goBack()));

    mainLayout->addLayout(decksLayout);
    mainLayout->addWidget(backButton);
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
    }
}

void DecksView::openDeck(Deck* deck)
{
    DeckMenu *dm = new DeckMenu(deck,pages);
    int index = pages->addWidget(dm);
    pages->setCurrentIndex(index);
}

void DecksView::goBack()
{
    pages->setCurrentIndex(0);
}

void DecksView::addNewDeckLabel(Deck* insDeck)
{
    decks.push_back(insDeck);
    DeckLabel* insLabel = new DeckLabel(insDeck, pages);
    connect(insLabel, &DeckLabel::clicked , this, &DecksView::openDeck);
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
    //JARED THIS IS WHERE THE CREATE NEW PAGE SHOULD BE ADDED TO THE QSTACKEDWIDGET
    builder* build = new builder(pages, this);
    pages->addWidget(build);
    pages->setCurrentIndex(2);
}
