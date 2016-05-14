#ifndef NEXTPAGE_H
#define NEXTPAGE_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QTimer>
#include "gamepage.h"

namespace Ui {
class nextPage;
}

class nextPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit nextPage(QWidget *parent = 0);
    ~nextPage();

public slots:
    void keyPressEvent(QKeyEvent *press);

private:
    Ui::nextPage *ui;
    gamePage *gameP;
    QTimer *mapTMR;
};

#endif // NEXTPAGE_H
