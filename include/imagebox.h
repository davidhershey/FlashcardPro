#ifndef IMAGEBOX_H
#define IMAGEBOX_H

#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QtGui>
#include <QtWidgets>
#include <QWidget>
#include <vector>
#include "imagebox.h"
class ImageBox : public QLabel
{
    Q_OBJECT
public:
    explicit ImageBox(QWidget *parent = 0);
    ImageBox(QString fileName, QWidget *parent = 0);
    ImageBox(QImage image, QWidget *parent=0);
    ~ImageBox();
    void select();
    void unselect();
    bool selected = false;
    void setBoxNo(int no);
    QImage getImage();
signals:
    void clicked();

protected:
    void mousePressEvent ( QMouseEvent * event ) ;

public slots:
private:
    int boxno;
    QImage image_data;
};

#endif // IMAGEBOX_H
