#include "pawnitem.hh"

Pawnitem::Pawnitem(int ID, Common::CubeCoordinate coord, std::shared_ptr<Common::Hex> hexi, QGraphicsItem* parent):
    QGraphicsPixmapItem(parent),pawnID_(ID), coord_(coord), hexi_(hexi)


{

    updateGraphics();
}

void Pawnitem::updateGraphics()
{

    int nappuMaaraHexissa = hexi_.get()->getPawnAmount() + 1;
    int sivuskaalaaja = 20 - nappuMaaraHexissa * 10;
    int korkeusskaalaaja = nappuMaaraHexissa * 8;
    QPixmap apuna("://pawn.png");
    setPixmap(apuna.scaledToHeight(15));
    int y = coord_.x;
    int x = 2 * coord_.z + coord_.x;

    int q = 200;
    int w = 200;
    int s = 20;
    x= x * 16 * s / 20;
    y= y * s * 1.5;
    this->setPos(q-x-sivuskaalaaja,w-s-y+korkeusskaalaaja);
}

