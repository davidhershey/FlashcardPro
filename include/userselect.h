#ifndef USERSELECT
#define USERSELECT

#include <QStackedWidget>
#include "user.h"
#include <QButtonGroup>

class UserSelect : public QFrame
{
    Q_OBJECT
public:
    UserSelect(QStackedWidget* pages_in, std::vector<User*> users_in);
    ~UserSelect();

    QStackedWidget* pages;
    std::vector<User*> users;
    QButtonGroup* userButtons;

public slots:
    void goBackCallback();
    void openClickedUser(int);
    void newUserCallback();

private:

};

#endif // USERSELECT

