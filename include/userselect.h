#ifndef USERSELECT
#define USERSELECT

#include <QStackedWidget>
#include "user.h"
#include <QButtonGroup>
#include "login.h"

class UserSelect : public QFrame
{
    Q_OBJECT
public:
    UserSelect(QStackedWidget* pages_in, std::vector<User*> users_in, LogIn* parent_in);
    ~UserSelect();

    QStackedWidget* pages;
    std::vector<User*> users;
    QButtonGroup* userButtons;
    LogIn* parent;

public slots:
    void goBackCallback();
    void openClickedUser(int);
    void newUserCallback();

private:

};

#endif // USERSELECT

