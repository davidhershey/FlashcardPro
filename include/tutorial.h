#ifndef TUTORIAL
#define TUTORIAL
#include <QDialog>
#include <QStackedWidget>
#include <QPushButton>
#include <QFrame>
#include "deck.h"
#include "deckmenu.h"

class Tutorial : public QDialog
{
    Q_OBJECT

public:
    Tutorial();
    ~Tutorial();
    QStackedWidget* tutPages;
    QPushButton* next;
    QPushButton* prev;
    QFrame* createUserTutPage();
    QFrame* createDecksViewTutPage();
    QFrame* createDeckMenuTutPage();
    QFrame* createStudyAreaTutPage();
    QFrame* createDonePage();

    Deck* mocDeck;
    DeckMenu* mocMenu;

public slots:
    void prevCallback();
    void nextCallback();

};

#endif // TUTORIAL

