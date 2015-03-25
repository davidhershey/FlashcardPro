#ifndef FLASHCARD_H
#define FLASHCARD_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class Flashcard : public QLabel
{
    Q_OBJECT
public:
    explicit Flashcard(QWidget *parent = 0);
    ~Flashcard();

signals:

public slots:
};

#endif // FLASHCARD_H
