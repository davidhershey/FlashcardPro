#include "decklabel.h"
#include <QMouseEvent>
#include "studyarea.h"
#include "deckmenu.h"


DeckLabel::DeckLabel(Deck* deck_in, QStackedWidget* pages_in, QGridLayout* grid_in, QWidget * parent ):
    QLabel(parent)

  {
      deck = deck_in;
      pages = pages_in;
      grid = grid_in;

      if(deck == NULL)
      {
          QPixmap pm(":/add_deck.png");
          this->setPixmap(pm);
          hover = false;
          this->setMinimumSize(pm.width(), pm.height());
          this->setMaximumSize(pm.width(), pm.height());
          qDebug() << pm.width();
          qDebug() << pm.height();
      }
      else
      {
          QFont naxa;
          QFontDatabase db;
          naxa = db.font("Nexa Light","Normal",12);
          this->setFont(naxa);
          this->setText(deck->deck_name);

          this->setStyleSheet("border: 1px solid; background-color: white; qproperty-alignment: AlignCenter; border-radius: 8px;");
          this->setFixedSize(129, 200);
          hover = true;
      }



  }

  DeckLabel::~DeckLabel()
  {

  }

  void DeckLabel::mousePressEvent ( QMouseEvent * event )

  {
      //std::cout << "Got click" << std::endl;
      emit clicked();
  }

  void DeckLabel::enterEvent(QEvent * event)
  {
    qDebug() << "entered!";
    if(hover) this->setStyleSheet("border: 2px solid; background-color: white; qproperty-alignment: AlignCenter; border-radius: 8px;");
  }

  void DeckLabel::leaveEvent(QEvent * event)
  {
    qDebug() << "exited!";
    if(hover) this->setStyleSheet("border: 1px solid; background-color: white; qproperty-alignment: AlignCenter; border-radius: 8px;");
  }

  void DeckLabel::openDeck()
  {
      DeckMenu *dm = new DeckMenu(deck,pages);
      int index = pages->addWidget(dm);
      pages->setCurrentIndex(index);
  }

  void DeckLabel::saveDeckCallback()
  {
      QString fileName = QFileDialog::getSaveFileName(this, tr("Save Selected Deck"),
                                                      QDir::homePath() + QDir::separator() + "*",
                                                      "");
     deck->saveDeck(fileName);
  }

void DeckLabel::updateName(){
    if(deck == NULL) return;
    this->setText(deck->deck_name);
}

void DeckLabel::SELFDESTRUCT()
{
    int index = grid->indexOf(this);
    QWidget* del = grid->itemAt(index)->widget();

    //reposition everything in decksLayout
    for(int i = index+1; i < grid->count(); ++i)
    {
        QWidget* move = grid->itemAtPosition(int(i/5),i%5)->widget();
        grid->addWidget(move, int((i-1)/5),(i-1)%5);
    }
    grid->removeWidget(del);
    delete deck;
    delete this;
}
