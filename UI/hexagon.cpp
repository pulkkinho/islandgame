#include "hexagon.hh"
#include <QtGui>
#include <iostream>
#include "QBrush"

#include <QGraphicsSceneMouseEvent>

Widget::Widget(std::shared_ptr<Common::Hex> Hexi, std::string Tyyppi, int x, int y, int z,
               GameBoard* board, Common::CubeCoordinate coord, std::shared_ptr<Common::IGameRunner> runner,
               QGraphicsPolygonItem *parent):
    QGraphicsPolygonItem(parent), hexptr(Hexi), tyyppi(Tyyppi), x_(x), y_(y),
    z_(z), board_(board), coord_(coord), runnerptr(runner)
{

    Pressed = false;
    flip = false;
}

void Widget::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{

    if (Pressed == true){

        return;
    }
    int y = x_;
    int x = 2 * z_ + x_;

    int q = 200;
    int w = 200;
    int s = 20;
    x= x * 16 * s / 20;
    y= y * s * 1.5;
    int a = sqrt(3)*(s/2);
    QGraphicsItem::mouseDoubleClickEvent(event);


    QPoint clickPosition = event->scenePos().toPoint();
    QPoint keke(clickPosition.x(),clickPosition.y());

        if(poly.containsPoint(keke,Qt::WindingFill)){
            if(flip == false){
            if(poly[0].y() < clickPosition.y() && poly[3].y() > clickPosition.y() && poly[1].x()-2 > clickPosition.x() &&
                    poly[5].x()+2 < clickPosition.x()){
                if(tyyppi == "Water"){

                }
                if(tyyppi == "Coral"){
                    return;
                }

                tyyppi = "Water";
                flip =  true;
                Pressed = true;
                board_->getrunner()->flipTile(coord_);
                return;
            }

        }else Pressed = false;
    } else Pressed = false;
}

QRectF Widget::boundingRect() const{
    int y = x_;
    int x = 2 * z_ + x_;

    int q = 200;
    int w = 200;
    int s = 20;
    x= x * 16 * s / 20;
    y= y * s * 1.5;
    int a = sqrt(3)*(s/2);
    return QRectF(q-a-x,w-s-y, 40,40);
}

void Widget::paint(QPainter *painter,
                      const QStyleOptionGraphicsItem *option,
                      QWidget *widget){


    int y = x_;
    int x = 2 * z_ + x_;

    int q = 200;
    int w = 200;
    int s = 20;
    x= x * 16 * s / 20;
    y= y * s * 1.5;
    int a = sqrt(3)*(s/2);


    //lähtee alimmasta kulmasta vastapäivään
    poly << QPoint(q-x,w-s-y);
    poly << QPoint(q+a-x,w-s/2-y);
    poly << QPoint(q+a-x,w+s/2-y);
    poly << QPoint(q-x,w+s-y);
    poly << QPoint(q-a-x,w+s/2-y);
    poly << QPoint(q-a-x,w-s/2-y);
    QBrush Brushi;
    if (tyyppi == "Forest"){
        Brushi.setColor((Qt::green));
    }
    if(tyyppi == "Mountain"){
        Brushi.setColor(((Qt::gray)));
    }
    if(tyyppi == "Peak"){
        Brushi.setColor(((Qt::black)));
    }
    if(tyyppi == "Water"){
        Brushi.setColor(((Qt::blue)));
    }
    if(tyyppi == "Coral"){
        Brushi.setColor(((Qt::magenta)));
    }
    if(tyyppi == "Beach"){
        Brushi.setColor(((Qt::yellow)));
    }
    Brushi.setStyle(Qt::SolidPattern);

    if (Pressed == true){
    Brushi.setColor(Qt::blue);
    }
    this->setBrush(Brushi);
    this->setPolygon(poly);

    painter->setBrush(Brushi.color());
    painter->drawPolygon(poly,Qt::WindingFill);
}
