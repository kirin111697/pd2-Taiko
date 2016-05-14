#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>

class item : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    item(int color);
    int getColor();

public slots:
    void moving();
    void setting(int color);

private:
    int bitColor;
};

#endif // ITEM_H
