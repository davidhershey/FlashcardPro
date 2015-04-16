#include "user.h"
#include "decksview.h"
#include <fstream>
#include <iostream>

User::User(QString usrn_in,QString _dir)
{
    username = usrn_in;
    dir = _dir;
//    dir += "/" + username + "_FCP";
    QDir *directory = new QDir(dir);
    if(directory->exists(username + "_FCP")){}
    else directory->mkdir(username + "_FCP");
    directory->cd(username + "_FCP");



}

User::~User(){}

bool User::sameName(QString check)
{
    if(check == username) return true;
    return false;
}

void User::goToDecksView(QStackedWidget* pages_in)
{
    int index = pages_in->addWidget(new DecksView(pages_in));
    pages_in->setCurrentIndex(index);
}

void User::writeUserInfo(QString fileLoc)
{
    std::ofstream myFile;
    qDebug() << fileLoc;
    myFile.open(fileLoc.toStdString().c_str(), std::ios::app);
    qDebug() << "Got here";
    myFile << username.toStdString().c_str() << " ";
    myFile << dir.toStdString().c_str() << "\n";
    myFile.close();
}
