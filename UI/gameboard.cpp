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
#include "spinnerwheel.hh"
#include <stdio.h>
#include "pawn.hh"
#include "QLabel"
#include "QtWidgets"
#include "QTimer"
#include "QtCore"
#include "chrono"
#include "thread"




GameBoard::GameBoard():
    Common::IGameBoard()

{
    sceneptr_ = new QGraphicsScene;
    spinButton_ = new QPushButton("SPIN");
    spinButton_->setGeometry(-400,-40,100,50);
    spinButton_->setDisabled(true);
    sceneptr_->addWidget(spinButton_);


}

GameBoard::~GameBoard()

{

}

int GameBoard::checkTileOccupation(Common::CubeCoordinate tileCoord) const
{
    if(HexMap.at(tileCoord).get() == 0){
        return -1;
    }
    else{
        return HexMap.at(tileCoord).get()->getPawnAmount();

    }

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
    //hexmappiin pawn
    HexMap.at(coord).get()->addPawn(pawnMap.at(pawnId));
    Pawnitem* apina = new Pawnitem(playerId,pawnId,coord,HexMap.at(coord));
    //pawnitemille oikea hex
    apina->setHex(HexMap.at(coord));
    sceneptr_->addItem(apina);
    //pawnitem oikeaan positioon
    apina->updateGraphics(HexMap.at(coord).get()->getPawnAmount());
    pawnItemMap.insert(std::make_pair(pawnId, apina));
}



void GameBoard::movePawn(int pawnId, Common::CubeCoordinate pawnCoord)
{
  Common::CubeCoordinate oldCoord = pawnItemMap.at(pawnId)->getCoord();

  HexMap.at(oldCoord).get()->removePawn(pawnMap.at(pawnId));

  int counter = 1;
  int x = 0;
  while (x < HexMap.at(oldCoord).get()->getPawnAmount()){
      pawnItemMap.at(HexMap.at(oldCoord).get()->getPawns().at(x).get()->getId())->updateGraphics(x+1);
      ++x;
  }

  pawnItemMap.at(pawnId)->setNewCoord(pawnCoord);
  pawnMap.at(pawnId)->setCoordinates(pawnCoord);

  HexMap.at(pawnCoord).get()->addPawn(pawnMap.at(pawnId));

  pawnItemMap.at(pawnId)->updateGraphics(HexMap.at(pawnCoord).get()->getPawnAmount());

  moveCount = 0;

}


void GameBoard::removePawn(int pawnId)
{
    // toimiiks?

    for(std::unordered_map<int, std::shared_ptr<Common::Pawn>>::iterator it = pawnMap.begin(); it != pawnMap.end(); it++)
    {
        if((it->first) == pawnId)
        {
            pawnMap.erase(it);
            
            break;
        }
    }

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
    // toimiiks?

    for(std::map<int, Common::CubeCoordinate>::iterator it = actorMap.begin(); it != actorMap.end(); it++)
    {
        if((it->first) == actorId)
        {
            actorMap.erase(it);
            break;
        }
    }
}

void GameBoard::addHex(std::shared_ptr<Common::Hex> newHex)
{
    Common::CubeCoordinate coord = newHex.get()->getCoordinates();
    HexMap.insert(std::make_pair(coord, newHex));
    int z = newHex.get()->getCoordinates().z;
    int x = newHex.get()->getCoordinates().x;
    int y = newHex.get()->getCoordinates().y;
    coordinates.push_back(coord);

    Widget* super = new Widget(newHex, newHex.get()->getPieceType(), x, y, z, this, newHex.get()->getCoordinates());

    sceneptr_->addItem(super);


}

std::shared_ptr<GameState> GameBoard::getstate()
{
    return state;
}

std::pair<std::string, std::string> GameBoard::spinwheel()
{
    //spinbutton->isChecked()

    std::pair<std::string,std::string> result = this->getrunner().get()->spinWheel();
    std::cout<< result.first<<result.second<<" spinnaus  " <<std::endl;


    QLabel *gif_anim = new QLabel();
    gif_anim->setGeometry(-170,-90,40,40);
    QMovie *movie = new QMovie("://spinneri.gif");
    movie->setScaledSize(gif_anim->size());
    gif_anim->setMovie(movie);
    std::cout<<movie->frameCount()<<std::endl;
    movie->start();
    QGraphicsProxyWidget *proxy = sceneptr_->addWidget(gif_anim);

    bool slept = false;
    if (slept == false){
        std::chrono::seconds dura(5);
        std::this_thread::sleep_for(dura);
        slept=true;
    }





    //QTimer *kello = new QTimer();
    //kello->start(8);
    //
    //bool onko = false;
    //while(onko == false)
    //if (kello->remainingTime()){
    //    std::cout<<kello->remainingTime()<<"plaa"<<std::endl;
    //
    //}

  //  kello->start(timeout);
  //  if(kello->time() == 0){
  //      movie->stop();
  //
  //  }



    //movie->jumpToFrame(7);
    //tehhää timer, annetaan spinnerin pyörii, katotaan sit
    //mikä spinnerin antama monsteri on ja pysäytetään spinneri siihen frameen mikä osottaa sinne
    //qdialogil esitetään numero
    //movie->setPaused(true);

    std::cout<<movie->loopCount()<<std::endl;


    return result;
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
    // toimiiks?
    // pitääks tehä transportmappi?

}

void GameBoard::drawwheel(std::shared_ptr<Common::SpinnerLayout> gamewheel)
{
            spinnerwheel* superpaatti = new spinnerwheel(gamewheel);
            sceneptr_->addItem(superpaatti);

}

void GameBoard::setwheel(std::shared_ptr<Common::SpinnerLayout> wheel)
{
    wheel_=wheel;
}

QPushButton* GameBoard::getpushbutton()
{
    return spinButton_;
}

QGraphicsScene* GameBoard::getscene()
{
    return sceneptr_;
}

void GameBoard::setTargetTile(Common::CubeCoordinate coord)
{
    moveTo = coord;
    moveCount = 0;
}

void GameBoard::setMoveTile(Common::CubeCoordinate coord, int id){
    moveFrom = coord;
    moveFromId = id;
    moveCount = 1;
}

int GameBoard::getMoveFromId(){
    return moveFromId;
}

Common::CubeCoordinate GameBoard::getMoveFrom(){
    return moveFrom;
}

std::map<int, Pawnitem *> GameBoard::getPawnItemMap()
{
    return pawnItemMap;
}

void GameBoard::setState(std::shared_ptr<GameState> steitti)
{
    state = steitti;
}
int GameBoard::getMoveCount(){
    return moveCount;
}

std::shared_ptr<Common::IGameRunner> GameBoard::getrunner()
{
  return runner;
}

std::map<Common::CubeCoordinate, std::shared_ptr<Common::Hex>> GameBoard::getHexMap(){
    return HexMap;
}

std::unordered_map<int, std::shared_ptr<Common::Pawn>> GameBoard::getpawnmap(){
    for (auto masa : pawnMap){
    }
    return pawnMap;
}

void GameBoard::addtopawnmap(int id, std::shared_ptr<Common::Pawn> pawnptr){
    pawnMap.insert(std::make_pair(id,pawnptr));
}



void GameBoard::setrunner(std::shared_ptr<Common::IGameRunner> runneri)
{
  runner = runneri;

}

