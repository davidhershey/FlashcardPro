#include "decklabel.h"
#include <QMouseEvent>
#include "studyarea.h"
#include "deckmenu.h"


DeckLabel::DeckLabel(Deck* deck_in, QStackedWidget* pages_in, QWidget * parent ):
    QLabel(parent)

  {
      deck = deck_in;
      pages = pages_in;
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
          /*QPixmap pm(":/deck.png");
          QPalette palette;
          palette.setBrush(this->backgroundRole(), QBrush(pm));
          this->setFlat(true);
          this->setAutoFillBackground(true);
          this->setPalette(palette);
          this->setText(deck->deck_name);*/
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

  void DeckLabel::chooseNext()
  {
      QDialog* chooseDialog = new QDialog();
      QVBoxLayout* layout = new QVBoxLayout();
      QPushButton* studyButton = new QPushButton("Study Deck");
      QPushButton* saveButton = new QPushButton("Save Deck");
      QPushButton* cancButton = new QPushButton("Cancel");
      connect(studyButton, SIGNAL(clicked()), this, SLOT(initStudyArea()));
      connect(saveButton, SIGNAL(clicked()), this, SLOT(saveDeck()));
      connect(studyButton, SIGNAL(clicked()), chooseDialog, SLOT(accept()));
      connect(saveButton, SIGNAL(clicked()), chooseDialog, SLOT(accept()));
      connect(cancButton, SIGNAL(clicked()), chooseDialog, SLOT(reject()));
      layout->addWidget(studyButton);
      layout->addWidget(saveButton);
      layout->addWidget(cancButton);
      chooseDialog->setLayout(layout);
      chooseDialog->exec();
      return;
  }

  /*void DeckLabel::initStudyArea()
  {
      StudyArea* area = new StudyArea(deck, pages);
      int index = pages->addWidget(area);
      pages->setCurrentIndex(index);
//      area->exec();
  }*/

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
