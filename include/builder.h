#ifndef BUILDER_H
#define BUILDER_H

#include <Qtwidgets>
#include "builderitem.h"
#include "decksview.h"

class builder : public QFrame
{
    Q_OBJECT

public:
    builder(QStackedWidget* pages_in, DecksView* decksview_in);
    ~builder();

private:
    QStackedWidget* pages;
    DecksView* decksview;

    QListWidget* card_list;

    QListWidgetItem* selected;

    QTextEdit* deck_title;
    QTextEdit* card_title;
    QTextEdit* front_text;
    QTextEdit* back_text;

    QPushButton* submit;
    QPushButton* remove;
    QPushButton* cancel;
    QPushButton* done;

public slots:
    void submit_card();
    void delete_card();
    void cancel_slot();
    void done_slot();
    void listClicked(QListWidgetItem*);
};

#endif // BUILDER_H
