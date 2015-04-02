#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <vector>
#include <QGridLayout>
#include "deck.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QAction* loadAct;
    std::vector<Deck*> decks;
    QGridLayout* decksLayout;

public slots:
    void loadDeck();
};

#endif // MAINWINDOW_H
