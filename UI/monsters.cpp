#include "monsters.hh"
#include "hexagon.hh"
#include <QtGui>
#include <iostream>
#include "QBrush"
#include "QColor"
#include "actor.hh"
#include "actorfactory.hh"
#include "QApplication"

monsters::monsters(std::shared_ptr<Common::Actor> monstersi,
                   Common::CubeCoordinate coord,
                   QGraphicsScene* scene, QGraphicsItem* parent):
                   QGraphicsPixmapItem(parent),
                   monsters_(monstersi),
                   coord_(coord),
                   sceneptr_(scene)

{
    monsters_.get()->getActorType();
    updateGraphics();
}

void monsters::updateGraphics()
{
    int sivuskaalaaja = 15;
    int korkeusskaalaaja = 4;

    if(monsters_.get()->getActorType()=="seamunster"){
        QPixmap laivunen("://monster.png");
        setPixmap(laivunen.scaledToHeight(25));
        korkeusskaalaaja = 5;
        sivuskaalaaja = 15;
    }

    if(monsters_.get()->getActorType()=="vortex"){
        QPixmap laivunen("://vortex.png");
        setPixmap(laivunen.scaledToHeight(10));
        sivuskaalaaja = 15;
        korkeusskaalaaja=12;
    }

    if(monsters_.get()->getActorType()=="shark"){
        QPixmap laivunen("://shark.png");
        setPixmap(laivunen.scaledToHeight(25));
        sivuskaalaaja = 18;
        korkeusskaalaaja = 10;
    }

    if(monsters_.get()->getActorType()=="kraken"){
        QPixmap laivunen("://kraken.png");
        setPixmap(laivunen.scaledToHeight(30));
        sivuskaalaaja = 10;
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

void monsters::setNewCoord(Common::CubeCoordinate coordi)
{
    coord_ = coordi;
}

std::string monsters::getType()
{
    return monsters_.get()->getActorType();
    std::cout << monsters_.get()->getActorType() << "actortype" << std::endl;
}

std::shared_ptr<Common::Actor> monsters::getActor()
{
    return monsters_;
}

void monsters::setmonsters(std::shared_ptr<Common::Actor> aktori)
{
    monsters_ = aktori;
}

Common::CubeCoordinate monsters::getCoord()
{
    return coord_;
}

void monsters::addToScene()
{
    sceneptr_->addItem(this);
}
