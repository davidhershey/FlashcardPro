#ifndef DECKSVIEW_H
#define DECKSVIEW_H
#include <QFrame>
#include <vector>
#include <QGridLayout>
#include "deck.h"
#include "decklabel.h"

class DecksView :public QFrame
{
    Q_OBJECT
public:
    DecksView(QStackedWidget* pages_in);
    ~DecksView();

private:
    //QAction* loadAct;
    QStackedWidget* pages;
    std::vector<Deck*> decks;
    QGridLayout* decksLayout;
    DeckLabel* loadLabel;
    QPushButton* backButton;

public slots:
    void loadDeck(Deck *nulldeck);
    void openDeck(Deck *deck);
    void goBack();
};

#endif // DECKSVIEW_H
