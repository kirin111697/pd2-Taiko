#include "item.h"

item::item()
{
    setting();
}

void item::setting(){
    setPixmap(QPixmap(":/background/mh2_kukku-a.gif"));
    setPos(1280,70);
}
void item::moving(){
    if (x()>50){
        setPos(x()-8,y());
    }
    else{
        delete this;
    }
}
