#include "gamepage.h"
#include "ui_gamepage.h"


gamePage::gamePage(QWidget *parent) :
    QWidget(parent),
    mapTMR(new QTimer),
    ui(new Ui::gamePage),
    gif(new QMovie),
    moveTMR(new QTimer),
    resultP(new showResult)
{
    ui->setupUi(this);
    gif->setFileName(":/background/imas.gif");
    ui->label->setMovie(gif);
    gif->start();
    sc=new QGraphicsScene(0,0,1280,310);
    ui->graphicsView->setScene(sc);
    connect(mapTMR,SIGNAL(timeout()),this,SLOT(outofTime()));
    srand(time(NULL));
    score=0;
    pastTime=0;
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
    connect(mapTMR,SIGNAL(timeout()),this,SLOT(addBit()));
    connect(mapTMR,SIGNAL(timeout()),this,SLOT(countdown()));
    mapTMR->start(1000);
}

void gamePage::bitmap(){//製作樂譜
    //connect(mapTMR,SIGNAL(timeout()),this,SLOT(addBit()));
    //it=keep.begin();
    int color;
    keep.clear();
    for(int i=0;i<24;i++){
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
        moveTMR->start(20);
        qDebug() << "add bit";
        ++add;
}

void gamePage::keyPressEvent(QKeyEvent *hit)
{
    if (det==keep.end())
        return;
    if ((*det)->x() >= 70){
        qDebug() << (*det)->x();
        if (hit->key() == Qt::Key_D){
            if ((*det)->getColor() == 0){
                score++;
                qDebug() << "add score";
                delete *det;
                ++det;
                qDebug() << det;
            }
            else{
                qDebug() << "wrong key";
                delete *det;
                ++det;
                qDebug() << det;
            }
        }
        else if(hit->key() == Qt::Key_K){
            if ((*det)->getColor() == 1){
                score++;
                delete *det;
                ++det;
                qDebug() << det;
            }
            else{
                delete *det;
                ++det;
                qDebug() << det;
            }
        }
    }
    else if ((*det)->x() < 70){
        qDebug() << "out of limit";
        delete *det;
        ++det;
        qDebug() << det;
    }
}

void gamePage::outofTime(){
    pastTime++;
    qDebug() << pastTime;
    if(pastTime==30){
        mapTMR->stop();
        moveTMR->stop();
        this->hide();
        pastTime=0;
        sc->clear();
        resultP->show();
        resultP->result(score);
        qDebug()<<resultP->exec();
        if(resultP->exec()){
            score=0;
            this->show();
            startGame();
        }
        else{
            return;
        }
    }
}

