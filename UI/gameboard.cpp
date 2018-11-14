#include "gameboard.hh"
#include "piecefactory.hh"
#include "hex.hh"
#include "QGraphicsPolygonItem"
#include "QGraphicsScene"
#include "QPainter"



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
    return true;
}

std::shared_ptr<Common::Hex> GameBoard::getHex(Common::CubeCoordinate hexCoord) const
{

    std::cout <<"moimoi" << std::endl;
    if (HexMap.find(hexCoord)== HexMap.end()){
        return nullptr;
    }
    return HexMap.at(hexCoord);
}

void GameBoard::addPawn(int playerId, int pawnId)
{
    std::cout << "moimoi" << std::endl;
}

void GameBoard::addPawn(int playerId, int pawnId, Common::CubeCoordinate coord)
{

    std::cout << "moimoi" << std::endl;
}

void GameBoard::movePawn(int pawnId, Common::CubeCoordinate pawnCoord)
{
  std::cout << "moimoi" << std::endl;
}

void GameBoard::removePawn(int pawnId)
{
    std::cout << "moimoi" << std::endl;
}

void GameBoard::addActor(std::shared_ptr<Common::Actor> actor, Common::CubeCoordinate actorCoord)
{

    std::cout << "moimoi" << std::endl;
}

void GameBoard::moveActor(int actorId, Common::CubeCoordinate actorCoord)
{
  std::cout << "moimoi" << std::endl;
}

void GameBoard::removeActor(int actorId)
{
  std::cout << "moimoi" << std::endl;
}

void GameBoard::addHex(std::shared_ptr<Common::Hex> newHex)
{
    Common::CubeCoordinate coord = newHex.get()->getCoordinates();
    HexMap.insert({coord, newHex});
    drawHex(newHex);

}

void GameBoard::addTransport(std::shared_ptr<Common::Transport> transport, Common::CubeCoordinate coord)
{
  std::cout << "moimoi" << std::endl;
}

void GameBoard::moveTransport(int id, Common::CubeCoordinate coord)
{
  std::cout << "moimoi" << std::endl;
}

void GameBoard::removeTransport(int id)
{
    std::cout << "moimoi" << std::endl;
}

void GameBoard::drawHex(std::shared_ptr<Common::Hex> newHex)
{
    std::cout << "moim7oi" << std::endl;
    newHex.get()->getNeighbourVector();
    int z = newHex.get()->getCoordinates().z*50;
    int x = newHex.get()->getCoordinates().x*50;
    int y = newHex.get()->getCoordinates().y*50;
    QPolygon poly(6);
    poly.setPoint(0, 625-x, 650+y);
    poly.setPoint(1, 650-x, 637.5+y);
    poly.setPoint(2, 650-x, 612.5+y);
    poly.setPoint(3, 625-x, 600+y);
    poly.setPoint(4, 600-x, 612.5+y);
    poly.setPoint(5, 600-x, 637.5+y);
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
        Brushi.setColor(((Qt::cyan)));
    }

    if(tyyppi == "Beach"){
        Brushi.setColor(((Qt::yellow)));
    }
    Brushi.setStyle(Qt::SolidPattern);
    sceneptr_->addPolygon(poly,Peni,Brushi);

}

QGraphicsScene* GameBoard::getscene()
{
  return sceneptr_;
}
