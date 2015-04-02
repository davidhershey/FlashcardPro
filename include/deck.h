////////////////////////////////////////////////////////////////
// This class represents a deck of flash cards for use studying
// It will contain a vector of flash cards and allow access to them via 'studying'

#ifndef DECK_H
#define DECK_H

#include <QFile>
#include <vector>
#include <QString>
#include <QGraphicsWidget>

class Deck
{
public:
    Deck(FILE* deck_file);
    ~Deck();

    int deck_score;
    int num_cards;
    QString deck_name;
    std::vector<QGraphicsWidget*> cards;
    QString saveText;

private:
    void parseCard(QString* line);
    void parseInfo(QString* line);
};

#endif // DECK_H
