#include "paatti.hh"

#include "hexagon.hh"
#include <QtGui>
#include <iostream>
#include "QBrush"
#include "QColor"

#include <QGraphicsSceneMouseEvent>

Paatti::Paatti(std::shared_ptr<Common::Transport> Paatti, Common::CubeCoordinate coord,  QGraphicsRectItem *parent):QGraphicsRectItem(parent),
    paattiptr(Paatti), coord_(coord)


{
}

QRectF Paatti::boundingRect() const
{
    return QRectF(coord_.x,coord_.y,20,20);
}


void Paatti::paint(QPainter *painter,
                      const QStyleOptionGraphicsItem *option,
                      QWidget *widget){

    int y = coord_.x;
    int x = 2 * coord_.z + coord_.x;

    int q = 200;
    int w = 200;
    int s = 20;
    x= x * 16 * s / 20;
    y= y * s * 1.5;
    int a = sqrt(3)*(s/2);
    painter->setBrush(Qt::red);
    QPolygon vene;
    vene << QPoint(q+a-x-7,w-s/2-y+10);

    vene << QPoint(q+a-x-10,w+s/2-y);
    vene << QPoint(q-a-x+10,w+s/2-y);
    vene << QPoint(q-a-x+7,w-s/2-y+10);
    painter->drawPolygon(vene, Qt::WindingFill);
}

