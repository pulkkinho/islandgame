#include "paatti.hh"

#include "hexagon.hh"
#include <QtGui>
#include <iostream>
#include "QBrush"
#include "QColor"

#include <QGraphicsSceneMouseEvent>

Paatti::Paatti(std::shared_ptr<Common::Transport> Paatti,  QGraphicsRectItem *parent):QGraphicsRectItem(parent),
    paattiptr(Paatti)


{
}

QRectF Paatti::boundingRect() const
{
    return QRectF(0,0,30,30);
}


void Paatti::paint(QPainter *painter,
                      const QStyleOptionGraphicsItem *option,
                      QWidget *widget){
    painter->setBrush(Qt::darkYellow);
    painter->drawRoundedRect(0,0,30,30,5,5);
}

