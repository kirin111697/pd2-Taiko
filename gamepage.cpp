#include "gamepage.h"
#include "ui_gamepage.h"


gamePage::gamePage(QWidget *parent) :
    QWidget(parent),
    mapTMR(new QTimer),
    ui(new Ui::gamePage),
    gif(new QMovie),
    moveTMR(new QTimer)
    //resultP(new result)
{
    ui->setupUi(this);
    gif->setFileName(":/background/imas.gif");
    ui->label->setMovie(gif);
    gif->start();
    sc=new QGraphicsScene(0,0,1280,310);
    ui->graphicsView->setScene(sc);
    connect(mapTMR,SIGNAL(timeout()),this,SLOT(outofTime()));
    srand(time(NULL));
    keep.clear();
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
}

void gamePage::bitmap(){
    connect(mapTMR,SIGNAL(timeout()),this,SLOT(addBit()));
    //it=keep.begin();
}

void gamePage::addBit(){
    int color=rand()%2;
    if (keep.empty()){
        qDebug() << "add first bit";
        bit=new item(color);
        sc->addItem(bit);
        connect(moveTMR,SIGNAL(timeout()),bit,SLOT(moving()));
        moveTMR->start(20);
        keep.push_back(bit);
        it=keep.begin();
        qDebug() << it;
    }
    else{
        bit=new item(color);
        sc->addItem(bit);
        connect(moveTMR,SIGNAL(timeout()),bit,SLOT(moving()));
        moveTMR->start(20);
        keep.push_back(bit);
        qDebug() << "add bit";

    }
}

void gamePage::keyPressEvent(QKeyEvent *hit)
{
    qDebug() << "key pressed";
    //qDebug() << (*it)->x();
    if (it==keep.end())
        return;
    if ((*it)->x() > 70 && (*it)->x() < 200){
        if (hit->key() == Qt::Key_D){
            /*qDebug() << "still working";
            qDebug() << hit->key();
            qDebug() << "still working";*/
            if ((*it)->getColor() == 0){
                score++;
                qDebug() << "add score";
                delete *it;
                ++it;
                qDebug() << it;
            }
            else{
                qDebug() << "wrong key";
                delete *it;
                ++it;
                qDebug() << it;
            }
        }
        else if(hit->key() == Qt::Key_K){
            //qDebug() << "still working";
            qDebug() << hit->key();
            //qDebug() << "still working";
            if ((*it)->getColor() == 1){
                //qDebug() << "still working";
                score++;
                delete *it;
                ++it;
                qDebug() << it;
            }
            else{
                delete *it;
                ++it;
                qDebug() << it;
            }
        }
    }
    else if ((*it)->x() < 70){
        qDebug() << "out of limit";
        delete *it;
        ++it;
        qDebug() << it;
    }
    else{
        qDebug() << "too early";
    }
}

void gamePage::outofTime(){
    pastTime++;
    if(pastTime==30){
        this->close();
        pastTime=0;
        //resultP->show();
    }
}

