#ifndef LOGIN_H
#define LOGIN_H

#include <QtWidgets>

class LogIn : public QFrame
{
    Q_OBJECT
public:
    LogIn(QStackedWidget* pages_in);
    ~LogIn();
private:
    QStackedWidget* pages;
    QPushButton* nextButton;

public slots:
    void nextPage();
};

//test comment from sam

#endif // LOGIN_H
