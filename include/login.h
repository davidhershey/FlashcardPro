#ifndef LOGIN_H
#define LOGIN_H

#include <QtWidgets>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class LogIn : public QFrame {
    Q_OBJECT
public:
    LogIn(QStackedWidget* pages_in);
    void initialSetup();
    void readCurrentUsers();
    QString fileLoc;
    QTextEdit *edit3;
    vector<QString> currentUsers;

private:
    QStackedWidget* pages;
    QPushButton* nextButton;
    QGridLayout* layout;

public slots:
    void nextPage();
    void createNewUserCallback();
    void writeNewUserCallback();
    void returnToLogInCallback();
    void userLoginCallback();
};

#endif // LOGIN_H
