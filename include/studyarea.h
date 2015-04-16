#ifndef STUDYAREA_H
#define STUDYAREA_H

#include <QWidget>
#include <QtWidgets>
#include "deck.h"
#include "flashcard.h"
#include "deckmenu.h"

class StudyArea : public QGraphicsView
{
    Q_OBJECT
public:
    explicit StudyArea(Deck* _deck, QStackedWidget* pages_in, DeckMenu* parent_in);
    ~StudyArea();

signals:

public slots:
    void correct();
    void incorrect();
    void goBack();

private:
    QLabel *scores;
    QGridLayout *grid;
    Deck *deck;
    QStackedWidget* pages;
    Flashcard *curCard;
    DeckMenu* parent;
};

#endif // STUDYAREA_H
