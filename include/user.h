#ifndef USER
#define USER

#include <vector>
#include "deck.h"
#include <QString>
#include <QStackedWidget>
#include <fstream>
#include <iostream>
#include <QDir>
class User
{
private:
    std::vector<Deck*> decks;
    QString dir;
    QDir *directory;
    //ADD STATS INFO IN HERE
public:
    QString username;
    User(QString usrn_in, QString _dir);
    ~User();
    bool sameName(QString check);
    void goToDecksView(QStackedWidget* pages_in);
    void writeUserInfo(QString fileLoc);
    QStringList getDeckFiles();

    QDir *getDirectory() const;

public slots:
    void startSession();
};

#endif // USER

