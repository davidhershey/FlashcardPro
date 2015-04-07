#include "mainwindow.h"
#include <QtWidgets>
#include "decksview.h"
#include "login.h"
#include "mainmenu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    pages = new QStackedWidget();
    LogIn* loginPage = new LogIn(pages);

    mainmenu* menuPage = new mainmenu(pages);

    LogIn* connectPage = new LogIn(pages);
    LogIn* statsPage = new LogIn(pages);
    LogIn* builderPage = new LogIn(pages);

    DecksView* decksView = new DecksView(pages);
    pages->addWidget(loginPage);                //Login is index 0

    pages->addWidget(menuPage);                 //Menu is index 1
    pages->addWidget(statsPage);                //Stats is index 2
    pages->addWidget(decksView);                //Decks is index 3
    pages->addWidget(connectPage);              //Connect is index 4
    pages->addWidget(builderPage);              // builder is index 5

    this->setCentralWidget(pages);
}

MainWindow::~MainWindow()
{
}
