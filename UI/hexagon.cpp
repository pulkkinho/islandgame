#include "hexagon.hh"
#include <QtGui>
#include <iostream>
#include "QBrush"

#include <QGraphicsSceneMouseEvent>

Widget::Widget(std::shared_ptr<Common::Hex> Hexi, std::string Tyyppi, int x, int y, int z,
               GameBoard board, Common::CubeCoordinate coord, std::shared_ptr<Common::IGameRunner> runner,
               QGraphicsPolygonItem *parent):
    QGraphicsPolygonItem(parent), hexptr(Hexi), tyyppi(Tyyppi), x_(x), y_(y),
    z_(z), board_(board), coord_(coord), runnerptr(runner)
{
    Pressed = false;
    flip = true;
}
void Widget::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{

    int y = x_;
    int x = 2 * z_ + x_;

    int q = 200;
    int w = 200;
    int s = 20;
    x= x * 16 * s / 20;
    y= y * s * 1.5;
    int a = sqrt(3)*(s/2);
    QGraphicsItem::mouseDoubleClickEvent(event);

    if (Pressed == false){
    Pressed = true;}
    else {Pressed = false;}
    QPoint clickPosition = event->scenePos().toPoint();
    std::cout << clickPosition.x() << " " << clickPosition.y() << std::endl;
    QPoint keke(clickPosition.x(),clickPosition.y());

        if(poly.containsPoint(keke,Qt::WindingFill)){
            int kk = 1/sqrt(3);
            //tarkistetaan onko klikkaus hexin ympärille piirretyn kuvitteellisen suorakulmion sisällä
            if(poly[0].y() < clickPosition.y() && poly[3].y() > clickPosition.y() && poly[1].x()-2 > clickPosition.x() &&
                    poly[5].x()+2 < clickPosition.x()){
                if(tyyppi == "Water"){
                    std::cout << "KONEKIVÄÄRI?" << std::endl;

                }
                if(tyyppi == "Coral"){
                    std::cout << "KORALLIRIUTTA?" << std::endl;
                    Pressed = false;
                    return;
                }
                std::cout << "lampeen?" << std::endl;
                Pressed = true;
                tyyppi = "Water";
                //Common::Hex masa;
                //masa = hexptr.get();
                //board_->getrunner().get()->flipTile(hexptr.get()->getCoordinates());
                std::cout << runnerptr.get() << std::endl;
                runnerptr.get()->flipTile(coord_);
                update();
                //tarkistetaan, onko klikkaus hexin sisällä tarkastelemalla vielä
                //klikkauksen y-koordinaatin suhdetta hexin vinojen sivujen
                //muodostamien suorien yhtälöihin.
                //Suoran yhtälö y = kk*x - kk*x0 +y0,
                //missä x = clickPosition.x(), y = clickPosition.y(), x0 ja y0 ovat QPolygonin pisteitä
            //    if(clickPosition.y() > (kk * clickPosition.x() + kk * (- poly[5].x()) + poly[5].y()) &&
            //       clickPosition.y() > (- kk * clickPosition.x() - kk * (- poly[1].x()) + poly[1].y()) &&
            //       clickPosition.y() < (kk * clickPosition.x() + kk * (- poly[2].x()) + poly[2].y()) &&
            //       clickPosition.y() < (- kk * clickPosition.x() - kk * (- poly[3].x()) + poly[3].y())){
            //            std::cout << "Oi Suomi on!" << std::endl;
            //            Pressed = true;
            //            tyyppi = "Water";
            //            update();
            //
            //}
        }else Pressed = false;
            update();
    } else Pressed = false;
        update();
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

    if (Pressed == true && flip == true){
    Brushi.setColor(Qt::blue);
    }
    this->setBrush(Brushi);
    this->setPolygon(poly);

    painter->setBrush(Brushi.color());
    painter->drawPolygon(poly,Qt::WindingFill);
}
