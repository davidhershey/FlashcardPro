#ifndef LOGIN_H
#define LOGIN_H

#include <QtWidgets>
#include <iostream>
#include <fstream>

class LogIn : public QFrame
{
    Q_OBJECT
public:
    LogIn(QStackedWidget* pages_in);
    ~LogIn();
    void initialSetup();
private:
    QStackedWidget* pages;
    QPushButton* nextButton;
    QVBoxLayout* layout;

public slots:
    void nextPage();
    void createNewUserCallback();
    void returnToLogInCallback();
};

#endif // LOGIN_H
