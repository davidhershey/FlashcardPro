#ifndef STUDYAREA_H
#define STUDYAREA_H

#include <QWidget>
#include <QtWidgets>
#include "deck.h"
#include "flashcard.h"

class StudyArea : public QGraphicsView
{
    Q_OBJECT
public:
    explicit StudyArea(Deck* _deck, QStackedWidget* pages_in, QWidget *parent = 0);
    ~StudyArea();

signals:

public slots:
    void correct();
    void incorrect();
    void goBack();

private:
    QGridLayout *grid;
    Deck *deck;
    QStackedWidget* pages;
    Flashcard *curCard;
};

#endif // STUDYAREA_H
