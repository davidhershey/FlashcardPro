#ifndef DECKMENU_H
#define DECKMENU_H

#include <QObject>
#include <QWidget>
#include <QStackedWidget>
#include "deck.h"
#include "decklabel.h"

class DeckMenu : public QWidget
{
    Q_OBJECT
public:
    explicit DeckMenu(Deck* _deck, QStackedWidget *pages_in, QWidget *parent = 0);
    QLabel* title;
    ~DeckMenu();
    void updateMenu();

signals:

public slots:
    void study();
    void edit();
    void stats();
    void saveDeckCallback();
    void back();
private:
    Deck* deck;
    QStackedWidget* pages;
    QLabel* quick_stats;

};

#endif // DECKMENU_H
