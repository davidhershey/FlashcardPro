#ifndef SCOREPLOT_H
#define SCOREPLOT_H

#include <QObject>
#include <QWidget>
#include "qcustomplot.h"
#include "deck.h"

class ScorePlot : public QWidget
{
    Q_OBJECT
public:
    explicit ScorePlot(Deck *deck, QWidget *parent = 0);
    ~ScorePlot();

signals:

public slots:
};

#endif // SCOREPLOT_H
