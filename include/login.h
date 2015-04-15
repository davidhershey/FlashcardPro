#ifndef LOGIN_H
#define LOGIN_H

#include <QtWidgets>
#include <iostream>
#include <fstream>
#include <vector>
#include "user.h"

using namespace std;

class LogIn : public QFrame {
    Q_OBJECT
public:
    LogIn(QStackedWidget* pages_in);
    void initialSetup();
    void readCurrentUsers();
    void writeNewUserCallback();
    void addNewUser(User* user);
    QTextEdit* edit3;
    QString fileLoc;
    vector<QString> currentUsers;
    vector<User*> curUsers;

private:
    QStackedWidget* pages;
    QPushButton* nextButton;
    QGridLayout* layout;

public slots:
    void nextPage();
    void createNewUserCallback();
    void returnToLogInCallback();
    void userLoginCallback();
};

#endif // LOGIN_H
