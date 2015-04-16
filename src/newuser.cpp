#include "newuser.h"
#include <QtWidgets>

NewUser::NewUser(QStackedWidget* pages_in, LogIn* parent_in)
{
    QFrame();
    pages = pages_in;
    parent = parent_in;

    QLabel* title = new QLabel("Create New User");
    QFont naxa;
    QFontDatabase db;
    naxa = db.font("Nexa Light","Normal",64);
    title->setFont(naxa);

    QFormLayout* form = new QFormLayout();
    first_name = new QTextEdit();
    last_name = new QTextEdit();
    username = new QTextEdit();
    password = new QTextEdit();
    password_check = new QTextEdit();

    form->addRow(tr("First Name:"), first_name);
    form->addRow(tr("Last Name:"), last_name);
    form->addRow(tr("Username:"), username);
    form->addRow(tr("Password:"), password);
    form->addRow(tr("Re-enter Password:"), password_check);

    QPushButton *submitButton = new QPushButton("Submit");
    QPushButton *cancelButton = new QPushButton("Cancel");
    connect(submitButton,SIGNAL(clicked()),this,SLOT(submit()));
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(cancel()));

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(title, 0, Qt::AlignHCenter);
    layout->addLayout(form);
    layout->addWidget(submitButton, 0, Qt::AlignHCenter);
    layout->addWidget(cancelButton, 0, Qt::AlignHCenter);

    this->setLayout(layout);
}
NewUser::~NewUser()
{

}

void NewUser::submit()
{
    if(anyEmpty())
    {
        showError("Please fill in all fields.");
        return;
    }
    if(invalidUsername())
    {
        showError("That username already exists. Please enter another username.");
        return;
    }
    if(passwordMismatch())
    {
        showError("Your passwords do not match.");
        return;
    }

    User* newUser = new User(username->toPlainText(),
                             password->toPlainText(),
                             first_name->toPlainText(),
                             last_name->toPlainText()
                             );

    parent->addNewUser(newUser);
    return;
}

void NewUser::cancel()
{
    pages->removeWidget(this);
    //pages->setCurrentIndex(pages->currentIndex() - 1);
}

bool NewUser::anyEmpty()
{
    if(first_name->toPlainText().isEmpty()) return true;
    if(last_name->toPlainText().isEmpty()) return true;
    if(username->toPlainText().isEmpty()) return true;
    if(password->toPlainText().isEmpty()) return true;
    if(password_check->toPlainText().isEmpty()) return true;
    return false;
}

bool NewUser::invalidUsername()
{
    for(int i=0; i < parent->curUsers.size(); ++i)
    {
        if(parent->curUsers[i]->sameName(username->toPlainText()))
            return true;
    }
    return false;
}

bool NewUser::passwordMismatch()
{
    if(password->toPlainText() != password_check->toPlainText())
        return true;
    return false;
}

void NewUser::showError(QString text)
{
    QMessageBox msgBox;
    msgBox.critical(0,"Error",text);
    msgBox.setFixedSize(500,200);
    return;
}
