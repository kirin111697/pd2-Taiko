#include "nextpage.h"
#include "ui_nextpage.h"
#include <QDebug>

nextPage::nextPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nextPage),
    gameP(new gamePage)
{
    ui->setupUi(this);
}

nextPage::~nextPage()
{
    delete ui;
}

void nextPage::keyPressEvent(QKeyEvent *press)
{
    qDebug() << press->key();
    this->hide();
    gameP->show();
    gameP->startGame();
    //gameP->bitmap();
    //gameP->moveTMR->start(30);

    /*if (press->key() == Qt::Key_F){
        qDebug() << press->key();
    }*/
}
