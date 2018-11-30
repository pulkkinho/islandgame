#include "pawnitem.hh"

Pawnitem::Pawnitem(int playerid,int ID, Common::CubeCoordinate coord, std::shared_ptr<Common::Hex> hexi, QGraphicsItem* parent):
    QGraphicsPixmapItem(parent),playerId_(playerid),pawnID_(ID), coord_(coord), hexi_(hexi)


{

    updateGraphics();
}

void Pawnitem::updateGraphics()
{

    int nappuMaaraHexissa = hexi_.get()->getPawnAmount() + 1;
    int sivuskaalaaja = 24 - nappuMaaraHexissa * 10;
    int korkeusskaalaaja = nappuMaaraHexissa * 6;
    if(playerId_ == 1){
        QPixmap apuna("://pawn1.png");
        setPixmap(apuna.scaledToHeight(15));

    }
    if(playerId_ == 2){
        QPixmap apuna("://pawn2.png");
        setPixmap(apuna.scaledToHeight(15));

    }
    if(playerId_ == 3){
        QPixmap apuna("://pawn3.png");
        setPixmap(apuna.scaledToHeight(15));

    }
    if(playerId_ == 4){
            QPixmap apuna("://pawn4.png");
            setPixmap(apuna.scaledToHeight(15));

        }
    if(playerId_ == 5){
            QPixmap apuna("://pawn5.png");
            setPixmap(apuna.scaledToHeight(15));

        }
    if(playerId_ == 6){
            QPixmap apuna("://pawn6.png");
            setPixmap(apuna.scaledToHeight(15));

        }
    int y = coord_.x;
    int x = 2 * coord_.z + coord_.x;

    int q = 200;
    int w = 200;
    int s = 20;
    x= x * 16 * s / 20;
    y= y * s * 1.5;
    this->setPos(q-x-sivuskaalaaja,w-s-y+korkeusskaalaaja);
}




