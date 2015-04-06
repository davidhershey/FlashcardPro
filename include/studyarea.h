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
    explicit StudyArea(Deck* _deck,QWidget *parent = 0);
    ~StudyArea();

signals:

public slots:
    void correct();
    void incorrect();

private:
    QGridLayout *grid;
    Deck *deck;
    Flashcard *curCard;
};

#endif // STUDYAREA_H
