#include "mainwindow.h"
#include <QtWidgets>
#include "decksview.h"
#include "login.h"
#include "mainmenu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    pages = new QStackedWidget();
    pages->setStyleSheet("QStackedWidget { background-color: rgb(191, 197, 255); }");
    LogIn* loginPage = new LogIn(pages);

    mainmenu* menuPage = new mainmenu(pages);
    DecksView *decksPage = new DecksView(pages);
    pages->addWidget(loginPage);                //Login is index 0
    pages->addWidget(decksPage);

    this->setCentralWidget(pages);
}

MainWindow::~MainWindow()
{
}
