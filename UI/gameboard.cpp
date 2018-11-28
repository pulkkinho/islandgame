#include "gameboard.hh"
#include "hex.hh"
#include "QGraphicsPolygonItem"
#include "ostream"
#include <QGraphicsSceneMouseEvent>
#include "map"
#include "iostream"
#include "string"
#include "hexagon.hh"
#include "paatti.hh"
#include "mainwindow.hh"
#include "gamestate.hh"
#include "kraken.hh"


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
    if( HexMap.find(hexCoord) != HexMap.end() ){
        return HexMap.at(hexCoord);
    }
    return nullptr;
}

void GameBoard::addPawn(int playerId, int pawnId)
{
    std::cout << "moimoi11" << std::endl;

}

void GameBoard::addPawn(int playerId, int pawnId, Common::CubeCoordinate coord)
{
           Pawnitem* apina = new Pawnitem(pawnId,coord,HexMap.at(coord));
           HexMap.at(coord).get()->addPawn(pawnMap.at(pawnId));
           sceneptr_->addItem(apina);

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



   for(auto untamo : HexMap){

       if( untamo.second.get()->getCoordinates().x == actorCoord.x && untamo.second.get()->getCoordinates().y == actorCoord.y){
          // actorMap.insert(std::make_pair(transport.get()->getId(),coord));
           kraken* superpaatti = new kraken(actor, actorCoord);
           sceneptr_->addItem(superpaatti);

       }
   }
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
    coordinates.push_back(coord);

    Widget* super = new Widget(newHex, newHex.get()->getPieceType(), x, y, z, this, newHex.get()->getCoordinates(), runner);
    sceneptr_->addItem(super);


}

GameState* GameBoard::getstate()
{
  return state;
}

void GameBoard::addTransport(std::shared_ptr<Common::Transport> transport, Common::CubeCoordinate coord)
{
    for(auto untamo : HexMap){

        if( untamo.second.get()->getCoordinates().x == coord.x && untamo.second.get()->getCoordinates().y == coord.y){
            actorMap.insert(std::make_pair(transport.get()->getId(),coord));
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


QGraphicsScene* GameBoard::getscene()
{
  return sceneptr_;
}


std::shared_ptr<Common::IGameRunner> GameBoard::getrunner()
{
  return runner;
}

std::map<Common::CubeCoordinate, std::shared_ptr<Common::Hex>> GameBoard::getHexMap(){
    return HexMap;
}

std::unordered_map<int, std::shared_ptr<Common::Pawn>> GameBoard::getpawnmap(){
    return pawnMap;
}

void GameBoard::addtopawnmap(int id, std::shared_ptr<Common::Pawn> pawnptr){
    pawnMap.insert(std::make_pair(id,pawnptr));
}



void GameBoard::setrunner(std::shared_ptr<Common::IGameRunner> runneri)
{
  runner = runneri;

}

