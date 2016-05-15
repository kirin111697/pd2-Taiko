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
    int getTime();

public slots:
    void moving();
    void setting(int color);

private:
    int bitColor;
    int appearT;
};

#endif // ITEM_H
