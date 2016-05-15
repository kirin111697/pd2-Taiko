#include "result.h"
#include "ui_result.h"

result::result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::result),
    newGame(new gamePage)

{
    ui->setupUi(this);
}

result::~result()
{
    delete ui;
}

void result::on_restartButton_clicked()
{
    this->close();
    newGame->show();
    newGame->bitmap();
    newGame->mapTMR->start(1000);
}

void result::on_exitButton_clicked()
{
    this->close();
    return;
}
