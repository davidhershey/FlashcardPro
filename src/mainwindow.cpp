#include "../include/mainwindow.h"
#include <QtWidgets>
#include "deck.h"
#include "studyarea.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui->setupUi(this);
    QMenu* fileMenu = this->menuBar()->addMenu("&File");
    loadAct = new QAction("&Load Deck",fileMenu);
    fileMenu->addAction(loadAct);
    saveAct = new QAction("&Save Deck",fileMenu);
    fileMenu->addAction(saveAct);
    QMenu* studyMenu = this->menuBar()->addMenu("&Study");
    studyAct = new QAction("&Study Deck",studyMenu);
    studyMenu->addAction(studyAct);
    studyAct->setEnabled(false);

    connect(loadAct, SIGNAL(triggered()), this, SLOT(loadDeck()));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveDeck()));
    connect(studyAct, SIGNAL(triggered()), this, SLOT(studyDeck()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadDeck()
{
    QString fileName =
      QFileDialog::getOpenFileName(this, tr("Pick a Set"),
                                   QDir::homePath() + QDir::separator() + "*",
                                   "*");
    if (fileName.isEmpty() || fileName.isNull())
      return;
    else
    {

        QFile myFile(fileName);
        myFile.open(QIODevice::ReadOnly);
        int fileHandle = myFile.handle();
        FILE* fh = fdopen(fileHandle, "rb");
        deck = new Deck(fh);
    }
    studyAct->setEnabled(true);
}

void MainWindow::saveDeck()
{

}

void MainWindow::studyDeck()
{
    StudyArea* area = new StudyArea(deck);
    area->exec();
}
