#ifndef READY_H
#define READY_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include "gamepage.h"

namespace Ui {
class ready;
}

class ready : public QWidget
{
    Q_OBJECT

public:
    explicit ready(QWidget *parent = 0);
    ~ready();

public slots:
    void keyPressEvent(QKeyEvent *press);

private:
    Ui::ready *ui;
    gamePage *gameP;
};

#endif // READY_H
