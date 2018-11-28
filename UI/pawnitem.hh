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
    Pawnitem(int ID, Common::CubeCoordinate coord, QGraphicsItem* parent =NULL);

    void updateGraphics();





private:
     int pawnID_;
     Common::CubeCoordinate coord_;

     int playerId_;


};

#endif // PAWNITEM_HH


