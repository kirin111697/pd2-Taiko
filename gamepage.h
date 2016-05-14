#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QMovie>
#include <QGraphicsScene>
#include <QTimer>
#include "item.h"
#include <QVector>
#include <ctime>
#include <cstdlib>
#include <QKeyEvent>

namespace Ui {
class gamePage;
}

class gamePage : public QWidget
{
    Q_OBJECT

public:
    explicit gamePage(QWidget *parent = 0);
    QTimer *mapTMR;
    void bitmap();
    ~gamePage();

public slots:
    void addBit();
    void keyPressEvent(QKeyEvent *hit);

private:
    Ui::gamePage *ui;
    QMovie *gif;
    QGraphicsScene *sc;
    QTimer *moveTMR;
    item *bit;
    QVector<item*> keep;
    QVector<item*> ::iterator it;
};

#endif // GAMEPAGE_H
