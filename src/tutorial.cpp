#include "tutorial.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QFontDatabase>
#include "decksview.h"
#include "user.h"
#include "flashcard.h"
#include <vector>
#include "studyarea.h"

Tutorial::Tutorial()
    :QDialog()
{
    QLabel* title = new QLabel("Tutorial");
    QFont naxa;
    QFontDatabase db;
    naxa = db.font("Nexa Light","Normal",64);
    title->setFont(naxa);

    next = new QPushButton("Next");
    prev = new QPushButton("Previous");
    connect(next, SIGNAL(clicked()), this, SLOT(nextCallback()));
    connect(prev, SIGNAL(clicked()), this, SLOT(prevCallback()));
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(prev);
    layout->addWidget(next);

    std::vector<Flashcard*> mocFlashcards = std::vector<Flashcard*>();
    mocFlashcards.push_back(new Flashcard("You can flip the flashcard by clicking anywhere on the flashcard."
                                          , "If you got the correct answer, click the green check. If you got the wrong answer, click the red x.", 0));

    mocFlashcards.push_back(new Flashcard("This will update your card score and take you to the next card. Flip me for more tips."
                                          , "Instead of clicking the green check, you can also press the left keyboard key. Likewise, you can press the right keyboard key instead of clicking the red x. Try it now.", 0));
    mocFlashcards.push_back(new Flashcard("FlashcardsPro uses an algorithm to help you learn the best by showing you cards that you struggle with more often."
                                          , "When you are finished, the back button brings you to the deck menu. Click the next button to proceed..", 0));
    mocDeck = new Deck(mocFlashcards, "Tutorial Deck", NULL);


    tutPages = new QStackedWidget();
    tutPages->addWidget(createUserTutPage());
    tutPages->addWidget(createDecksViewTutPage());
    tutPages->addWidget(createDeckMenuTutPage());
    tutPages->addWidget(createStudyAreaTutPage());
    tutPages->addWidget(createDonePage());


    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(title, 0, Qt::AlignHCenter);
    mainLayout->addWidget(tutPages);
    mainLayout->addLayout(layout);
    setLayout(mainLayout);

}

Tutorial::~Tutorial()
{

}

void Tutorial::prevCallback()
{
    next->setText("Next");
    if(tutPages->currentIndex() == 0) return;
    tutPages->setCurrentIndex(tutPages->currentIndex()-1);
}

void Tutorial::nextCallback()
{
    if(tutPages->currentIndex() == tutPages->count()-2) next->setText("Finish");
    if(tutPages->currentIndex()+1 == tutPages->count()) this->close();
    tutPages->setCurrentIndex(tutPages->currentIndex()+1);
}

QFrame* Tutorial::createUserTutPage()
{
    QFont naxa;
    QFont naxa_b;
    QFontDatabase db;
    naxa = db.font("Nexa Light","Normal",18);
    naxa_b = db.font("Nexa Light","Normal",18);
    naxa_b.setBold(true);

    QFrame* frame = new QFrame(this);
    frame->setMaximumSize(700,500);
    QLabel* line1 = new QLabel("You've just successfully created a new user!");
    QLabel* line2 = new QLabel("If you are new to FlashcardsPro, "
                               "we suggest that you continue through this quick tutorial.");
    QLabel* line3 = new QLabel("You can exit the tutorial at any time by closing this window.");
    QLabel* line4 = new QLabel("Click the next button to proceed...");
    line1->setFont(naxa);
    line2->setFont(naxa);
    line3->setFont(naxa);
    line4->setFont(naxa_b);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(line1, 0, Qt::AlignHCenter);
    layout->addWidget(line2, 0, Qt::AlignHCenter);
    layout->addWidget(line3, 0, Qt::AlignHCenter);
    layout->addWidget(line4, 0, Qt::AlignHCenter);
    frame->setLayout(layout);
    return frame;
}

QFrame* Tutorial::createDecksViewTutPage()
{
    QFont naxa;
    QFont naxa_b;
    QFontDatabase db;
    naxa = db.font("Nexa Light","Normal",18);
    naxa_b = db.font("Nexa Light","Normal",18);
    naxa_b.setBold(true);

    QFrame* frame = new QFrame(this);
    frame->setMaximumSize(700,500);
    QLabel* line1 = new QLabel("Selecting your username will bring you to all of your decks. There are currently no decks created.");
    QLabel* line2 = new QLabel("Clicking on the plus sign will let you load a .dek file or create a new deck with our deck builder.");
    QLabel* line3 = new QLabel("Try clicking the plus sign and then click next to proceed...");
    line1->setFont(naxa);
    line2->setFont(naxa);
    line3->setFont(naxa);

    DecksView* mocDecksView = new DecksView(NULL, NULL);
    mocDecksView->setStyleSheet("background-color: rgb(191, 197, 255);");

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(line1, 0, Qt::AlignHCenter);
    layout->addWidget(mocDecksView, 0, Qt::AlignHCenter);
    layout->addWidget(line2, 0, Qt::AlignHCenter);
    layout->addWidget(line3, 0, Qt::AlignHCenter);
    frame->setLayout(layout);
    return frame;
}

QFrame* Tutorial::createDeckMenuTutPage()
{
    QFont naxa;
    QFont naxa_b;
    QFontDatabase db;
    naxa = db.font("Nexa Light","Normal",18);
    naxa_b = db.font("Nexa Light","Normal",18);
    naxa_b.setBold(true);

    QFrame* frame = new QFrame(this);
    frame->setMaximumSize(700,500);
    QLabel* line1 = new QLabel("Once you have created a deck, you will be brought to the deck's menu page.");
    QLabel* line2 = new QLabel("Here, you can see your deck stats, study, edit, or delete a deck.");
    line1->setFont(naxa);
    line2->setFont(naxa);

    mocMenu = new DeckMenu(mocDeck, NULL);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(line1,0, Qt::AlignHCenter);
    layout->addWidget(line2,0, Qt::AlignHCenter);
    layout->addWidget(mocMenu,0, Qt::AlignHCenter);
    frame->setLayout(layout);
    return frame;
}

QFrame* Tutorial::createStudyAreaTutPage()
{
    QFont naxa;
    QFont naxa_b;
    QFontDatabase db;
    naxa = db.font("Nexa Light","Normal",18);
    naxa_b = db.font("Nexa Light","Normal",18);
    naxa_b.setBold(true);

    QFrame* frame = new QFrame(this);
    frame->setMaximumSize(700,500);
    QLabel* line1 = new QLabel("Clicking study deck brings you to the Study Area. Click on the flashcards to get useful tips.");
    line1->setFont(naxa);

    StudyArea* mocStudyArea = new StudyArea(mocDeck, NULL, mocMenu);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(line1,0, Qt::AlignHCenter);
    layout->addWidget(mocStudyArea,0, Qt::AlignHCenter);
    frame->setLayout(layout);
    return frame;
}

QFrame* Tutorial::createDonePage()
{
    QFont naxa;
    QFont naxa_b;
    QFontDatabase db;
    naxa = db.font("Nexa Light","Normal",18);
    naxa_b = db.font("Nexa Light","Normal",18);
    naxa_b.setBold(true);

    QFrame* frame = new QFrame(this);
    frame->setMaximumSize(700,500);
    QLabel* line1 = new QLabel("You're done!");
    QLabel* line2 = new QLabel("Remember, all of your progress will be automatically saved for when you open FlashcardsPro again.");
    line1->setFont(naxa);
    line2->setFont(naxa);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(line1,0, Qt::AlignHCenter);
    layout->addWidget(line2,0, Qt::AlignHCenter);
    frame->setLayout(layout);
    return frame;
}
