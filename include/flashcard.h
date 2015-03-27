#ifndef FLASHCARD_H
#define FLASHCARD_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QGraphicsWidget>
#include <QStackedWidget>
class Flashcard : public QGraphicsWidget
{
    Q_OBJECT
public:
    explicit Flashcard(QString ftext, QString btext, int cscore, QWidget *parent = 0);
    ~Flashcard();
    int card_score;

signals:
    void flipRequest(); // private
    void clicked();

protected:
    void mousePressEvent ( QMouseEvent * event ) ;
    void resizeEvent(QGraphicsSceneResizeEvent *event);
public slots:

private slots:
    void togglePage();
private:
    QString fstr;
    QString bstr;

//    QLabel* front;
//    QLabel* back;
    QStackedWidget* m_stack;
};

#endif // FLASHCARD_H

