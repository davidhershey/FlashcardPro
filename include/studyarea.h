#ifndef STUDYAREA_H
#define STUDYAREA_H
#include "deck.h"
#include <QtWidgets>
class StudyArea : public QFrame
{
    Q_OBJECT
public:
    StudyArea(Deck* deck_in);
    ~StudyArea();

private:
    Deck* deck;
    int current_card;
    QGridLayout *grid;
    QPushButton* prevButton;
    QPushButton* nextButton;

public slots:
    void nextCard();
    void prevCard();
};

#endif // STUDYAREA_H
