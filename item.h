#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>

class item : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    item();

public slots:
    void moving();
    void setting();
};

#endif // ITEM_H
