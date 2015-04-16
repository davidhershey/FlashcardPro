#include "userselect.h"
#include "newuser.h"

#include <vector>
#include <QVBoxLayout>
#include <QtWidgets>
#include "newuser.h"
UserSelect::UserSelect(QStackedWidget *pages_in, std::vector<User*> users_in, LogIn* parent_in)
{
    QFrame();
    pages = pages_in;
    users = users_in;
    parent = parent_in;

    QVBoxLayout* layout = new QVBoxLayout();
    QHBoxLayout* topBar = new QHBoxLayout();

    QPushButton* backButton = new QPushButton("Back");
    connect(backButton, SIGNAL(clicked()), this, SLOT(goBackCallback()));


    QLabel* title = new QLabel("Current Users");
    QFont naxa, naxa2;
    QFontDatabase db;
    naxa = db.font("Nexa Light","Normal",64);
    naxa2= db.font("Nexa Light", "Normal", 18);
    title->setFont(naxa);
    title->setMaximumHeight(70);
    backButton->setFont(naxa2);

    topBar->addWidget(backButton, 0, Qt::AlignLeft);
    topBar->addSpacerItem(new QSpacerItem((title->width()/2), title->height(),QSizePolicy::Expanding));
    topBar->addWidget(title, 0, Qt::AlignHCenter);
    topBar->addSpacerItem(new QSpacerItem((title->width()/2), title->height(), QSizePolicy::Expanding));
    topBar->setAlignment(layout, Qt::AlignTop);
    layout->addLayout(topBar);

    userButtons = new QButtonGroup();
    connect(userButtons, SIGNAL(buttonClicked(int)), this, SLOT(openClickedUser(int)));
    for(int i=0; i < users.size(); i++){
        QPushButton *btn = new QPushButton(users.at(i)->username.toStdString().c_str());
        btn->setMinimumSize(250,50);
        btn->setMaximumSize(300,100);
        btn->setStyleSheet("background-color: rgb(200,200,200);");
        userButtons->addButton(btn);
        userButtons->setId(btn,i);
        layout->addWidget(btn, 0, Qt::AlignHCenter);
    }


    QPushButton* newUserButton = new QPushButton("Create New User");
    connect(newUserButton, SIGNAL(clicked()), this, SLOT(newUserCallback()));
    newUserButton->setMinimumSize(250,50);
    newUserButton->setMaximumSize(300,100);
    layout->addWidget(newUserButton, 0, Qt::AlignHCenter);

    this->setLayout(layout);
}

UserSelect::~UserSelect(){}

void UserSelect::goBackCallback()
{
    int index = pages->currentIndex();
    pages->removeWidget(this);
    pages->setCurrentIndex(index - 1);
}

void UserSelect::newUserCallback()
{
    //pages->removeWidget(this);
    int index = pages->addWidget(new NewUser(pages, parent));
    pages->setCurrentIndex(index);
}

void UserSelect::openClickedUser(int id)
{
    users[id]->goToDecksView(pages);
}
