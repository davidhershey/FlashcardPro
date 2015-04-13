#include "builder.h"
#include "flashcard.h"

builder::builder(QStackedWidget* pages_in, DecksView* decksview_in)
{
    pages = pages_in;
    decksview = decksview_in;

    submit = new QPushButton(tr("Add Card"));
    remove = new QPushButton(tr("Delete Card"));
    done = new QPushButton(tr("Add Deck"));
    cancel = new QPushButton(tr("Cancel"));


    QLabel* header00 = new QLabel(tr("Deck title"));
    deck_title = new QTextEdit();

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(header00);
    layout->addWidget(deck_title);

    QLabel* title = new QLabel(tr("Deck Builder"));
    layout->addWidget(title);

    QHBoxLayout* layout2 = new QHBoxLayout();
    layout->addLayout(layout2);

    card_list = new QListWidget();

    QVBoxLayout *cardlay = new QVBoxLayout();
    cardlay->addWidget(card_list);
    cardlay->addWidget(remove);

    layout2->addLayout(cardlay);

    QVBoxLayout *layout3 = new QVBoxLayout();
    layout2->addLayout(layout3);


    QLabel* header0 = new QLabel(tr("Card title"));
    card_title = new QTextEdit();



    QLabel* header1 = new QLabel(tr("Front text"));
    QLabel* header2 = new QLabel(tr("Back text"));
    front_text = new QTextEdit();
    back_text = new QTextEdit();


    layout3->addWidget(header0);
    layout3->addWidget(card_title);
    layout3->addWidget(header1);
    layout3->addWidget(front_text);
    layout3->addWidget(header2);
    layout3->addWidget(back_text);
    layout3->addWidget(submit);

    layout->addSpacing(20);
    QVBoxLayout* layout4 = new QVBoxLayout();
    layout4->addWidget(done);
    layout4->addWidget(cancel);
    layout->addLayout(layout4);

    connect(submit, SIGNAL(pressed()), this, SLOT(submit_card()));
    connect(remove, SIGNAL(pressed()), this, SLOT(delete_card()));
    connect(cancel, SIGNAL(pressed()), this, SLOT(cancel_slot()));
    connect(done, SIGNAL(pressed()), this, SLOT(done_slot()));

    deck_title->setTabChangesFocus(true);
    card_title->setTabChangesFocus(true);
    front_text->setTabChangesFocus(true);
    back_text->setTabChangesFocus(true);

    this->setLayout(layout);

}

builder::~builder()
{

}

void builder::submit_card(){
    if ((card_title->toPlainText()).trimmed().isEmpty() | (front_text->toPlainText()).trimmed().isEmpty() | (back_text->toPlainText()).trimmed().isEmpty()){
        qDebug() << "empty card";
    }
    else {
        builderItem *add = new builderItem(card_list);
        add->setCardInfo(card_title->toPlainText(), front_text->toPlainText(), back_text->toPlainText());
        add->setText(card_title->toPlainText());
        card_list->insertItem(0, add);

        card_title->clear();
        front_text->clear();
        back_text->clear();
    }
}

void builder::delete_card(){
    card_list->takeItem(card_list->currentRow());
}

void builder::cancel_slot(){
    pages->removeWidget(this);
    pages->setCurrentIndex(1);
}

void builder::done_slot(){

    if (card_list->count() == 0){
        QMessageBox::warning(this, "Deck is empty", "Deck is empty.");
    }
    else {


    std::vector<Flashcard*> _cards;

    while (card_list->count() > 0){
    builderItem* item = dynamic_cast <builderItem*> (card_list->takeItem(0));
    Flashcard* card = new Flashcard(item->ftext(), item->btext(), 0);
    _cards.push_back(card);
    }

    Deck* send_deck = new Deck(_cards, deck_title->toPlainText());
    decksview->addNewDeckLabel(send_deck);

    pages->removeWidget(this);
    pages->setCurrentIndex(1);
    }
}