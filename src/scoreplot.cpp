#include "scoreplot.h"
#include <time.h>

ScorePlot::ScorePlot(Deck* deck, QWidget *parent) : QWidget(parent)
{
    QCustomPlot *plot = new QCustomPlot;
    QVector<double> times,score;

    for(int i = 0;i<deck->scoreTimes.size();i++){
        times.push_back(deck->scoreTimes[i]);
        score.push_back(i+1);
    }
    plot->addGraph();
    plot->graph(0)->addData(times,score);
    plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    plot->xAxis->setDateTimeFormat("MMM d\nhap");
    plot->xAxis->setLabel("Date");
    plot->yAxis->setLabel("Best Deck Score");
    plot->yAxis->setRange(0, 10);
    plot->yAxis->setAutoTickStep(false);
    plot->yAxis->setTickStep(1);
    plot->yAxis->setSubTickCount(1);
    // set axes ranges, so we see all data:
    time_t curtime;
    time(&curtime);
    plot->xAxis->setRange(times[0]-1000.0,double(curtime)+1000.0);
//    plot->graph()->rescaleAxes(true);

    plot->replot();

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(plot);
    this->setLayout(vbox);
}

ScorePlot::~ScorePlot()
{

}

