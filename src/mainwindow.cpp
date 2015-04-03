#include "mainwindow.h"
#include <QtWidgets>
#include "decksview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    /*QMenu* fileMenu = this->menuBar()->addMenu("&File");
    loadAct = new QAction("&Load Deck",fileMenu);
    fileMenu->addAction(loadAct);

    connect(loadAct, SIGNAL(triggered()), this, SLOT(loadDeck()));*/

    DecksView* decksView = new DecksView();
    //INSERT LOGIC FOR SWITCHING BETWEEN FRAMES HERE
    //setting this as central widget for now
    this->setCentralWidget(decksView);
}

MainWindow::~MainWindow()
{
}

void MainWindow::loadDeck()
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

