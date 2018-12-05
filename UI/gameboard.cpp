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
#include "monsters.hh"
#include "spinnerwheel.hh"
#include <stdio.h>
#include "pawn.hh"
#include "QLabel"
#include "QtWidgets"
#include "QTimer"
#include "spinneranimation.hh"



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

    int x = 0;
    while (x < HexMap.at(oldCoord).get()->getPawnAmount()){
        pawnItemMap.at(HexMap.at(oldCoord).get()->getPawns().at(x).get()->getId())->updateGraphics(x+1);
        ++x;
    }
    if(HexMap.at(pawnCoord).get()->getTransports().size() > 0){
        HexMap.at(pawnCoord).get()->getTransports().at(0).get()->addPawn(pawnMap.at(pawnId));
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
            sceneptr_->removeItem(pawnItemMap.at(pawnId));
            
            break;
        }
    }

}

void GameBoard::addActor(std::shared_ptr<Common::Actor> actor, Common::CubeCoordinate actorCoord)
{

    for(auto untamo : HexMap){

        if( untamo.second.get()->getCoordinates().x == actorCoord.x && untamo.second.get()->getCoordinates().y == actorCoord.y){
            actorMap.insert(std::make_pair(actor.get()->getId(), actorCoord));
            monsters* superpaatti = new monsters(actor, actorCoord);
            superpaatti->setmonsters(actor);
            actor.get()->addHex(HexMap.at(actorCoord));
            sceneptr_->addItem(superpaatti);
            std::cout << actor << " actor gb" << std::endl;
         std::cout << actor.get()->getId() << std::endl;
            monstersMap.insert(std::make_pair(actor.get()->getId(), superpaatti));

        }
    }
}

void GameBoard::moveActor(int actorId, Common::CubeCoordinate actorCoord)
{
    std::vector<std::shared_ptr<Common::Transport>> transportit = HexMap.at(actorCoord).get()->getTransports();

    std::cout << transportit.size() << "transportit.ziseee" << std::endl;
    monstersMap.at(actorId)->getActor().get()->addHex(HexMap.at(actorCoord));
    std::cout << transportit.size() << "transportit.ziseee" << std::endl;
    if(transportit.size() != 0){
        sceneptr_->removeItem(paattiMap.at(actorId));
        paattiMap.at(HexMap.at(actorCoord).get()->getTransports().at(0).get()->getId())->setOpacity(1);
        paattiMap.erase(actorId);
    }

    monstersMap.at(actorId)->getActor().get()->doAction();
    monstersMap.at(actorId)->setNewCoord(actorCoord);
    monstersMap.at(actorId)->updateGraphics();
}

void GameBoard::removeActor(int actorId)
{
    // toimiiks?

    for(std::map<int, Common::CubeCoordinate>::iterator it = actorMap.begin(); it != actorMap.end(); it++)
    {
        if((it->first) == actorId)
        {
            actorMap.erase(it);
            sceneptr_->removeItem(monstersMap.at(actorId));
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

    spinneranimation* spinner = new spinneranimation(result.first,result.second);

    sceneptr_->addWidget(spinner);

    QLabel *kakko = new QLabel();

    QString menejo =QString::fromStdString( result.second);
    kakko->setText("Amount to move:   "+menejo);
    kakko->setGeometry(-250,50,150,25);
    sceneptr_->addWidget(kakko);
    //std::cout<< result.first<<result.second<<" spinnaus  " <<std::endl;
    //
    //
    //QLabel *gif_anim = new QLabel();
    //gif_anim->setGeometry(-170,-90,40,40);
    //QMovie *movie = new QMovie("://spinneri.gif");
    //movie->setScaledSize(gif_anim->size());
    //gif_anim->setMovie(movie);
    //std::cout<<movie->frameCount()<<std::endl;
    //movie->start();
    //
    //
    //QGraphicsProxyWidget *proxy = sceneptr_->addWidget(gif_anim);


    spinnerResult = result;

    for (auto aktor : monstersMap){
        if(aktor.second->getType() == spinnerResult.first){
            return result;
        }
    }
    nextTurn();
}

void GameBoard::addTransport(std::shared_ptr<Common::Transport> transport, Common::CubeCoordinate coord)
{
    std::string tyyppi = transport.get()->getTransportType();
    for(auto untamo : HexMap){

        if( untamo.second.get()->getCoordinates().x == coord.x && untamo.second.get()->getCoordinates().y == coord.y){



            actorMap.insert(std::make_pair(transport.get()->getId(),coord));
            Paatti* superpaatti = new Paatti(transport, coord);
            sceneptr_->addItem(superpaatti);
            HexMap.at(coord).get()->addTransport(transport);

            paattiMap.insert(std::make_pair(transport.get()->getId(), superpaatti));
            //lisätään mahdolliset jo hexissä olleet pawnit transporttiin
            if(HexMap.at(coord).get()->getPawnAmount() > 0){
                for(auto x : HexMap.at(coord).get()->getPawns()){
                    transport.get()->addPawn(x);
                }
            }
        }
    }
}

void GameBoard::moveTransport(int id, Common::CubeCoordinate coord)
{
    paattiMap.at(id)->getObject().get()->addHex(HexMap.at(coord));
    HexMap.at(coord).get()->removeTransport(paattiMap.at(id)->getObject());
    HexMap.at(coord).get()->addTransport(paattiMap.at(id)->getObject());
    paattiMap.at(id)->setNewCoord(coord);
    paattiMap.at(id)->updateGraphics();
}

void GameBoard::removeTransport(int id)
{
    std::cout << "removetransport" << std::endl;
    paattiMap.erase(id);
    sceneptr_->removeItem(paattiMap.at(id));

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

void GameBoard::setLabel(Common::GamePhase, int)
{

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

std::pair<std::string, std::string> GameBoard::getSpinnerResult()
{
    return spinnerResult;
}

int GameBoard::getActorId(Common::CubeCoordinate coord, std::string tyyppi)
{
    for (auto actori : monstersMap){
        if(actori.second->getType() == tyyppi && actori.second->getCoord() == coord){
            return actori.first;
        }
    }
}

int GameBoard::getPaattiId(Common::CubeCoordinate coord)
{
    for (auto paatti : paattiMap){
        if(paatti.second->getCoord() == coord){
            return paatti.first;
        }
    }
}

std::map<int, monsters *> GameBoard::getmonstersMap()
{
    return monstersMap;
}

void GameBoard::nextTurn()
{
    if(runner.get()->getCurrentPlayer().get()->getPlayerId() == runner.get()->playerAmount()){

        runner.get()->getCurrentPlayer().get()->setActionsLeft(3);
        state.get()->changePlayerTurn(1);
    }
    else{
        runner.get()->getCurrentPlayer().get()->setActionsLeft(3);
    state.get()->changePlayerTurn(getrunner().get()->getCurrentPlayer().get()->getPlayerId() + 1);

    }
    state.get()->changeGamePhase(Common::GamePhase::MOVEMENT);
    this->updateInfobox(this->getstate().get()->currentGamePhase(), this->getstate().get()->currentPlayer());

}

std::map<int, Paatti *> GameBoard::getPaattiMap()
{
    return paattiMap;
}


void GameBoard::showScoreBoard(std::vector<std::pair<int,int>> playerPointVector)
{
    scoreboard = std::make_shared<scoreboardUI>(playerPointVector);
    scoreboard.get()->setGeometry(500,-100,30,30);
    sceneptr_->addWidget(scoreboard.get());
}

void GameBoard::updateScoreBoard(std::vector<std::pair<int, int>> playerPointVector)
{
    scoreboard.get()->updateGraphics(playerPointVector);
}

void GameBoard::showInfoBox(Common::GamePhase currentGamePhase, int playerInTurn)
{


    infobox = std::make_shared<infoBox>(currentGamePhase,playerInTurn);
    infobox.get()->setGeometry(0,-200,30,30);
    sceneptr_->addWidget(infobox.get());
}

void GameBoard::updateInfobox(Common::GamePhase currentGamePhase, int playerInTurn)
{
    infobox.get()->setNew(currentGamePhase,playerInTurn);
    infobox.get()->updateGraphics();
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

