#ifndef MAINMENU_H
#define MAINMENU_H
#include <QtWidgets>

class mainmenu : public QFrame
{
    Q_OBJECT
public:
    mainmenu(QStackedWidget* pages_in);
    ~mainmenu();
private:
    QStackedWidget* pages;
    QPushButton* study_button;
    QPushButton* builder_button;
    QPushButton* stats_button;
    QPushButton* connect_button;

public slots:
    void switch_study();
    void switch_main();
    void switch_builder();
    void switch_stats();
    void switch_connect();
};

#endif // MAINMENU_H
