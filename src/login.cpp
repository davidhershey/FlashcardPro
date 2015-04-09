#include "login.h"
#include <iostream>
#include <fstream>


using namespace std;

LogIn::LogIn(QStackedWidget* pages_in)
    :QFrame()
{
    pages = pages_in;
    QVBoxLayout* layout = new QVBoxLayout();

    QDir directory;
    QString txtFile;
    txtFile = directory.currentPath();
    int cutpoint = 0;
    for(int i = txtFile.size() - 1; i > 0; i--){
        if(txtFile.at(i) == '/'){
            cutpoint = i;
            i = 0;
        }
    }
    txtFile = txtFile.left(cutpoint);
    txtFile.append("/FlashcardPro/flashcard.png");



    QPixmap newPixmap(txtFile);

    if (newPixmap.isNull()){
      QMessageBox msgBox;
      msgBox.critical(0,"Error", "Cannot open pixmap");
      msgBox.setFixedSize(500,200);
    }
    else{
        QLabel *newLabel = new QLabel();
        newLabel->setPixmap(newPixmap.scaled(500,500,Qt::KeepAspectRatio));
        newLabel->setMaximumSize(500,500);
        newLabel->setMinimumSize(500,500);
        layout->addWidget(newLabel);
    }

    QLabel *lab = new QLabel("The most comprehensive flashcard app on the market. Two thumbs up!");
    layout->addWidget(lab);

    /*
    QLabel *label = new QLabel("Existing Users:");
    label->setMaximumHeight(15);
    QPushButton *lauren = new QPushButton("Lauren");
    lauren->setMinimumHeight(50);
    lauren->setMaximumWidth(150);
    QPushButton *david = new QPushButton("David");
    david->setMinimumHeight(50);
    david->setMaximumWidth(150);
    QPushButton *jared = new QPushButton("Jared");
    jared->setMinimumHeight(50);
    jared->setMaximumWidth(150);
    QPushButton *sam = new QPushButton("Sam");
    sam->setMinimumHeight(50);
    sam->setMaximumWidth(150);
    QLabel *newUser = new QLabel("Create New User:");
    newUser->setMaximumHeight(15);
    QPushButton *createNewUser = new QPushButton("Create New User");
    createNewUser->setMaximumSize(150,50);
    createNewUser->setMinimumSize(150,50);
    layout->addWidget(label);
    layout->addWidget(lauren);
    layout->addWidget(david);
    layout->addWidget(jared);
    layout->addWidget(sam);
    layout->addWidget(newUser);
    layout->addWidget(createNewUser);
    connect(createNewUser, SIGNAL(clicked()),this,SLOT(createNewUserCallback()));
*/
    nextButton = new QPushButton("Log In");
    QPushButton *cr = new QPushButton("Sign Up");
    connect(nextButton, SIGNAL(clicked()), this, SLOT(nextPage()));
    layout->addWidget(nextButton);
    layout->addWidget(cr);

    setLayout(layout);



}

LogIn::~LogIn()
{

}

void LogIn::nextPage()
{
    //LOGIC FOR LOGGING INTO DATABASE HERE
    //int current = pages->currentIndex();
    pages->setCurrentIndex(1);
}

void LogIn::createNewUserCallback(){
    qDebug() << "createNewUser";
    QDir directory;
    QString txtFile;
    txtFile = directory.currentPath();
    int cutpoint = 0;
    for(int i = txtFile.size() - 1; i > 0; i--){
        if(txtFile.at(i) == '/'){
            cutpoint = i;
            i = 0;
        }
    }
    txtFile = txtFile.left(cutpoint);
    txtFile.append("/FlashcardPro/flashcard.png");

    //txtFile.append("/FlashcardPro/login_names.txt");

    //ofstream myFile;
    //myFile.open(txtFile.toStdString().c_str(), std::ios::app);
    //myFile << "Writing to this file 21313232\n";
    //myFile.close();
}
