#ifndef KRAKEN_HH
#define KRAKEN_HH

#include <QObject>
#include <QWidget>

#include <QWidget>
#include <QPainterPath>

#include "hex.hh"
#include <QPoint>
#include <QVector>
#include <QGraphicsItem>
#include <QObject>


class kraken : public QGraphicsPixmapItem
{

public:
    kraken(std::shared_ptr<Common::Actor> kraken, Common::CubeCoordinate coord, QGraphicsItem* parent =NULL);

    void updateGraphics();
    void setNewCoord(Common::CubeCoordinate coordi);
    std::string getType();

    std::shared_ptr<Common::Actor> getActor();

    void setKraken(std::shared_ptr<Common::Actor> aktori);

    Common::CubeCoordinate getCoord();





private:
     std::shared_ptr<Common::Actor> kraken_;
     Common::CubeCoordinate coord_;


};
#endif // KRAKEN_HH
