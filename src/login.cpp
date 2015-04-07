#include "login.h"

LogIn::LogIn(QStackedWidget* pages_in)
    :QFrame()
{
    pages = pages_in;
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(new QLabel("This is where the login page will be"));

    nextButton = new QPushButton("Log In");
    connect(nextButton, SIGNAL(clicked()), this, SLOT(nextPage()));
    layout->addWidget(nextButton);

    setLayout(layout);
}

LogIn::~LogIn()
{

}

void LogIn::nextPage()
{
    //LOGIC FOR LOGGING INTO DATABASE HERE
    //int current = pages->currentIndex();
    pages->setCurrentIndex(1);
}
