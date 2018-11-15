#include "gameboard.hh"
#include "hex.hh"
#include "QGraphicsPolygonItem"



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
    newHex.get()->getNeighbourVector();
    int z = newHex.get()->getCoordinates().z;
    int x = newHex.get()->getCoordinates().x;
    int y = newHex.get()->getCoordinates().z;

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
    poly.setPoint(0,q-x,w-s-y);
    poly.setPoint(1,q+a-x,w-s/2-y);
    poly.setPoint(2,q+a-x,w+s/2-y);
    poly.setPoint(3,q-x,w+s-y);
    poly.setPoint(4,q-a-x,w+s/2-y);
    poly.setPoint(5,q-a-x,w-s/2-y);

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

    sceneptr_->addPolygon(poly,Peni,Brushi);

}

QGraphicsScene* GameBoard::getscene()
{
  return sceneptr_;
}
