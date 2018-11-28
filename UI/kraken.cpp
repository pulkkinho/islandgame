#include "kraken.hh"
#include "hexagon.hh"
#include <QtGui>
#include <iostream>
#include "QBrush"
#include "QColor"
#include "actor.hh"
#include "actorfactory.hh"

#include <QGraphicsSceneMouseEvent>
kraken::kraken(std::shared_ptr<Common::Actor> krakeni, Common::CubeCoordinate coord, QGraphicsItem* parent):
    QGraphicsPixmapItem(parent),kraken_(krakeni), coord_(coord)


{

    kraken_.get()->getActorType();
    updateGraphics();
}

void kraken::updateGraphics()
{

    int sivuskaalaaja = 15;
    int korkeusskaalaaja = 4;

    if(kraken_.get()->getActorType()=="seamunster"){
        QPixmap laivunen("://monster.png");
        setPixmap(laivunen.scaledToHeight(35));
        korkeusskaalaaja = 2;
        sivuskaalaaja = 18;

    }

    if(kraken_.get()->getActorType()=="vortex"){
        QPixmap laivunen("://vortex.png");
        setPixmap(laivunen.scaledToHeight(45));
        sivuskaalaaja = 22;
        korkeusskaalaaja=-2;

    }

    if(kraken_.get()->getActorType()=="shark"){
        QPixmap laivunen("://shark.png");
        setPixmap(laivunen.scaledToHeight(20));
        sivuskaalaaja = 18;
        korkeusskaalaaja = 10;

    }

    if(kraken_.get()->getActorType()=="kraken"){
        QPixmap laivunen("://kraken.png");
        setPixmap(laivunen.scaledToHeight(22));
        sivuskaalaaja = 16;

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
