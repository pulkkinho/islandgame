#ifndef PAATTI_HH
#define PAATTI_HH

#include <QWidget>
#include <QPainterPath>

#include "mainwindow.hh"
#include <QPoint>
#include <QVector>
#include <QGraphicsItem>
#include <QObject>

class Paatti : public QGraphicsRectItem
{

public:
    Paatti(std::shared_ptr<Common::Transport> Paatti, Common::CubeCoordinate coord,
            QGraphicsRectItem *parent = NULL);

protected:
    void paint(QPainter *painter,
                const QStyleOptionGraphicsItem *option,
                QWidget *widget);
    QRectF boundingRect() const;


private:
     std::shared_ptr<Common::Transport> paattiptr;
     Common::CubeCoordinate coord_;


};

#endif // PAATTI_HH
