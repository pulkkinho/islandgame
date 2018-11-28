#ifndef KRAKEN_HH
#define KRAKEN_HH

#include <QObject>
#include <QWidget>

#include <QWidget>
#include <QPainterPath>

#include "mainwindow.hh"
#include <QPoint>
#include <QVector>
#include <QGraphicsItem>
#include <QObject>


class kraken : public QGraphicsPixmapItem
{

public:
    kraken(std::shared_ptr<Common::Actor> kraken, Common::CubeCoordinate coord, QGraphicsItem* parent =NULL);

    void updateGraphics();





private:
     std::shared_ptr<Common::Actor> kraken_;
     Common::CubeCoordinate coord_;


};
#endif // KRAKEN_HH
