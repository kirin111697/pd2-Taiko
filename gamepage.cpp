#include "gamepage.h"
#include "ui_gamepage.h"


gamePage::gamePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamePage),
    gif(new QMovie),
    note(new item),
    timer(new QTimer)
{
    ui->setupUi(this);
    gif->setFileName(":/background/imas.gif");
    ui->label->setMovie(gif);
    gif->start();
    sc=new QGraphicsScene(0,0,1280,310);
    ui->graphicsView->setScene(sc);
    sc->addItem(note);
    connect(timer,SIGNAL(timeout()),note,SLOT(moving()));
}

gamePage::~gamePage()
{
    delete ui;
    delete sc;
}

/*gamePage::bitmap(){

}*/
