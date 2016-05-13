#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QMovie>
#include <QGraphicsScene>
#include <QTimer>
#include "item.h"

namespace Ui {
class gamePage;
}

class gamePage : public QWidget
{
    Q_OBJECT

public:
    explicit gamePage(QWidget *parent = 0);
    QTimer *timer;
    //void bitmap();
    ~gamePage();

private:
    Ui::gamePage *ui;
    QMovie *gif;
    QGraphicsScene *sc;
    item *note;
};

#endif // GAMEPAGE_H
