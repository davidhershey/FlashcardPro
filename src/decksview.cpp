#include "decksview.h"
#include "decklabel.h"

DecksView::DecksView(QStackedWidget* pages_in)
    :QFrame()
{
    pages = pages_in;
    decksLayout = new QGridLayout();
    setLayout(decksLayout);
    setMinimumSize(700,500);

    loadLabel = new DeckLabel(NULL);
    loadLabel->setStyleSheet("background-color: white; border: 1px solid");
    connect(loadLabel, SIGNAL(clicked()), this, SLOT(loadDeck()));
    decksLayout->addWidget(loadLabel, 0, 0);
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
        DeckLabel* insLabel = new DeckLabel(insDeck);
        connect(insLabel, SIGNAL(clicked()), insLabel, SLOT(chooseNext()));
        int i = decks.size()-1;
        QWidget* last = decksLayout->itemAtPosition(int(i/5),i%5)->widget();
        decksLayout->addWidget(insLabel,int(i/5),i%5);
        ++i;
        decksLayout->addWidget(last,int(i/5),i%5);
    }
}
