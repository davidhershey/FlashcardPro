#include "newuser.h"
#include <QtWidgets>

NewUser::NewUser(QStackedWidget* pages_in, LogIn* parent_in)
{
    QFrame();
    pages = pages_in;
    parent = parent_in;
    qDebug() << "making new user ";
    QLabel* title = new QLabel("Create New User");
    QFont naxa;
    QFontDatabase db;
    naxa = db.font("Nexa Light","Normal",64);
    title->setFont(naxa);

    QFormLayout* form = new QFormLayout();
    username = new QTextEdit();
    form->addRow(tr("Name:"), username);

    QPushButton *submitButton = new QPushButton("Select a Save Directory");
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

    QString pathName = QFileDialog::getExistingDirectory(this,tr("Select a Save Directory"), QDir::homePath());
//    QDir dir(pathName);
    User* newUser = new User(username->toPlainText(),
                             pathName
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
    if(username->toPlainText().isEmpty()) return true;
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
    return false;
}

void NewUser::showError(QString text)
{
    QMessageBox msgBox;
    msgBox.critical(0,"Error",text);
    msgBox.setFixedSize(500,200);
    return;
}
