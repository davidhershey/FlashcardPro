#include "mainwindow.h"
#include <QtWidgets>
#include "decksview.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    pages = new QStackedWidget();
    LogIn* loginPage = new LogIn(pages);
    DecksView* decksView = new DecksView(pages);
    pages->addWidget(loginPage);
    pages->addWidget(decksView);
    this->setCentralWidget(pages);
}

MainWindow::~MainWindow()
{
}

