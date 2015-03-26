#include "imagebox.h"
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QtGui>
#include <QtWidgets>
#include <QWidget>
ImageBox::ImageBox(QWidget *parent) : QLabel(parent)
{

}

ImageBox::ImageBox(QString fileName, QWidget *parent) : QLabel(parent)
{
    int h = 150;
    int w = 150;
    this->setBackgroundRole(QPalette::Base); // some from http://qt-project.org/doc/qt-4.8/widgets-imageviewer.html
    this->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    this->setFixedHeight(h);
    this->setFixedWidth(w);
    this->setScaledContents(false);
    this->setFrameStyle(QFrame::Box | QFrame::Plain);
    this->setAlignment(Qt::AlignCenter);
    this->setLineWidth(1);
    if (!fileName.isEmpty()) {//from http://qt-project.org/doc/qt-4.8/widgets-imageviewer.html
        QImage image(fileName);
        image_data = image;
        if (image.isNull()) {
            QMessageBox::information(this, tr("Image Viewer"),
                                     tr("Cannot load %1.").arg(fileName));
            return;
        }
        QPixmap pm = QPixmap::fromImage(image);
        this->setPixmap(pm.scaled(h,w,Qt::KeepAspectRatio));
    }
}

ImageBox::ImageBox(QImage image, QWidget *parent)
{
    int h = 150;
    int w = 150;
    this->setBackgroundRole(QPalette::Base); // some from http://qt-project.org/doc/qt-4.8/widgets-imageviewer.html
    this->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    this->setFixedHeight(h);
    this->setFixedWidth(w);
    this->setScaledContents(false);
    this->setFrameStyle(QFrame::Box | QFrame::Plain);
    this->setAlignment(Qt::AlignCenter);
    this->setLineWidth(1);
//    if (!image.isNull()) {//from http://qt-project.org/doc/qt-4.8/widgets-imageviewer.html
    image_data = image;
//    if (image.isNull()) {
//        QMessageBox::information(this, tr("Image Viewer"),
//                                 tr("Cannot load %1.").arg(fileName));
//        return;
//    }
    QPixmap pm = QPixmap::fromImage(image);
    this->setPixmap(pm.scaled(h,w,Qt::KeepAspectRatio));
//    }
}

ImageBox::~ImageBox()
{

}

void ImageBox::setBoxNo(int no)
{
    boxno = no;
}

QImage ImageBox::getImage()
{
    return image_data;
}

void ImageBox::mousePressEvent(QMouseEvent *event)
{
 emit clicked();
}

void ImageBox::select()
{
    QPalette palette = this->palette();
    palette.setColor(this->backgroundRole(), Qt::blue);
    palette.setColor(this->foregroundRole(), Qt::blue);
    selected = true;
    this->setPalette(palette);
}

void ImageBox::unselect()
{
    QPalette palette = this->palette();
    palette.setColor(this->backgroundRole(), Qt::black);
    palette.setColor(this->foregroundRole(), Qt::black);
    selected = false;
    this->setPalette(palette);
}


