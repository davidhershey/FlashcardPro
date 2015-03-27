////////////////////////////////////////////////////////////////
// This class represents a deck of flash cards for use studying
// It will contain a vector of flash cards and allow access to them via 'studying'

#ifndef DECK_H
#define DECK_H

#include <QtWidgets>
#include <vector>

class Deck
{
public:
    Deck(FILE* deck_file);
    ~Deck();
    void saveDeck(QString location);

    int deck_score;
    int num_cards;
    QString deck_name;
    std::vector<QGraphicsWidget*> cards;

private:
    void parseCard(QString* line);
    void parseInfo(QString* line);
};

#endif // DECK_H
