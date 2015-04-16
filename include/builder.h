#ifndef BUILDER_H
#define BUILDER_H

#include <Qtwidgets>
#include "builderitem.h"
#include "decksview.h"
#include "user.h"

class builder : public QFrame
{
    Q_OBJECT

public:
    builder(QStackedWidget* pages_in, DecksView* decksview_in, User *_user);
    builder(QStackedWidget* pages_in, Deck* deck);
    ~builder();

private:
    QStackedWidget* pages;
    DecksView* decksview;
    Deck* decksave;

    QListWidget* card_list;

    QListWidgetItem* selected;

    QTextEdit* deck_title;

    QTextEdit* front_text;
    QTextEdit* back_text;

    QPushButton* submit;
    QPushButton* remove;
    QPushButton* cancel;
    QPushButton* done;\

    QLabel* titleplate;
    void setup();
    User* user;
public slots:
    void submit_card();
    void delete_card();
    void cancel_slot();
    void done_slot();
    void done_edit_slot();
    void listClicked(QListWidgetItem*);
};

#endif // BUILDER_H
