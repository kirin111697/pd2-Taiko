#include "item.h"

item::item(int color)
{
    setting(color);
}

void item::setting(int color){
    switch(color){
        case 0:
            setPixmap(QPixmap(":/background/mh2_kukku.gif"));
            setPos(1280,70);
            bitColor=0;
        break;

        case 1:
            setPixmap(QPixmap(":/background/mh2_kukku-a.gif"));
            setPos(1280,70);
            bitColor=1;
        break;
    }
}
void item::moving(){
    if (x()>0){
        setPos(x()-8,y());
    }
    else{
        delete this;
    }
}

int item::getColor(){
    return bitColor;
}
