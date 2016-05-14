#include "gamepage.h"
#include "ui_gamepage.h"


gamePage::gamePage(QWidget *parent) :
    QWidget(parent),
    mapTMR(new QTimer),
    ui(new Ui::gamePage),
    gif(new QMovie),
    moveTMR(new QTimer)
    {
    ui->setupUi(this);
    gif->setFileName(":/background/imas.gif");
    ui->label->setMovie(gif);
    gif->start();
    sc=new QGraphicsScene(0,0,1280,310);
    ui->graphicsView->setScene(sc);
    srand(time(NULL));
}

gamePage::~gamePage()
{
    delete ui;
    delete mapTMR;
    delete moveTMR;
    delete gif;
    delete sc;
}

void gamePage::bitmap(){
    connect(mapTMR,SIGNAL(timeout()),this,SLOT(addBit()));
    it=keep.begin();
}

void gamePage::addBit(){
    int color=rand()%2;
    bit=new item(color);
    sc->addItem(bit);
    moveTMR->start(20);
    connect(moveTMR,SIGNAL(timeout()),bit,SLOT(moving()));
    keep.push_back(bit);
}

void gamePage::keyPressEvent(QKeyEvent *hit)
{
    if (it==keep.end())
        return;
    if ((*it)->x() > 70){
        if (hit->key() == Qt::Key_D){
            if ((*it)->getColor() == 0){
                delete *it;
                ++it;
            }
        }
        else if(hit->key() == Qt::Key_K){
            if ((*it)->getColor() == 1){
                delete *it;
                ++it;
            }
        }
    }
}

