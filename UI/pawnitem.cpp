#include "pawnitem.hh"

Pawnitem::Pawnitem(int ID, Common::CubeCoordinate coord, QGraphicsItem* parent):
    QGraphicsPixmapItem(parent),pawnID_(ID), coord_(coord)


{

    std::cout<<"APINOITA"<<std::endl;
    updateGraphics();
}

void Pawnitem::updateGraphics()
{
    QPixmap apuna("://pawn.png");
    setPixmap(apuna.scaledToHeight(20));
    int y = coord_.x+20;
    int x = 2 * coord_.z + coord_.x+20;

    int s = 2;
    x= x * 16 * s / 20;
    y= y * s * 1.5;

    this->setPos(y*10,x*10);
}

