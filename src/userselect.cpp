#include "userselect.h"
#include "newuser.h"

#include <vector>
#include <QVBoxLayout>
#include <QtWidgets>
UserSelect::UserSelect(QStackedWidget *pages_in, std::vector<User*> users_in)
{
    QFrame();
    pages = pages_in;
    users = users_in;

    QVBoxLayout* layout = new QVBoxLayout();
    QLabel* title = new QLabel("Current Users");
    QFont naxa;
    QFontDatabase db;
    naxa = db.font("Nexa Light","Normal",64);
    title->setFont(naxa);
    title->setMaximumHeight(50);
    layout->addWidget(title, 0, Qt::AlignHCenter);

    userButtons = new QButtonGroup();
    connect(userButtons, SIGNAL(buttonClicked(int)), this, SLOT(openClickedUser(int)));
    for(int i=0; i < users.size(); i++){
        QPushButton *btn = new QPushButton(users.at(i)->username.toStdString().c_str());
        btn->setMinimumHeight(50);
        btn->setMaximumWidth(150);
        userButtons->addButton(btn);
        layout->addWidget(btn);
    }

    QHBoxLayout* bottomLayout = new QHBoxLayout();
    QPushButton* newUserButton = new QPushButton("Create New User");
    connect(newUserButton, SIGNAL(clicked()), this, SLOT(newUserCallback()));
    QPushButton* backButton = new QPushButton("Back");
    connect(backButton, SIGNAL(clicked()), this, SLOT(goBackCallback()));
    bottomLayout->addWidget(backButton, 0, Qt::AlignLeft);
    bottomLayout->addWidget(newUserButton, 0, Qt::AlignHCenter);

    layout->addLayout(bottomLayout);

    this->setLayout(layout);
}

UserSelect::~UserSelect(){}

void UserSelect::goBackCallback()
{
    pages->removeWidget(this);
    //pages->setCurrentIndex(pages->currentIndex() - 1);
}

void UserSelect::newUserCallback()
{
    qDebug() << "Still needs to be implemented!";
}

void UserSelect::openClickedUser(int id)
{
    users[id]->goToDecksView(pages);
}
