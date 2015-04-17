#include "newuser.h"
#include <QtWidgets>

NewUser::NewUser(QStackedWidget* pages_in, LogIn* parent_in, UserSelect* select_parent)
{
    QFrame();
    pages = pages_in;
    parent = parent_in;
    select = select_parent;
    qDebug() << "making new user ";
    QLabel* title = new QLabel("Create New User");
    QFont naxa;
    QFontDatabase db;
    naxa = db.font("Nexa Light","Normal",64);
    title->setFont(naxa);

    QFont naxa2= db.font("Nexa Light", "Normal", 18);

    QFormLayout* form = new QFormLayout();
    username = new QTextEdit();

    QLabel *name = new QLabel(tr("Name:"));
    name->setFont(naxa2);
    form->addRow(name, username);
    username->setMaximumHeight(40);
    username->setFont(naxa2);
    QLabel *select = new QLabel(tr("Select a Save Directory:"));
    select->setFont(naxa2);
    QPushButton *submitButton = new QPushButton("Browse");
    submitButton->setFont(naxa2);
    QPushButton *cancelButton = new QPushButton("Cancel");
    connect(submitButton,SIGNAL(clicked()),this,SLOT(submit()));
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(cancel()));
    form->addRow(select, submitButton);

    submitButton->setFont(naxa2);
    cancelButton->setFont(naxa2);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(title, 0, Qt::AlignHCenter);
    layout->addSpacerItem(new QSpacerItem(this->width(), this->height()/4));
    layout->addLayout(form);
    layout->addSpacerItem(new QSpacerItem(this->width(), this->height()/4));
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

    for(int i=0; i < parent->curUsers.size(); i++){
        if(parent->curUsers.at(i)->username == validName()){
            showError("Please choose a unique name");
            return;
        }
    }

    QString pathName = QFileDialog::getExistingDirectory(this,tr("Select a Save Directory"), QDir::homePath());
//    QDir dir(pathName);
    if(pathName == "") return;
    User* newUser = new User(validName(),
                             pathName
                             );

    parent->addNewUser(newUser);
    if(select != NULL) select->updateUserSelect();
    return;
}

void NewUser::cancel()
{
    int index = pages->currentIndex();
    pages->removeWidget(this);
    pages->setCurrentIndex(index - 1);
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

QString NewUser::validName()
{
    return username->toPlainText().replace(" ","_");
}

void NewUser::showError(QString text)
{
    QMessageBox msgBox;
    msgBox.critical(0,"Error",text);
    msgBox.setFixedSize(500,200);
    return;
}
