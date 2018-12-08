#ifndef PAATTI_HH
#define PAATTI_HH

#include <QWidget>
#include <QPainterPath>

#include "hex.hh"
#include <QPoint>
#include <QVector>
#include <QGraphicsItem>
#include <QObject>
#include "transport.hh"
#include "QGraphicsScene"

class Paatti : public QGraphicsPixmapItem
{

public:
    Paatti(std::shared_ptr<Common::Transport> boat, Common::CubeCoordinate coord, QGraphicsScene* scene, QGraphicsItem* parent =NULL);

    void updateGraphics();
    void setNewCoord(Common::CubeCoordinate coordi);

    std::shared_ptr<Common::Transport> getObject();
    Common::CubeCoordinate getCoord();
    void addToScene();





private:
     QGraphicsScene* sceneptr_;
     std::shared_ptr<Common::Transport> paatti_;
     Common::CubeCoordinate coord_;


};

#endif // PAATTI_HH
