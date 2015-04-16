////////////////////////////////////////////////////////////////
// This class represents a deck of flash cards for use studying
// It will contain a vector of flash cards and allow access to them via 'studying'

#ifndef DECK_H
#define DECK_H
class Deck;
class User;
#include <QFile>
#include <vector>
#include <QString>
#include <QGraphicsWidget>
#include "flashcard.h"
#include "user.h"
#include "decklabel.h"
#include "deckmenu.h"
class DeckLabel;    //forward declaration
class DeckMenu;     //forward declaration

class Deck
{
public:
    Deck(FILE* deck_file, User* _user);
    Deck(std::vector<Flashcard*> _cards, QString deck_name_in, User* _user);
    ~Deck();

    int deck_score;
    int num_cards;
    QString deck_name;
    std::vector<Flashcard*> cards;
    QString saveText;
    Flashcard* getTop();
    int getDeckScore();
    DeckLabel* label;
    DeckMenu* menu;

    void shuffle();
    void saveDeck(QString fileName);
    Flashcard* getHardest();
    std::vector<int> scoreTimes;
    std::vector<Flashcard*> getDeck();
    void updateDeck(std::vector<Flashcard*> cards_in);

    void autoSave();
private:
    void parseCard(QString* line);
    void parseInfo(QString* line);
    void makeSaveText();
    User *user;

    int maxScore;
};

#endif // DECK_H
