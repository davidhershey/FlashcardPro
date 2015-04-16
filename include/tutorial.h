#ifndef TUTORIAL
#define TUTORIAL
#include <QDialog>
#include <QStackedWidget>
#include <QPushButton>
#include <QFrame>

class Tutorial : public QDialog
{
    Q_OBJECT

public:
    Tutorial();
    ~Tutorial();
    QStackedWidget* tutPages;
    QPushButton* next;
    QPushButton* prev;
    QFrame* createUserTutPage();
    QFrame* createDecksViewTutPage();
    QFrame* createDeckMenuTutPage();
    QFrame* createStudyAreaTutPage();
    QFrame* createDonePage();

public slots:
    void prevCallback();
    void nextCallback();

};

#endif // TUTORIAL

