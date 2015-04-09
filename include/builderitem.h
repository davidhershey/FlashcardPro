#ifndef BUILDERITEM_H
#define BUILDERITEM_H

#include <QtWidgets>

class builderItem : public QListWidgetItem
{

public:
    builderItem(QListWidget* list_in);
    ~builderItem();
    void setCardInfo(QString titlein, QString frontin, QString backin);
    QString ftext();
    QString btext();
private:
    QListWidget* list;
    QString front_text;
    QString back_text;
    QString card_title;
};

#endif // BUILDERITEM_H
