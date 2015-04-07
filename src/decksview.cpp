#include "decksview.h"
#include "decklabel.h"

DecksView::DecksView(QStackedWidget* pages_in)
    :QFrame()
{
    pages = pages_in;
    QVBoxLayout* mainLayout = new QVBoxLayout();

    decksLayout = new QGridLayout();
    loadLabel = new DeckLabel(NULL, pages);
    loadLabel->setStyleSheet("background-color: white; border: 1px solid");
    connect(loadLabel, SIGNAL(clicked()), this, SLOT(loadDeck()));
    decksLayout->addWidget(loadLabel, 0, 0);

    backButton = new QPushButton("Back");
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
    QString fileName =
      QFileDialog::getOpenFileName(this, tr("Pick a Deck"),
                                   QDir::homePath() + QDir::separator() + "*",
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
        decks.push_back(insDeck);
        DeckLabel* insLabel = new DeckLabel(insDeck, pages);
        connect(insLabel, SIGNAL(clicked()), insLabel, SLOT(chooseNext()));
        int i = decks.size()-1;
        QWidget* last = decksLayout->itemAtPosition(int(i/5),i%5)->widget();
        decksLayout->addWidget(insLabel,int(i/5),i%5);
        ++i;
        decksLayout->addWidget(last,int(i/5),i%5);
    }
}

void DecksView::goBack()
{
    pages->setCurrentIndex(1);
}
