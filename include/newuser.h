#ifndef NEWUSER
#define NEWUSER

#include <QStackedWidget>
#include "login.h"

class NewUser : public QFrame
{
    Q_OBJECT

public:
    NewUser(QStackedWidget* pages_in, LogIn* parent_in);
    ~NewUser();

    QStackedWidget* pages;
    LogIn* parent;

    QTextEdit *username;

    bool anyEmpty();
    bool invalidUsername();
    bool passwordMismatch();
    QString validName();
    void showError(QString text);

public slots:
    void submit();
    void cancel();
};

#endif // NEWUSER

