#include "login.h"
#include "newuser.h"
#include "userselect.h"
//#include <direct.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// LogIn Constructor //////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
LogIn::LogIn(QStackedWidget* pages_in)
    :QFrame(){
    pages = pages_in;
    layout = new QGridLayout();
    QDir directory;
    fileLoc = directory.currentPath();
    readCurrentUsers();
    initialSetup();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// Next Page Call /////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void LogIn::nextPage()
{

    if(curUsers.empty()){
        int index = pages->addWidget(new NewUser(pages, this));
        pages->setCurrentIndex(index);
        return;
    }

    int index = pages->addWidget(new UserSelect(pages, curUsers, this));
    pages->setCurrentIndex(index);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////// Goes From Login to Create New Users Page ///////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void LogIn::createNewUserCallback(){

    int index = pages->addWidget(new NewUser(pages, this));
    pages->setCurrentIndex(index);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Sets Up Initial Login Page /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void LogIn::initialSetup(){

    QPixmap newPixmap(":/flashcard.png");

    if (newPixmap.isNull()){
      QMessageBox msgBox;
      msgBox.critical(0,"Error", "Cannot open pixmap");
      msgBox.setFixedSize(500,200);
    }
    else{
        QLabel *newLabel = new QLabel();
        newLabel->setPixmap(newPixmap.scaled(500,500,Qt::KeepAspectRatio));
        newLabel->setMaximumSize(500,500);
        newLabel->setMinimumSize(500,500);
        layout->addWidget(newLabel,0,0);
    }

    QLabel *title_info = new QLabel("The most comprehensive flashcard app on the market. Two thumbs up!");
    QFont naxa;
    QFontDatabase db;
    naxa = db.font("Nexa Light","Normal",18);
    title_info->setFont(naxa);

    QPushButton* startButton = new QPushButton("Start");
    //QPushButton *cr = new QPushButton("Sign Up");


    layout->addWidget(title_info,1,0);
    layout->addWidget(startButton,2,0);
    //layout->addWidget(cr,3,0);
    setLayout(layout);

    connect(startButton, SIGNAL(clicked()), this, SLOT(nextPage()));
    //connect(cr, SIGNAL(clicked()),this,SLOT(createNewUserCallback()));
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Reads in Users from Text File //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void LogIn::readCurrentUsers(){

    QString txtFile = fileLoc;
    txtFile.append("/users.txt");

    qDebug() << txtFile;

    ifstream file(txtFile.toStdString().c_str());
    string temp;

    if(!file.is_open())
    {
        //create new
        std::ofstream myFile;
        myFile.open(txtFile.toStdString().c_str(), std::ios::app);
        qDebug() << "New User!";
        return;
    }

    while(getline(file,temp)){

        QString push = QString::fromStdString(temp);
        QStringList list = push.split(" ");
        if(list.size() != 4)
        {
            qDebug() << "issue in login readCurrentUsers";
            return;
        }
        qDebug() << "added user " << list[0];
        curUsers.push_back(new User(list[0], list[1], list[2], list[3]));
    }
}


void LogIn::addNewUser(User* user)
{
    curUsers.push_back(user);

    //write to login_names.txt
    user->writeUserInfo(fileLoc + "/users.txt");

    //Create directory to contain decks
    QString folder;
    folder = fileLoc + "/" + user->username + "_Decks";
    QDir dir(folder);
    //mkdir(folder.toStdString().c_str());
    if(!dir.exists()) dir.mkdir(".");
    else qDebug() << "Folder already exists!";

    //Go to choose user
    pages->removeWidget(pages->currentWidget());
    //pages->setCurrentIndex(pages->currentIndex()-1);

    //Display success
    QMessageBox msgBox;
    msgBox.setText("Successfully Created User!");
    msgBox.setFixedSize(500,200);
    msgBox.exec();
}
