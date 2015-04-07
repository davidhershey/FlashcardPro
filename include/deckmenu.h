#ifndef DECKMENU_H
#define DECKMENU_H

#include <QObject>
#include <QWidget>
#include "deck.h"

class DeckMenu : public QWidget
{
    Q_OBJECT
public:
    explicit DeckMenu(QWidget *parent = 0);
    ~DeckMenu();

signals:

public slots:
};

#endif // DECKMENU_H
