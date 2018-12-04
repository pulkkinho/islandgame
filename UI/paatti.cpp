#include "paatti.hh"

#include <QtGui>
#include <iostream>
#include "QBrush"
#include "QColor"

#include <QGraphicsSceneMouseEvent>

Paatti::Paatti(std::shared_ptr<Common::Transport> Paatti, Common::CubeCoordinate coord, QGraphicsItem* parent):
    QGraphicsPixmapItem(parent),paatti_(Paatti), coord_(coord)


{
    updateGraphics();
}

void Paatti::updateGraphics()
{

    int sivuskaalaaja = 15;
    int korkeusskaalaaja = 7;

    if(paatti_.get()->getTransportType()=="dolphin"){
        QPixmap laivunen("://dolphin.png");
        setPixmap(laivunen.scaledToHeight(20));

    }
    else{
        QPixmap laivunen("://vene.png");
        setPixmap(laivunen.scaledToHeight(30));
        sivuskaalaaja = 20;

    }
    int y = coord_.x;
    int x = 2 * coord_.z + coord_.x;

    int q = 200;
    int w = 200;
    int s = 20;
    x= x * 16 * s / 20;
    y= y * s * 1.5;
    this->setPos(q-x-sivuskaalaaja,w-s-y+korkeusskaalaaja);
}

void Paatti::setNewCoord(Common::CubeCoordinate coordi)
{
    coord_ = coordi;
}

std::shared_ptr<Common::Transport> Paatti::getObject()
{
    return paatti_;
}

Common::CubeCoordinate Paatti::getCoord()
{
    return coord_;
}

