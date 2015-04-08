#ifndef STATSVIEW_H
#define STATSVIEW_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "deck.h"
class StatsView : public QWidget
{
    Q_OBJECT
public:
    explicit StatsView(Deck* _deck, QStackedWidget *pages_in, QWidget *parent = 0);
    ~StatsView();

signals:

public slots:
    void goBack();
private:
    Deck *deck;
    QVBoxLayout *vbox;
    QStackedWidget *pages;
};

#endif // STATSVIEW_H
