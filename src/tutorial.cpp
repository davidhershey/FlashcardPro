#include "tutorial.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QFontDatabase>
Tutorial::Tutorial()
    :QDialog()
{
    QLabel* title = new QLabel("Tutorial");
    QFont naxa;
    QFontDatabase db;
    naxa = db.font("Nexa Light","Normal",64);
    title->setFont(naxa);

    next = new QPushButton("Next");
    prev = new QPushButton("Previous");
    connect(next, SIGNAL(clicked()), this, SLOT(nextCallback()));
    connect(prev, SIGNAL(clicked()), this, SLOT(prevCallback()));
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(prev);
    layout->addWidget(next);

    tutPages = new QStackedWidget();
    tutPages->addWidget(createUserTutPage());
    tutPages->addWidget(createDecksViewTutPage());
    tutPages->addWidget(createDeckMenuTutPage());
    tutPages->addWidget(createStudyAreaTutPage());
    tutPages->addWidget(createDonePage());

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(title);
    mainLayout->addWidget(tutPages);
    mainLayout->addLayout(layout);
    setLayout(mainLayout);
}

Tutorial::~Tutorial()
{

}

void Tutorial::prevCallback()
{
    if(tutPages->currentIndex() == 0) return;
    tutPages->setCurrentIndex(tutPages->currentIndex()-1);
}

void Tutorial::nextCallback()
{
    if(tutPages->currentIndex() == tutPages->count()) return;
    tutPages->setCurrentIndex(tutPages->currentIndex()+1);
}

QFrame* Tutorial::createUserTutPage()
{
    QFrame* frame = new QFrame(this);
    QLabel* label = new QLabel("You've just created a new user");
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(label);
    frame->setLayout(layout);
    return frame;
}

QFrame* Tutorial::createDecksViewTutPage()
{
    QFrame* frame = new QFrame(this);
    QLabel* label = new QLabel("Decks View Tut Page");
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(label);
    frame->setLayout(layout);
    return frame;
}

QFrame* Tutorial::createDeckMenuTutPage()
{
    QFrame* frame = new QFrame(this);
    QLabel* label = new QLabel("Deck Menu Tut Page");
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(label);
    frame->setLayout(layout);
    return frame;
}

QFrame* Tutorial::createStudyAreaTutPage()
{
    QFrame* frame = new QFrame(this);
    QLabel* label = new QLabel("Study Area Tut Page");
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(label);
    frame->setLayout(layout);
    return frame;
}

QFrame* Tutorial::createDonePage()
{
    QFrame* frame = new QFrame(this);
    QLabel* label = new QLabel("You're done!");
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(label);
    frame->setLayout(layout);
    return frame;
}
