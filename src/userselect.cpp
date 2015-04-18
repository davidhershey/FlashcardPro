#include "userselect.h"
#include "newuser.h"

#include <vector>
#include <QVBoxLayout>
#include <QtWidgets>
#include "newuser.h"
#include "deletebutton.h"
#include <fstream>
#include <iostream>

UserSelect::UserSelect(QStackedWidget *pages_in, std::vector<User *> *users_in, LogIn* parent_in)
{
    QFrame();
    pages = pages_in;
    users = users_in;
    parent = parent_in;

    QGridLayout* layout = new QGridLayout();
    QHBoxLayout* topBar = new QHBoxLayout();

    QPushButton* backButton = new QPushButton("Back");
    connect(backButton, SIGNAL(clicked()), this, SLOT(goBackCallback()));


    QLabel* title = new QLabel("Current Users");
    QFont naxa, naxa2, naxa3;
    QFontDatabase db;
    naxa = db.font("Nexa Light","Normal", 64);
    naxa2= db.font("Nexa Light", "Normal", 18);
    naxa3= db.font("Nexa Light", "Normal", 24);
    title->setFont(naxa);
    title->setMaximumHeight(70);
    backButton->setFont(naxa2);
    backButton->setMinimumWidth(100);

    topBar->addWidget(backButton, 0, Qt::AlignLeft);
    topBar->addSpacerItem(new QSpacerItem((title->width()/2), title->height(),QSizePolicy::Expanding));
    topBar->addWidget(title, 0, Qt::AlignHCenter);
    topBar->addSpacerItem(new QSpacerItem((title->width()/2), title->height(), QSizePolicy::Expanding));
    topBar->setAlignment(layout, Qt::AlignTop);
    //layout->addLayout(topBar);

    QWidget *userList = new QWidget();
    userList->setLayout(layout);

    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(userList);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QVBoxLayout *lay = new QVBoxLayout();
    lay->addSpacing(10);
    lay->addLayout(topBar);
    lay->addSpacing(40);
    lay->addWidget(scrollArea, 0, Qt::AlignHCenter);

    this->setLayout(lay);
    this->setStyleSheet("QFrame { background-color: rgb(191, 197, 255); }");
    //scrollArea->setStyleSheet("background-color:rgb(191,197,255);");


    userButtons = new QButtonGroup();
    connect(userButtons, SIGNAL(buttonClicked(int)), this, SLOT(openClickedUser(int)));
    for(int i=0; i < users->size(); i++){
        QPushButton *btn = new QPushButton(users->at(i)->username.toStdString().c_str());
        btn->setMinimumSize(250,75);
        btn->setMaximumSize(300,100);
        btn->setStyleSheet("background-color: rgb(250,236,191);");
        btn->setFont(naxa3);
        userButtons->addButton(btn);
        userButtons->setId(btn,i);
        layout->addWidget(btn, i, 0, Qt::AlignRight);

        deleteButton *removeUser = new deleteButton;
        removeUser->setToolTip("Remove this user");
        removeUser->setFixedSize(30,30);
        removeUser->user_number = i;

        QPixmap pm(":/red_x.png");
        pm = pm.scaled(30, 30, Qt::KeepAspectRatio);
        QIcon ic(pm);
        removeUser->setIcon(ic);
        layout->addWidget(removeUser, i, 1, Qt::AlignLeft);
        connect(removeUser, SIGNAL(clicked()), this, SLOT(removeUser()));
        QWidget *spacer = new QWidget();
        spacer->setMinimumWidth(15);
        layout->addWidget(spacer, i,2);

    }


    QPushButton* newUserButton = new QPushButton("Create New User");
    connect(newUserButton, SIGNAL(clicked()), this, SLOT(newUserCallback()));
    newUserButton->setMinimumSize(250,75);
    newUserButton->setMaximumSize(300,100);
    newUserButton->setFont(naxa3);
    newUserButton->setStyleSheet("background-color: rgb(240,240,200);");
    lay->addWidget(newUserButton, 0, Qt::AlignHCenter);
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
    int index = pages->addWidget(new NewUser(pages, parent, this));
    pages->setCurrentIndex(index);
}

void UserSelect::openClickedUser(int id)
{
    users->at(id)->goToDecksView(pages);
}

void UserSelect::updateUserSelect()
{
    UserSelect* refreshed = new UserSelect(this->pages, users, this->parent);
    pages->removeWidget(this);
    int index = pages->addWidget(refreshed);
    pages->setCurrentIndex(index);
}

void UserSelect::removeUser(){
    deleteButton* button = dynamic_cast<deleteButton*>(sender());

    confirm = new QDialog();
    QVBoxLayout* layout = new QVBoxLayout();
    QLabel *label = new QLabel(tr("Are you sure you want to delete this user and all his/her decks?"));
    deleteButton* yes = new deleteButton;
    yes->setText("Yes");

    yes->user_number = button->user_number;

    QPushButton* no = new QPushButton("No");

    QFont naxa;
    QFontDatabase db;
    naxa = db.font("Naxa Light", "Normal", 18);

    label->setFont(naxa);
    yes->setFont(naxa);
    no->setFont(naxa);


    QHBoxLayout* layout2 = new QHBoxLayout();
    layout->addWidget(label);
    layout->addLayout(layout2);
    layout2->addWidget(yes);
    layout2->addWidget(no);
    connect(yes, SIGNAL(clicked()), this, SLOT(yes()));
    connect(no, SIGNAL(clicked()), this, SLOT(no()));
    confirm->setLayout(layout);
    confirm->exec();
    return;

}

void UserSelect::yes(){
    deleteButton* button = dynamic_cast<deleteButton*>(sender());
    int id = button->user_number;
    users->clear();

    QDir directory;
    QString txtFile = directory.currentPath();
    txtFile.append("/users.txt");

    ifstream file(txtFile.toStdString().c_str());

    string temp;

    int i=0;
    vector <QStringList> myList;

    while(getline(file,temp)){
      if (i != id){
        QString push = QString::fromStdString(temp);
        QStringList list = push.split(" ");
        myList.push_back(list);
        users->push_back(new User(list[0], list[1]));
        if(list.size() != 2)
        {
            //qDebug() << "issue in login readCurrentUsers";
            return;
        }
      }
        i++;
    }
    file.close();

    std::ofstream myFile2(txtFile.toStdString().c_str());
    //qDebug() << "Got here";

    for (int j=0; j < myList.size(); j++){
       myFile2 << myList[j].at(0).toStdString() << " ";
       myFile2 << myList[j].at(1).toStdString() << "\n";
    }

    myFile2.close();




    updateUserSelect();
    confirm->close();
}

void UserSelect::no(){
    confirm->close();
}
