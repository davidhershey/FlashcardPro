#ifndef DECKLABEL_H
#define DECKLABEL_H

#include <QtWidgets>
#include "deck.h"

class DeckLabel:public QPushButton
{
    Q_OBJECT
public:
    explicit DeckLabel(Deck* deck_in, QStackedWidget* pages_in, QWidget * parent = 0 );
    ~DeckLabel();
    void updateName();
private:
    Deck* deck;
    QStackedWidget* pages;
    bool hover;

signals:
    void clicked(Deck* _deck);

protected:
    //void mousePressEvent ( QMouseEvent * event );
    //void enterEvent(QEvent * event);
    //void leaveEvent(QEvent * event);

public slots:
    void chooseNext();
    void initStudyArea();
    void saveDeckCallback();
    void openDeck();

};

#endif // DECKLABEL_H

