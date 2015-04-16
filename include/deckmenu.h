#ifndef DECKMENU_H
#define DECKMENU_H

#include <QObject>
#include <QWidget>
#include <QStackedWidget>
#include "deck.h"
#include "scoreplot.h"
#include "decklabel.h"

class ScorePlot;

class DeckMenu : public QWidget
{
    Q_OBJECT
public:
    DeckMenu(Deck* _deck, QStackedWidget *pages_in,QWidget *parent = 0);
    QLabel* title;
    ~DeckMenu();
    void updateMenu();
    ScorePlot *sp;
    QDialog* confirm;
signals:

public slots:
    void study();
    void edit();
    void deleteDeck();
    void stats();
    void saveDeckCallback();
    void back();
    void yes();
    void no();
private:
    Deck* deck;
    QStackedWidget* pages;
    QLabel* quick_stats;

};

#endif // DECKMENU_H
