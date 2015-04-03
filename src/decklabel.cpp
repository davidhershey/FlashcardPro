#include "decklabel.h"
#include <QMouseEvent>
#include "studyarea.h"


DeckLabel::DeckLabel(Deck* deck_in, QWidget * parent ):
    QLabel(parent)

  {
      deck = deck_in;
      if(deck == NULL) this->setText("Load New\nDeck");
      else this->setText(deck->deck_name);

      this->setStyleSheet("border: 1px solid");
      this->setMinimumSize(50, 100);
      this->setMaximumSize(100, 200);

  }

  DeckLabel::~DeckLabel()
  {

  }

  void DeckLabel::mousePressEvent ( QMouseEvent * event )

  {
      //std::cout << "Got click" << std::endl;
      emit clicked();
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

  void DeckLabel::initStudyArea()
  {
      StudyArea* area = new StudyArea(deck);
      area->exec();
  }

  void DeckLabel::saveDeck()
  {
      QString deck_save = deck->saveText;
      QString fileName = QFileDialog::getSaveFileName(this, tr("Save Selected Deck"),
                                                      QDir::homePath() + QDir::separator() + "*",
                                                      "");

      if (fileName.isEmpty() || fileName.isNull())
        return;

      QFile file(fileName);
              if (!file.open(QIODevice::WriteOnly)) {
                  QMessageBox::information(this, tr("Unable to open file"),
                      file.errorString());
                  return;
              }
      QTextStream out(&file);
      out << deck_save;
      file.close();
  }
