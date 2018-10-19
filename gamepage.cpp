#include "gamepage.h"
#include "ui_gamepage.h"


gamePage::gamePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamePage),
    gif(new QMovie),
    moveTMR(new QTimer),
    mapTMR(new QTimer),
    resultP(new showResult)
{
    ui->setupUi(this);
    gif->setFileName(":/background/resources/imas.gif");
    ui->label->setMovie(gif);
    gif->start();
    sc=new QGraphicsScene(0,0,1280,310);
    ui->graphicsView->setScene(sc);
    connect(mapTMR,SIGNAL(timeout()),this,SLOT(outofTime()));
    connect(mapTMR,SIGNAL(timeout()),this,SLOT(addBit()));
    connect(mapTMR,SIGNAL(timeout()),this,SLOT(countdown()));
    srand(time(NULL));
    score=0;
    pastTime=0;
    speed=15;
}

gamePage::~gamePage()
{
    delete ui;
    delete mapTMR;
    delete moveTMR;
    delete gif;
    delete sc;
    delete resultP;
}

void gamePage::startGame(){
    bitmap();
    mapTMR->start(1000);
    ui->lcdScore->display(0);
    ui->lcdTime->display(0);
}

void gamePage::bitmap(){//製作樂譜
    int color;
    keep.clear();
    for(int i=0;i<25;i++){
        color=rand()%2;
        bit=new item(color);
        keep.push_back(bit);
    }
    add=keep.begin();
    det=keep.begin();
}

void gamePage::countdown(){
    ui->lcdTime->display(pastTime);
}

void gamePage::addBit(){
        if(add == keep.end())
            return;
        sc->addItem(*add);
        connect(moveTMR,SIGNAL(timeout()),(*add),SLOT(moving()));
        connect(*add,SIGNAL(kill()),this,SLOT(killBit()));
        moveTMR->start(speed);
        ++add;
}

void gamePage::killBit(){
    if (det != keep.end())
        ++det;
}

void gamePage::keyPressEvent(QKeyEvent *hit)
{
    if (det==keep.end())
        return;
    if ((*det)->x() < 300){
        if (hit->key() == Qt::Key_D){
            if ((*det)->getColor() == 0){
                score+=4;
                ui->lcdScore->display(score);
                delete *det;
                ++det;
            }
            else{
                delete *det;
                ++det;
            }
        }
        else if(hit->key() == Qt::Key_K){
            if ((*det)->getColor() == 1){
                score+=4;
                ui->lcdScore->display(score);
                delete *det;
                ++det;
            }
            else{
                delete *det;
                ++det;
            }
        }
    }
}

void gamePage::outofTime(){
    pastTime++;
    if(pastTime==30){
        mapTMR->stop();
        moveTMR->stop();
        pastTime=0;
        sc->clear();
        resultP->show();
        resultP->result(score);
        if(resultP->exec()){
            score=0;
            startGame();
        }
        else{
            this->close();
            return;
        }
    }
}
