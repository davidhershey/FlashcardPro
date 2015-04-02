#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QAction* loadAct;
    QAction* saveAct;
    QAction* studyAct;
    Deck* deck;

public slots:
    void loadDeck();
    void saveDeck();
    void studyDeck();
};

#endif // MAINWINDOW_H
