#include "login.h"
#include <direct.h>
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
    initialSetup();
    readCurrentUsers();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// Next Page Call /////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void LogIn::nextPage()
{

    if(currentUsers.empty()){
        createNewUserCallback();
        return;
    }

    for(int i=layout->count()-1; i >= 0; i--){
        QLayoutItem *item = layout->takeAt(i);
        layout->removeItem(item);
        item->widget()->hide();
    }

    QLabel *label = new QLabel("Existing Users:");
    label->setMaximumHeight(15);
    layout->addWidget(label,0,0);

    for(int i=0; i < currentUsers.size(); i++){
        QPushButton *btn = new QPushButton(currentUsers.at(i).toStdString().c_str());
        btn->setMinimumHeight(50);
        btn->setMaximumWidth(150);
        layout->addWidget(btn,i+1,0);
        connect(btn,SIGNAL(clicked()),this,SLOT(userLoginCallback()));
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////// Goes From Login to Create New Users Page ///////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void LogIn::createNewUserCallback(){

    for(int i=layout->count()-1; i >= 0; i--){
        QLayoutItem *item = layout->takeAt(i);
        layout->removeItem(item);
        item->widget()->hide();
    }

    QLabel *label1 = new QLabel("Create new user:");
    QLabel *label2 = new QLabel("First Name:");
    QLabel *label3 = new QLabel("Last Name:");
    QLabel *label4 = new QLabel("Username:");
    QLabel *label5 = new QLabel("Password:");
    QLabel *label6 = new QLabel("Re-enter Password:");
    QTextEdit *edit1 = new QTextEdit();
    QTextEdit *edit2 = new QTextEdit();
    edit3 = new QTextEdit();
    QTextEdit *edit4 = new QTextEdit();
    QTextEdit *edit5 = new QTextEdit();
    QPushButton *createNewUserBtn = new QPushButton("Submit");
    QPushButton *returnBtn = new QPushButton("Cancel");

    layout->addWidget(label1,0,0);
    layout->addWidget(label2,1,0);
    layout->addWidget(edit1,1,1);
    layout->addWidget(label3,2,0);
    layout->addWidget(edit2,2,1);
    layout->addWidget(label4,3,0);
    layout->addWidget(edit3,3,1);
    layout->addWidget(label5,4,0);
    layout->addWidget(edit4,4,1);
    layout->addWidget(label6,5,0);
    layout->addWidget(edit5,5,1);
    layout->addWidget(createNewUserBtn,6,0);
    layout->addWidget(returnBtn,7,0);

    connect(returnBtn,SIGNAL(clicked()),this,SLOT(returnToLogInCallback()));
    connect(createNewUserBtn,SIGNAL(clicked()),this,SLOT(writeNewUserCallback()));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Sets Up Initial Login Page /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void LogIn::initialSetup(){

    QDir directory;
    fileLoc = directory.currentPath();
    int cutpoint = 0;
    for(int i = fileLoc.size() - 1; i > 0; i--){
        if(fileLoc.at(i) == '/'){
            cutpoint = i;
            i = 0;
        }
    }
    fileLoc = fileLoc.left(cutpoint);
    /*
    QString picLoc;
    picLoc = fileLoc;
    picLoc.append(":/flashcard.png");*/

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

    QLabel *label1 = new QLabel("The most comprehensive flashcard app on the market. Two thumbs up!");


    nextButton = new QPushButton("Log In");
    QPushButton *cr = new QPushButton("Sign Up");


    layout->addWidget(label1,1,0);
    layout->addWidget(nextButton,2,0);
    layout->addWidget(cr,3,0);
    setLayout(layout);

    connect(nextButton, SIGNAL(clicked()), this, SLOT(nextPage()));
    connect(cr, SIGNAL(clicked()),this,SLOT(createNewUserCallback()));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Goes from Create User to Login Page ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void LogIn::returnToLogInCallback(){

    for(int i=layout->count()-1; i >= 0; i--){
        QLayoutItem *item = layout->takeAt(i);
        layout->removeItem(item);
        item->widget()->hide();
    }
    initialSetup();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Writes New User to Text File ///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void LogIn::writeNewUserCallback(){
    QString txtFile;
    txtFile = fileLoc;
    txtFile.append("/FlashcardPro/login_names.txt");

    if(edit3->toPlainText() == ""){
        QMessageBox msgBox;
        msgBox.critical(0,"Error", "Please enter a username");
        msgBox.setFixedSize(500,200);
        return;
    }

    for(int i=0; i < currentUsers.size(); i++){
        if(edit3->toPlainText() == currentUsers.at(i)){
            QMessageBox msgBox;
            msgBox.critical(0,"Error", "Username Already exists. Please choose a new username");
            msgBox.setFixedSize(500,200);
            return;
        }
    }

    currentUsers.push_back(edit3->toPlainText());

    ofstream myFile;
    myFile.open(txtFile.toStdString().c_str(), std::ios::app);
    myFile << edit3->toPlainText().toStdString().c_str();
    myFile << "\n";
    myFile.close();

    returnToLogInCallback();

    QString folder;
    folder = fileLoc + "/" + edit3->toPlainText() + "_Decks";
    mkdir(folder.toStdString().c_str());


    //LOGIC FOR LOGGING INTO DATABASE HERE
    //int current = pages->currentIndex();
    pages->setCurrentIndex(1);

    QMessageBox msgBox;
    msgBox.setText("Successfully Created User!");
    msgBox.setFixedSize(500,200);
    msgBox.exec();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Reads in Users from Text File //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void LogIn::readCurrentUsers(){
    QString txtFile = fileLoc;
    txtFile.append("/FlashcardPro/login_names.txt");

    ifstream file(txtFile.toStdString().c_str());
    string temp;

    while(getline(file,temp)){
        QString push = QString::fromStdString(temp);
        if(push != "") currentUsers.push_back(push);
    }
}


void LogIn::userLoginCallback(){
    returnToLogInCallback();
    pages->setCurrentIndex(1);
}
