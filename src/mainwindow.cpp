#include "mainwindow.h"
#include <QtWidgets>
#include "deck.h"
#include "decklabel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QMenu* fileMenu = this->menuBar()->addMenu("&File");
    loadAct = new QAction("&Load Deck",fileMenu);
    fileMenu->addAction(loadAct);

    connect(loadAct, SIGNAL(triggered()), this, SLOT(loadDeck()));

    QFrame* frame = new QFrame();
    decksLayout = new QGridLayout();
    frame->setLayout(decksLayout);
    frame->setMinimumSize(700,500);
    this->setCentralWidget(frame);

    DeckLabel* loadLabel = new DeckLabel(NULL);
    connect(loadLabel, SIGNAL(clicked()), this, SLOT(loadDeck()));
    decksLayout->addWidget(loadLabel, 0, 0);
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

