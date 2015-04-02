#ifndef DECKLABEL_H
#define DECKLABEL_H

#include <QtWidgets>
#include "deck.h"
class DeckLabel:public QLabel
{
    Q_OBJECT
public:
    explicit DeckLabel(Deck* deck_in, QWidget * parent = 0 );
    ~DeckLabel();

private:
    Deck* deck;

signals:
    void clicked();

protected:
    void mousePressEvent ( QMouseEvent * event );

public slots:
    void chooseNext();
    void initStudyArea();
    void saveDeck();

};

#endif // DECKLABEL_H

