#include "gameboard.hh"
#include "hex.hh"
#include "QGraphicsPolygonItem"
#include "ostream"
#include <QGraphicsSceneMouseEvent>
#include "map"
#include "iostream"
#include "string"
#include "scene.hh"
#include "hexagon.hh"
#include "paatti.hh"
#include "mainwindow.hh"
#include "gamestate.hh"


GameBoard::GameBoard():
    Common::IGameBoard()

{
    sceneptr_ = new QGraphicsScene;



}

GameBoard::~GameBoard()

{

}

int GameBoard::checkTileOccupation(Common::CubeCoordinate tileCoord) const
{
    return 0;
}

bool GameBoard::isWaterTile(Common::CubeCoordinate tileCoord) const
{
    if(HexMap.at(tileCoord).get()->getPieceType() == "Water"){
        return true;
    }
    return false;
}

std::shared_ptr<Common::Hex> GameBoard::getHex(Common::CubeCoordinate hexCoord) const
{

    if (HexMap.find(hexCoord)== HexMap.end()){
        return nullptr;
    }
    return HexMap.at(hexCoord);
}

void GameBoard::addPawn(int playerId, int pawnId)
{
    std::cout << "moimoi11" << std::endl;
}

void GameBoard::addPawn(int playerId, int pawnId, Common::CubeCoordinate coord)
{

    std::cout << "moimoi22" << std::endl;
}

void GameBoard::movePawn(int pawnId, Common::CubeCoordinate pawnCoord)
{
  std::cout << "moimoi33" << std::endl;
}

void GameBoard::removePawn(int pawnId)
{
    std::cout << "moimoi44" << std::endl;
}

void GameBoard::addActor(std::shared_ptr<Common::Actor> actor, Common::CubeCoordinate actorCoord)
{

    std::cout << "moimoi55" << std::endl;
}

void GameBoard::moveActor(int actorId, Common::CubeCoordinate actorCoord)
{
  std::cout << "moimoi66" << std::endl;
}

void GameBoard::removeActor(int actorId)
{
  std::cout << "moimoi77" << std::endl;
}

void GameBoard::addHex(std::shared_ptr<Common::Hex> newHex)
{
    Common::CubeCoordinate coord = newHex.get()->getCoordinates();
    HexMap.insert(std::make_pair(coord, newHex));
    int z = newHex.get()->getCoordinates().z;
    int x = newHex.get()->getCoordinates().x;
    int y = newHex.get()->getCoordinates().y;
    std::cout << this << "matti gb addhex" << std::endl;



    Widget* super = new Widget(newHex, newHex.get()->getPieceType(), x, y, z, this, newHex.get()->getCoordinates(), runner);
    sceneptr_->addItem(super);


}

GameState* GameBoard::getstate()
{
  return state;
}

void GameBoard::addTransport(std::shared_ptr<Common::Transport> transport, Common::CubeCoordinate coord)
{
     std::cout << "Untamo" << std::endl;

    int paattimaara = 0;
    for(auto untamo : HexMap){

        if( untamo.second.get()->getCoordinates().x == coord.x && untamo.second.get()->getCoordinates().y == coord.y){
            actorMap.insert(std::make_pair(transport.get()->getId(),coord));
            std::cout<< "paattikaara" << paattimaara << std::endl;
            paattimaara = paattimaara + 1;
            Paatti* superpaatti = new Paatti(transport, coord);
            sceneptr_->addItem(superpaatti);

        }
    }
}

void GameBoard::moveTransport(int id, Common::CubeCoordinate coord)
{
  std::cout << "moimoi1" << std::endl;
}

void GameBoard::removeTransport(int id)
{
    std::cout << "moimoi2" << std::endl;
}

void GameBoard::drawHex(std::shared_ptr<Common::Hex> newHex)
{
    QPolygon poly = getPolygon(newHex);

    //std::cout << poly[1].x() << std::endl;

    QPen Peni;
    QBrush Brushi;
    std::string tyyppi = newHex.get()->getPieceType();
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


}

QGraphicsScene* GameBoard::getscene()
{
  return sceneptr_;
}


std::shared_ptr<Common::IGameRunner> GameBoard::getrunner()
{

    std::cout << this << "getrunneRII" << std::endl;
    std::cout << runner << "getrunneRII" << std::endl;
  return runner;
}

void GameBoard::setrunner(std::shared_ptr<Common::IGameRunner> runneri)
{
  runner = runneri;

  std::cout << this << "setrunner board" << std::endl;
  std::cout << runner << " setrunner runner" << std::endl;
}

Common::CubeCoordinate GameBoard::findClickedHex(int clickX, int clickY)
{
    for ( const auto& mauri : HexMap){
        std::cout << "huu"  << std::endl;
        std::cout << getHex(mauri.first).get()->getCoordinates().y << std::endl;
       // if (wasClicked(getHex(hexi), clickX, clickY) == true){
        //    return hexi;
        }
       // }

}



bool GameBoard::wasClicked(std::shared_ptr<Common::Hex> hexiptr, int clickX, int clickY)
{
    std::cout << "wasclicked" << std::endl;
    //haetaan polygoni jotta voidaan tarkastella sen pisteitä
    QPolygon poly = getPolygon(hexiptr);
    //kulmakerroin
    int kk = 1/sqrt(3);
    //tarkistetaan onko klikkaus hexin ympärille piirretyn kuvitteellisen suorakulmion sisällä
    if(poly[0].y() < clickY && poly[3].y() > clickY && poly[4].x() < clickX &&
            poly[2].x() > clickX){
        //tarkistetaan, onko klikkaus hexin sisällä tarkastelemalla vielä
        //klikkauksen y-koordinaatin suhdetta hexin vinojen sivujen
        //muodostamien suorien yhtälöihin.
        //Suoran yhtälö y = kk*x - kk*x0 +y0,
        //missä x = clickX, y = clickY, x0 ja y0 ovat QPolygonin pisteitä
        if(clickY < kk * clickX + kk * (- poly[4].x()) + poly[4].y() &&
           clickY < - kk * clickX - kk * (- poly[3].x()) + poly[3].y() &&
           clickY > - kk * clickX - kk * (- poly[5].x()) + poly[5].y() &&
           clickY > kk * clickX + kk * (- poly[0].x()) + poly[0].y())
        {
            //Mikäli klikkaus on sekä aiemmin tarkastellun hexin ympärille
            //piirretyn neliön, että viimeisenä tarkasteltujen suorien
            //muodostaman neliön sisällä voidaan klikkauksen todeta olevan
            //hexin sisällä.
            return true;
        }
    }
    return false;
}



QPolygon GameBoard::getPolygon(std::shared_ptr<Common::Hex> newHex)
{
    int x = newHex.get()->getCoordinates().x;
    int y = newHex.get()->getCoordinates().y;
    int z = newHex.get()->getCoordinates().z;

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

    return poly;
}


//bool GameBoard::arebeachleft(){
//    for(auto untamo : HexMap){
//           std::string kantamoinen = untamo.second.get()->getPieceType();
//           if (kantamoinen == "Beach"){
//               return true;
//
//           }
//    }
//}
//
//bool GameBoard::areforestleft(){
//    for(auto untamo : HexMap){
//           std::string kantamoinen = untamo.second.get()->getPieceType();
//           if (kantamoinen == "Forest"){
//               return true;
//
//           }
//    }
//}
//
//bool GameBoard::aremountainleft(){
//    for(auto untamo : HexMap){
//           std::string kantamoinen = untamo.second.get()->getPieceType();
//           if (kantamoinen == "Mountain"){
//               return true;
//           }
//    }
//}
//
