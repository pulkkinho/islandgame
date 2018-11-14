#include "gameboard.hh"
#include "piecefactory.hh"
#include "hex.hh"
#include "QGraphicsPolygonItem"
#include "QGraphicsScene"
#include "QPainter"



GameBoard::GameBoard():
    Common::IGameBoard()

{

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




}
