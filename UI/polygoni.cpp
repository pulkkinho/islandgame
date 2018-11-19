#include "polygoni.hh"
#include <QGraphicsSceneMouseEvent>
#include "QGraphicsScene"
#include "ostream"
#include "QPainter"

Polygoni::Polygoni(std::shared_ptr<Common::Hex> Hex, QGraphicsScene* sceneptr):
    QGraphicsPolygonItem(),
    sceneptr_(sceneptr),
    Hex_(Hex)

{       QPainter p;
        int z = Hex.get()->getCoordinates().z;
        int x = Hex.get()->getCoordinates().x;
        int y = Hex.get()->getCoordinates().z;

        //muutetaan xyz-koordinaatit xy-muotoon:
        y = x;
        x = 2 * z + x;

        int q = 400;
        int w = 400;
        int s = 20;
        x= x * 16 * s / 20;
        y= y * s * 1.5;
        int a = sqrt(3)*(s/2);
                QPolygon poly(6);
        //lähtee alimmasta kulmasta vastapäivään
        poly.setPoint(0,q-x,w-s-y);
        poly.setPoint(1,q+a-x,w-s/2-y);
        poly.setPoint(2,q+a-x,w+s/2-y);
        poly.setPoint(3,q-x,w+s-y);
        poly.setPoint(4,q-a-x,w+s/2-y);
        poly.setPoint(5,q-a-x,w-s/2-y);
        QPen Peni;
        QBrush Brushi;
        std::string tyyppi = Hex.get()->getPieceType();
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
        //this->setPolygon(poly);



        sceneptr->addPolygon(poly, Peni, Brushi);
      //  sceneptr->addWidget(poly);



}

Polygoni::~Polygoni()
{

}

void Polygoni::setRunnerptr(std::shared_ptr<Common::IGameRunner> runneri)
{
}

void Polygoni::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{

    QGraphicsPolygonItem::mouseDoubleClickEvent(event);
    std::cout << "oi suomi on" << std::endl;

    QPoint clickPosition = event->scenePos().toPoint();
    emit mouseClick(clickPosition.x(), clickPosition.y());
}

void Polygoni::click(int clickX, int clickY)
{
    std::cout << "Click coordinates: x=" << clickX << " y=" << clickY << std::endl;
  //  std::cout << board_->findClickedHex(clickX,clickY);
                 //.get()->getCoordinates().x << std::endl;
  //  runnerptr_.get()->flipTile(board_->findClickedHex(clickX,clickY).get()->getCoordinates());



}
