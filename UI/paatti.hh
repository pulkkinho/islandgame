#ifndef PAATTI_HH
#define PAATTI_HH

#include <QWidget>
#include <QPainterPath>

#include "mainwindow.hh"
#include <QPoint>
#include <QVector>
#include <QGraphicsItem>
#include <QObject>

class Paatti : public QGraphicsPixmapItem
{

public:
    Paatti(std::shared_ptr<Common::Transport> boat, Common::CubeCoordinate coord, QGraphicsItem* parent =NULL);

    void updateGraphics();





private:
     std::shared_ptr<Common::Transport> paatti_;
     Common::CubeCoordinate coord_;


};

#endif // PAATTI_HH
