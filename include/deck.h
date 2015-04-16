////////////////////////////////////////////////////////////////
// This class represents a deck of flash cards for use studying
// It will contain a vector of flash cards and allow access to them via 'studying'

#ifndef DECK_H
#define DECK_H

#include <QFile>
#include <vector>
#include <QString>
#include <QGraphicsWidget>
#include "flashcard.h"

class DeckLabel;    //forward declaration
class DeckMenu;     //forward declaration

class Deck
{
public:
    Deck(FILE* deck_file);
    Deck(std::vector<Flashcard*> _cards, QString deck_name_in);
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

private:
    void parseCard(QString* line);
    void parseInfo(QString* line);
    void makeSaveText();


    int maxScore;
};

#endif // DECK_H
