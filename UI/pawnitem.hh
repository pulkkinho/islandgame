#ifndef PAWNITEM_HH
#define PAWNITEM_HH

#include <QObject>
#include <QWidget>
#include "mainwindow.hh"

#include <QPoint>
#include <QVector>
#include <QGraphicsItem>
#include <QObject>


class Pawnitem : public QGraphicsPixmapItem
{

public:
    Pawnitem(int playerid,int ID, Common::CubeCoordinate coord, std::shared_ptr<Common::Hex>, QGraphicsItem* parent =NULL);

    void updateGraphics();





private:
     int pawnID_;
     Common::CubeCoordinate coord_;
     std::shared_ptr<Common::Hex> hexi_;

     int playerId_;


};

#endif // PAWNITEM_HH
