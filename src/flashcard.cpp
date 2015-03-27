#include "../include/flashcard.h"
#include <QStateMachine>
#include <QPropertyAnimation>
#include <QGraphicsProxyWidget>
#include <QGraphicsLinearLayout>
#include <QSignalTransition>
#include <QGraphicsRotation>
#include <QtGui>
#include <QObject>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGraphicsSceneResizeEvent>
#include "../include/imagebox.h"

Flashcard::Flashcard(QString ftext, QString btext, int cscore, QWidget *parent)
{
    card_score = cscore;
    ImageBox* front = new ImageBox;
    ImageBox* back = new ImageBox;
    fstr = ftext;
    front->setText(ftext);
    int h = 350;
    int w = 550;
    front->setBackgroundRole(QPalette::Base); // some from http://qt-project.org/doc/qt-4.8/widgets-imageviewer.html
    front->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    front->setFixedHeight(h);
    front->setFixedWidth(w);
    front->setScaledContents(false);
    front->setFrameStyle(QFrame::Box | QFrame::Plain);
    front->setAlignment(Qt::AlignCenter);
    front->setStyleSheet("QLabel { background-color : white; color : black; }");

    bstr = btext;
    back->setText(btext);
    back->setBackgroundRole(QPalette::Base); // some from http://qt-project.org/doc/qt-4.8/widgets-imageviewer.html
    back->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    back->setFixedHeight(h);
    back->setFixedWidth(w);
    back->setScaledContents(false);
    back->setFrameStyle(QFrame::Box | QFrame::Plain);
    back->setAlignment(Qt::AlignCenter);
    back->setStyleSheet("QLabel { background-color : white; color : black; }");
    // The front.
//        QWidget* front = new QWidget();
//        QPushButton *toBackButton = new QPushButton("To Back");
//        QObject::connect(toBackButton, SIGNAL(clicked()), this, SIGNAL(flipRequest()));
//        toBackButton->setStyleSheet("background: pink");
//        QVBoxLayout *vbox1 = new QVBoxLayout(front);
//        vbox1->addWidget(toBackButton);
//        front->setLayout(vbox1);

//        // The back.
//        QWidget* back = new QWidget();
//        QPushButton *toFrontButton = new QPushButton("To Front");
//        QObject::connect(toFrontButton, SIGNAL(clicked()), this, SIGNAL(flipRequest()));
//        toFrontButton->setStyleSheet("background: yellow");
//        QVBoxLayout *vbox2 = new QVBoxLayout(back);
//        vbox2->addWidget(toFrontButton);


    // The stacked widget.
    //From http://blog.qt.io/blog/2009/06/09/flippin-widgets-medium-rare-please/

    connect(front,SIGNAL(clicked()),this,SIGNAL(flipRequest()));
    connect(back,SIGNAL(clicked()),this,SIGNAL(flipRequest()));
    m_stack = new QStackedWidget();
    m_stack->addWidget(front);
    m_stack->addWidget(back);


    QGraphicsRotation* rotation = new QGraphicsRotation();
    rotation->setAxis( QVector3D( 1, 1, 1) );
    QList<QGraphicsTransform *> transformations;
    transformations << rotation;
    setTransformations( transformations );

    QGraphicsProxyWidget *stackProxy = new QGraphicsProxyWidget;
    stackProxy->setWidget(m_stack);
    QGraphicsLinearLayout *vbox = new QGraphicsLinearLayout;
    vbox->addItem(stackProxy);
    this->setLayout(vbox);

    rotation->setOrigin( QVector3D( front->width()/4 ,front->height()/4,0) );

    QStateMachine *machine = new QStateMachine;
    QState *s0 = new QState(machine);
    s0->assignProperty(rotation, "angle", 0);

    QState *s1 = new QState(machine);
    s1->assignProperty(rotation, "angle", 90);

    QAbstractTransition *t1 = s0->addTransition(this, SIGNAL(flipRequest()), s1);
    QPropertyAnimation *yRotationAnim = new QPropertyAnimation(rotation, "angle");
    yRotationAnim->setDuration(250);
    t1->addAnimation(yRotationAnim);

    QState *s2 = new QState(machine);
    QObject::connect(s2, SIGNAL(entered()), this, SLOT(togglePage()));
    s2->assignProperty(rotation, "angle", -90);
    s1->addTransition(s1, SIGNAL(propertiesAssigned()), s2);

    QAbstractTransition *t2 = s2->addTransition(s0);
    t2->addAnimation(yRotationAnim);

    machine->setInitialState(s0);
    machine->start();
}

Flashcard::~Flashcard()
{

}

void Flashcard::togglePage()
{
    m_stack->setCurrentIndex(m_stack->currentIndex() ^ 1);
}

void Flashcard::mousePressEvent(QMouseEvent *event)
{
 emit clicked();
}

void Flashcard::resizeEvent(QGraphicsSceneResizeEvent *event)
{
    QSizeF siz = event->newSize();
    QPointF pt = QPointF(siz.width() / 2, siz.height() / 2);
    setTransformOriginPoint(pt);
}
