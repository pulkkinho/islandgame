#ifndef PAWNITEM_HH
#define PAWNITEM_HH

#include <QObject>
#include <QWidget>

#include <QPoint>
#include <QVector>
#include <QGraphicsItem>
#include "QGraphicsPixmapItem"
#include "hex.hh"

#include "gamestate.hh"


class Pawnitem : public QGraphicsPixmapItem
{

public:
    Pawnitem(int playerid,int ID, Common::CubeCoordinate coord, std::shared_ptr<Common::Hex>, QGraphicsItem* parent =NULL);

    void updateGraphics(int slotti);
    void setNewCoord(Common::CubeCoordinate newCoord);
    void setHex(std::shared_ptr<Common::Hex> hex);
    Common::CubeCoordinate getCoord();




private:
    int playerId_;
     int pawnID_;
     Common::CubeCoordinate coord_;
     std::shared_ptr<Common::Hex> hexi_;

     bool vbMousePressed;


};

#endif // PAWNITEM_HH
