#include "user.h"
#include "decksview.h"
#include <fstream>
#include <iostream>

User::User(QString usrn_in, QString pw_in, QString fn_in, QString ln_in, std::vector<Deck*> decks_in)
{
    username = usrn_in;
    password = pw_in;
    first_name = fn_in;
    last_name = ln_in;
    decks= decks_in;
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
    myFile << password.toStdString().c_str() << " ";
    myFile << first_name.toStdString().c_str() << " ";
    myFile << last_name.toStdString().c_str() << "\n";
    myFile.close();
}
