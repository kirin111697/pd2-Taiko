#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QDebug>
#include <QWidget>
#include <QMovie>
#include <QGraphicsScene>
#include <QTimer>
#include "item.h"
#include <QVector>
#include <ctime>
#include <cstdlib>
#include <QKeyEvent>
#include "showresult.h"

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
    void startGame();
    ~gamePage();

public slots:
    void addBit();
    void outofTime();
    void countdown();
    void keyPressEvent(QKeyEvent *hit);

private:
    Ui::gamePage *ui;
    QMovie *gif;
    QGraphicsScene *sc;
    QTimer *moveTMR;
    item *bit;
    QVector<item*> keep;
    QVector<item*> ::iterator add;
    QVector<item*> ::iterator det;
    showResult *resultP;
    int score;
    int pastTime;
};

#endif // GAMEPAGE_H
