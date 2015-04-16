#ifndef NEWUSER
#define NEWUSER

#include <QStackedWidget>
#include "login.h"
#include "userselect.h"

class NewUser : public QFrame
{
    Q_OBJECT

public:
    NewUser(QStackedWidget* pages_in, LogIn* parent_in, UserSelect* select_parent = NULL);
    ~NewUser();

    QStackedWidget* pages;
    LogIn* parent;
    UserSelect* select;

    QTextEdit *username;

    bool anyEmpty();
    bool invalidUsername();
    bool passwordMismatch();
    QString validName();
    void showError(QString text);
    QString pathName;
    QTextEdit* direct;

public slots:
    void submit();
    void cancel();
    void browse();
};

#endif // NEWUSER

