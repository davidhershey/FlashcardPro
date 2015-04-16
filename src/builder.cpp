#include "builder.h"
#include "flashcard.h"
#include "deckmenu.h"
#include <stack>

builder::builder(QStackedWidget* pages_in, DecksView* decksview_in, User* _user)
{
        decksview = decksview_in;
        user = _user;
        pages = pages_in;

        setup();
        connect(done, SIGNAL(pressed()), this, SLOT(done_slot()));
}

builder::builder(QStackedWidget* pages_in, Deck* deck)
{
    pages = pages_in;
    decksave = deck;

    setup();

    done->setText("Save Changes");
    titleplate->setText("Deck Editor");

    connect(done, SIGNAL(pressed()), this, SLOT(done_edit_slot()));

    std::vector <Flashcard*> import = deck->getDeck();
    for (int i=0; i < import.size(); i++){
        builderItem *add = new builderItem(card_list);
        add->setCardInfo(import[i]->fstr, import[i]->bstr);
        add->setText(import[i]->fstr);
        card_list->insertItem(0,add);
    }
    deck_title->setText(deck->deck_name);

}



builder::~builder()
{

}

void builder::submit_card(){
    if ((front_text->toPlainText()).trimmed().isEmpty() | (back_text->toPlainText()).trimmed().isEmpty()){
        qDebug() << "empty card";
    }
    else {
        bool free = true;
        builderItem* update;
        for (int i=0; i < card_list->count(); i++){

            if (card_list->item(i)->text() == front_text->toPlainText()){
                free = false;
                update = dynamic_cast <builderItem*> (card_list->item(i));
            }

        }

        if (free == true){
        builderItem *add = new builderItem(card_list);
        add->setCardInfo( front_text->toPlainText(), back_text->toPlainText());
        add->setText(front_text->toPlainText());
        card_list->insertItem(0, add);

        front_text->clear();
        back_text->clear();
        }
        else {
            qDebug() << "update existing card";
            update->setCardInfo(front_text->toPlainText(), back_text->toPlainText());
        }
    }
}

void builder::delete_card(){
    card_list->takeItem(card_list->currentRow());
    front_text->clear();
    back_text->clear();
}

void builder::cancel_slot(){
    int index = pages->currentIndex();
    pages->removeWidget(this);
    pages->setCurrentIndex(index-1);
}

void builder::done_slot(){

    if (card_list->count() == 0){
        QMessageBox::warning(this, "Deck is empty", "Deck is empty.");
    }
    else {


    std::stack<Flashcard*> _cards;

    while (card_list->count() > 0){
    builderItem* item = dynamic_cast <builderItem*> (card_list->takeItem(0));
    Flashcard* card = new Flashcard(item->ftext(), item->btext(), 1);
    _cards.push(card);
    }

    std::vector<Flashcard*> rev_cards;
    while(!_cards.empty())
    {
        rev_cards.push_back(_cards.top());
        _cards.pop();
    }

    Deck* send_deck = new Deck(rev_cards, deck_title->toPlainText(),user);
    decksview->addNewDeckLabel(send_deck);

    int index = pages->currentIndex();
    pages->removeWidget(this);
    pages->setCurrentIndex(index-1);
    }
}

void builder::listClicked(QListWidgetItem* item){

    builderItem* myItem = dynamic_cast <builderItem*> (card_list->currentItem());

    front_text->setText(myItem->ftext());
    back_text->setText(myItem->btext());
}

void builder::done_edit_slot(){
    int index = pages->currentIndex();
    pages->removeWidget(this);
    pages->setCurrentIndex(index-1);


    std::vector<Flashcard*> _cards;

    while (card_list->count() > 0){
    builderItem* item = dynamic_cast <builderItem*> (card_list->takeItem(0));
    Flashcard* card = new Flashcard(item->ftext(), item->btext(), 1);
    _cards.push_back(card);
    qDebug() << "push card";
    }

    decksave->updateDeck(_cards);
    decksave->deck_name = deck_title->toPlainText();
    decksave->label->updateName();
    decksave->menu->title->setText(decksave->deck_name);
}

void builder::setup(){

    submit = new QPushButton(tr("Add/Update Card"));
    remove = new QPushButton(tr("Delete Card"));
    cancel = new QPushButton(tr("Cancel"));
    done = new QPushButton(tr("Add Deck"));

    titleplate = new QLabel(tr("Deck title"));
    deck_title = new QTextEdit();

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(titleplate);
    deck_title->setMaximumHeight(40);

    QHBoxLayout* titlelay = new QHBoxLayout();
    QLabel* title2 = new QLabel(tr("Deck Name"));

    titlelay->addWidget(title2);
    titlelay->addWidget(deck_title);

    layout->addLayout(titlelay);

    QHBoxLayout* layout2 = new QHBoxLayout();
    layout->addLayout(layout2);

    card_list = new QListWidget();

    QVBoxLayout *cardlay = new QVBoxLayout();
    cardlay->addWidget(card_list);
    cardlay->addWidget(remove);

    layout2->addLayout(cardlay);

    QVBoxLayout *layout3 = new QVBoxLayout();
    layout2->addLayout(layout3);

    QLabel* header1 = new QLabel(tr("Front text"));
    QLabel* header2 = new QLabel(tr("Back text"));
    front_text = new QTextEdit();
    back_text = new QTextEdit();


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

    deck_title->setTabChangesFocus(true);
    front_text->setTabChangesFocus(true);
    back_text->setTabChangesFocus(true);

    connect(card_list, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(listClicked(QListWidgetItem*)));

    this->setLayout(layout);

    QFont headerfont, smallfont, medfont;
    QFontDatabase db;

    headerfont = db.font("Nexa Light", "Normal", 48);
    smallfont = db.font("Nexa Light", "Normal", 18);
    medfont = db.font("Nexa Light", "Normal", 24);

    titleplate->setFont(headerfont);
    title2->setFont(medfont);

    submit->setFont(medfont);
    remove->setFont(medfont);
    cancel->setFont(medfont);
    done->setFont(medfont);
    deck_title->setFont(smallfont);
    front_text->setFont(smallfont);
    back_text->setFont(smallfont);
    header1->setFont(medfont);
    header2->setFont(medfont);

}
