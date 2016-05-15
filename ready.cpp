#include "ready.h"
#include "ui_ready.h"

ready::ready(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ready),
    gameP(new gamePage)
{
    ui->setupUi(this);
}

ready::~ready()
{
    delete ui;
}

void ready::keyPressEvent(QKeyEvent *press)
{
    this->hide();
    gameP->show();
    gameP->startGame();

}
