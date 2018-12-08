#ifndef MONSTERS_HH
#define MONSTERS_HH

#include <QObject>
#include <QWidget>

#include <QWidget>
#include <QPainterPath>

#include "hex.hh"
#include <QPoint>
#include <QVector>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsScene>


class monsters : public QGraphicsPixmapItem
{

public:
    monsters(std::shared_ptr<Common::Actor> monsters, Common::CubeCoordinate coord, QGraphicsScene* scene, QGraphicsItem* parent =NULL);

    void updateGraphics();
    void setNewCoord(Common::CubeCoordinate coordi);
    std::string getType();

    std::shared_ptr<Common::Actor> getActor();

    void setmonsters(std::shared_ptr<Common::Actor> aktori);

    Common::CubeCoordinate getCoord();

    void addToScene();





private:

     QGraphicsScene* sceneptr_;
     std::shared_ptr<Common::Actor> monsters_;
     Common::CubeCoordinate coord_;


};
#endif // MONSTERS_HH
