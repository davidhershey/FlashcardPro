#include "user.h"
#include "decksview.h"
#include <fstream>
#include <iostream>


QDir *User::getDirectory() const
{
    return directory;
}


User::User(QString usrn_in,QString _dir)
{
    username = usrn_in;
    dir = _dir;
    //    dir += "/" + username + "_FCP";
    directory = new QDir(dir);
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
    int index = pages_in->addWidget(new DecksView(pages_in,this));
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

QStringList User::getDeckFiles()
{
    QStringList filters;
    filters << "*.dek";
    QStringList files = directory->entryList(filters);
    QStringList abs;
    for (QStringList::iterator it = files.begin();it != files.end(); ++it) {
        QString fileName = *it;
        abs <<  directory->absoluteFilePath(fileName);
    }
    return abs;
}
