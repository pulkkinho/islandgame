#include "pawnitem.hh"
#include "iostream"
#include "gameboard.hh"
Pawnitem::Pawnitem(int playerid,int ID, Common::CubeCoordinate coord, std::shared_ptr<Common::Hex> hexi,
                   QGraphicsScene* scene, QGraphicsItem* parent):
    QGraphicsPixmapItem(parent),playerId_(playerid),pawnID_(ID), coord_(coord), hexi_(hexi), sceneptr_(scene)

{

}

void Pawnitem::setNewCoord(Common::CubeCoordinate newCoord)
{
    coord_ = newCoord;
}

void Pawnitem::setHex(std::shared_ptr<Common::Hex> hex)
{
    hexi_ = hex;
}

Common::CubeCoordinate Pawnitem::getCoord()
{
    return coord_;
}

void Pawnitem::addToScene()
{
    sceneptr_->addItem(this);
}

void Pawnitem::updateGraphics(int slotti)
{
    int sivuskaalaaja = 24 - slotti * 10;
    int korkeusskaalaaja = slotti * 6;
    if(playerId_ == 1){
        QPixmap pawnImage("://pawn1.png");
        setPixmap(pawnImage.scaledToHeight(15));

    }
    if(playerId_ == 2){
        QPixmap pawnImage("://pawn2.png");
        setPixmap(pawnImage.scaledToHeight(15));

    }
    if(playerId_ == 3){
        QPixmap pawnImage("://pawn3.png");
        setPixmap(pawnImage.scaledToHeight(15));

    }
    if(playerId_ == 4){
            QPixmap pawnImage("://pawn4.png");
            setPixmap(pawnImage.scaledToHeight(15));

        }
    if(playerId_ == 5){
            QPixmap pawnImage("://pawn5.png");
            setPixmap(pawnImage.scaledToHeight(15));

        }
    if(playerId_ == 6){
            QPixmap pawnImage("://pawn6.png");
            setPixmap(pawnImage.scaledToHeight(15));

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
