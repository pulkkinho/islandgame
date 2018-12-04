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

class Paatti : public QGraphicsPixmapItem
{

public:
    Paatti(std::shared_ptr<Common::Transport> boat, Common::CubeCoordinate coord, QGraphicsItem* parent =NULL);

    void updateGraphics();
    void setNewCoord(Common::CubeCoordinate coordi);

    std::shared_ptr<Common::Transport> getObject();
    Common::CubeCoordinate getCoord();





private:
     std::shared_ptr<Common::Transport> paatti_;
     Common::CubeCoordinate coord_;


};

#endif // PAATTI_HH
