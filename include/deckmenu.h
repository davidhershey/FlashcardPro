#ifndef DECKMENU_H
#define DECKMENU_H

#include <QObject>
#include <QWidget>
#include <QStackedWidget>
#include "deck.h"

class DeckMenu : public QWidget
{
    Q_OBJECT
public:
    explicit DeckMenu(Deck* _deck, QStackedWidget *pages_in, QWidget *parent = 0);
    ~DeckMenu();

signals:

public slots:
    void study();
    void edit();

    void stats();
    void back();
private:
    Deck* deck;
    QStackedWidget* pages;
};

#endif // DECKMENU_H
