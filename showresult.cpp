#include "showresult.h"
#include "ui_showresult.h"

showResult::showResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showResult)
{
    ui->setupUi(this);
}

showResult::~showResult()
{
    delete ui;
}

void showResult::result(int score){
    ui->lcdNumber->display(score);
}
