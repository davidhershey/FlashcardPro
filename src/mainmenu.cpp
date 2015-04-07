#include "mainmenu.h"

mainmenu::mainmenu(QStackedWidget* pages_in)
    :QFrame()
{
    pages = pages_in;
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(new QLabel("This is the main menu"));

    study_button = new QPushButton(tr("Study Now!"));
    builder_button = new QPushButton(tr("Build card decks!"));
    stats_button = new QPushButton(tr("View your stats!"));
    connect_button = new QPushButton(tr("Connect with friends!"));

    layout->addWidget(study_button);
    layout->addWidget(builder_button);
    layout->addWidget(stats_button);
    layout->addWidget(connect_button);

    connect(study_button, SIGNAL(pressed()), this, SLOT(switch_study()));
    connect(builder_button, SIGNAL(pressed()), this, SLOT(switch_builder()));
    connect(stats_button, SIGNAL(pressed()), this, SLOT(switch_stats()));
    connect(connect_button, SIGNAL(pressed()), this, SLOT(switch_connect()));


    this->setLayout(layout);

}
mainmenu::~mainmenu(){

}

void mainmenu::switch_study(){
    pages->setCurrentIndex(3);
}

void mainmenu::switch_builder(){
    pages->setCurrentIndex(5);
}

void mainmenu::switch_connect(){
    pages->setCurrentIndex(4);
}

void mainmenu::switch_main(){
    pages->setCurrentIndex(1);
}

void mainmenu::switch_stats(){
    pages->setCurrentIndex(2);
}
