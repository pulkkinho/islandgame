#include "gameboard.hh"
#include "hex.hh"
#include "QGraphicsPolygonItem"
#include "ostream"
#include <QGraphicsSceneMouseEvent>
#include "map"
#include "iostream"
#include "string"
#include "paatti.hh"
#include "mainwindow.hh"
#include "spinnerwheel.hh"
#include <stdio.h>
#include "QLabel"
#include "QtWidgets"
#include "infobox.hh"
#include "gamestate.hh"
#include "hexagon.hh"

#include "pawnitem.hh"
#include "pawn.hh"
#include "monsters.hh"

#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "QTimer"



GameBoard::GameBoard():
    Common::IGameBoard()

{


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

}



void GameBoard::movePawn(int pawnId, Common::CubeCoordinate pawnCoord)
{

    Common::CubeCoordinate oldCoord = pawnItemMap.at(pawnId)->getCoord();

    HexMap.at(oldCoord).get()->removePawn(pawnMap.at(pawnId));

    int x = 0;
    //päivitetään vanhassa ruudussa olleiden muiden pawnien sijainti
    while (x < HexMap.at(oldCoord).get()->getPawnAmount()){
        pawnItemMap.at(HexMap.at(oldCoord).get()->getPawns().at(x).get()->getId())->updateGraphics(x+1);
        ++x;
    }
    if(HexMap.at(pawnCoord).get()->getTransports().size() > 0 && HexMap.at(pawnCoord).get()->getTransports().at(0).get()->getCapacity() > 0){
        HexMap.at(pawnCoord).get()->getTransports().at(0).get()->addPawn(pawnMap.at(pawnId));
    }
    pawnItemMap.at(pawnId)->setNewCoord(pawnCoord);
    pawnMap.at(pawnId)->setCoordinates(pawnCoord);
    HexMap.at(pawnCoord).get()->addPawn(pawnMap.at(pawnId));
    pawnItemMap.at(pawnId)->updateGraphics(HexMap.at(pawnCoord).get()->getPawnAmount());



    if(checkPoints(pawnCoord)==true){

        for(auto paatti : paattiMap){
            if(paatti.second->getObject().get()->isPawnInTransport(pawnMap.at(pawnId)) == true){
                paatti.second->getObject().get()->removePawn(pawnMap.at(pawnId));
            }
        }

        if(HexMap.at(pawnMap.at(pawnId).get()->getCoordinates()).get()->getPawnAmount() > 0){
        HexMap.at(pawnItemMap.at(pawnId)->getCoord()).get()->removePawn(pawnMap.at(pawnId));
        }
        pawnMap.erase(pawnId);
    }

    if(HexMap.at(pawnCoord).get()->getActorTypes().size() > 0){
        if(HexMap.at(pawnCoord).get()->getActorTypes().at(0) == "vortex"){
            removePawn(pawnId);
        }
    }
    moveCount = 0;
}


void GameBoard::removePawn(int pawnId)
{
    for(std::unordered_map<int, std::shared_ptr<Common::Pawn>>::iterator it = pawnMap.begin(); it != pawnMap.end(); it++)
    {
        if((it->first) == pawnId)
        {
            if(HexMap.at(pawnMap.at(pawnId).get()->getCoordinates()).get()->getPawnAmount() > 0){
            HexMap.at(pawnItemMap.at(pawnId)->getCoord()).get()->removePawn(pawnMap.at(pawnId));
            }
            pawnMap.erase(it);
            sceneptr_->removeItem(pawnItemMap.at(pawnId));
            break;
        }
    }

}

void GameBoard::addActor(std::shared_ptr<Common::Actor> actor, Common::CubeCoordinate actorCoord)
{
    actorMap.insert(std::make_pair(actor.get()->getId(), actorCoord));
    monsters* superpaatti = new monsters(actor, actorMap.at(actor.get()->getId()), sceneptr_);
    superpaatti->setmonsters(actor);
    HexMap.at(actorMap.at(actor.get()->getId())).get()->addActor(actor);
    actor.get()->addHex(HexMap.at(actorMap.at(actor.get()->getId())));
    monstersMap.insert(std::make_pair(actor.get()->getId(), superpaatti));



    if(actor.get()->getActorType() == "vortex"){
        //poistetaan mahdolliset hexissä olleet pawnit
        if(HexMap.at(actorCoord).get()->getPawnAmount() > 0){
            for (auto pawn: HexMap.at(actorCoord).get()->getPawns()){
                removePawn(pawn.get()->getId());
            }
        }
        //poistetaan ympäröivien hexien transportit..
        for(auto hexCoord : HexMap.at(actorCoord).get()->getNeighbourVector()){
            if(HexMap.at(hexCoord).get()->getTransports().size()>0){
                removeTransport(HexMap.at(hexCoord).get()->getTransports().at(0).get()->getId());
            }
            //..ja pawnit..
            if(HexMap.at(hexCoord).get()->getPawnAmount()>0){
                for (auto pawn : HexMap.at(hexCoord).get()->getPawns()){
                    removePawn(pawn.get()->getId());
                }
            }//..ja actorit vortexeja lukuunottamatta
            if(HexMap.at(hexCoord).get()->getActors().size() > 0){
                for(auto actor : HexMap.at(hexCoord).get()->getActors()){
                    if(actor.get()->getActorType() != "vortex"){
                    removeActor(actor.get()->getId());
                    }
                }
            }
        }
    }
}

void GameBoard::moveActor(int actorId, Common::CubeCoordinate actorCoord)
{
    std::vector<std::shared_ptr<Common::Transport>> transportit = HexMap.at(actorCoord).get()->getTransports();

    std::vector<std::shared_ptr<Common::Pawn>> pawnit = HexMap.at(actorCoord).get()->getPawns();

    monstersMap.at(actorId)->getActor().get()->addHex(HexMap.at(actorCoord));
    monstersMap.at(actorId)->getActor().get()->doAction();
    HexMap.at(actorCoord).get()->addActor(monstersMap.at(actorId)->getActor());
    if(transportit.size() != HexMap.at(actorCoord).get()->getTransports().size()){
            removeTransport(paattiMap.at(getPaattiId(actorCoord))->getObject().get()->getId());

    }

    if(pawnit.size() != HexMap.at(actorCoord).get()->getPawns().size()){
        for(auto pawn : pawnit){
            removePawn(pawn.get()->getId());
        }
    }
    bool remove = false;
    for(auto actor : HexMap.at(actorCoord).get()->getActorTypes()){
        if(actor == "vortex"){
            removeActor(actorId);
            remove = true;
        }
    }

    if (remove == false){
        monstersMap.at(actorId)->setNewCoord(actorCoord);
        monstersMap.at(actorId)->updateGraphics();
    }
}

void GameBoard::removeActor(int actorId)
{
    // toimiiks?

    for(std::map<int, Common::CubeCoordinate>::iterator it = actorMap.begin(); it != actorMap.end(); it++)
    {
        if((it->first) == actorId)
        {   if(HexMap.at(actorMap.at(actorId)).get()->getActors().size() > 0){
            HexMap.at(actorMap.at(actorId)).get()->removeActor(monstersMap.at(actorId)->getActor());
            }
            actorMap.erase(it);
            sceneptr_->removeItem(monstersMap.at(actorId));
            monstersMap.erase(actorId);
            break;
        }
    }
}

void GameBoard::addHex(std::shared_ptr<Common::Hex> newHex)
{
    Common::CubeCoordinate coord = newHex.get()->getCoordinates();
    bool neww = true;
    for(auto hex : HexMap){
        if(hex.first.x == coord.x && hex.first.y == coord.y && hex.first.z == coord.z){
            HexMap.at(hex.first) = newHex;
            neww = false;
        }
    }
    if (neww == true){
        HexMap.insert(std::make_pair(coord, newHex));

    }
}

std::shared_ptr<GameState> GameBoard::getstate()
{
    return state;
}

std::pair<std::string, std::string> GameBoard::spinwheel()
{
    std::pair<std::string,std::string> result = this->getrunner().get()->spinWheel();

    spinner = new spinneranimation(result.first,result.second);
    spinner->startanimation();

    proxy = sceneptr_->addWidget(spinner);
    std::cout << result.first << " spin" << std::endl;


    spinnermovement = new QLabel();
    spinnermovement->setStyleSheet("QLabel { background-color : white; color : blue; }");


    QString menejo =QString::fromStdString( result.second);
    spinnermovement->setText("Amount to move:   "+menejo);
    spinnermovement->setGeometry(-250,50,150,25);
    sceneptr_->addWidget(spinnermovement);


    spinnerResult = result;

    for (auto aktor : monstersMap){
        if(aktor.second->getType() == spinnerResult.first){
            return result;
        }
    }
    if (result.first == "dolphin"){
        for (auto transport : paattiMap){
            if(transport.second->getObject().get()->getTransportType() == "dolphin"){
                return result;
            }
        }
    }
    nextTurn();
}

void GameBoard::addTransport(std::shared_ptr<Common::Transport> transport, Common::CubeCoordinate coord)
{
    Paatti* superpaatti = new Paatti(transport, coord, sceneptr_);
    transport.get()->addHex(HexMap.at(coord));
    HexMap.at(coord).get()->addTransport(transport);
    paattiMap.insert(std::make_pair(transport.get()->getId(), superpaatti));
    //lisätään mahdolliset jo hexissä olleet pawnit transporttiin
    if(HexMap.at(coord).get()->getPawnAmount() > 0){
        for(auto x : HexMap.at(coord).get()->getPawns()){
            if(transport.get()->getCapacity() > 0){
                transport.get()->addPawn(x);
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
    if(HexMap.at(coord).get()->getPawnAmount() > 0){
        for(auto pawn : HexMap.at(coord).get()->getPawns()){
            paattiMap.at(id)->getObject().get()->addPawn(pawn);
        }
    }
    if(HexMap.at(coord).get()->getActorTypes().size() > 0){
        if(paattiMap.at(id)->getObject().get()->getPawnsInTransport().size() > 0
                && HexMap.at(coord).get()->getActorTypes().at(0) == "vortex"){
            for(auto pawns : paattiMap.at(id)->getObject().get()->getPawnsInTransport()){
                removePawn(pawns.get()->getId());
            }
        }
        if(HexMap.at(coord).get()->getActorTypes().at(0) == "vortex"){
            removeTransport(id);
        }

    }
}

void GameBoard::removeTransport(int id)
{

    if(HexMap.at(paattiMap.at(id)->getCoord()).get()->getTransports().size() > 0){
    HexMap.at(paattiMap.at(id)->getCoord()).get()->removeTransport(paattiMap.at(id)->getObject());
    }
    sceneptr_->removeItem(paattiMap.at(id));
    paattiMap.erase(id);
}

void GameBoard::drawwheel()
{
            spinnerwheel* superpaatti = new spinnerwheel();
            sceneptr_->addItem(superpaatti);

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
    if(checkIfGameOver() == false){
    if(runner.get()->getCurrentPlayer().get()->getPlayerId() == runner.get()->playerAmount()){

        runner.get()->getCurrentPlayer().get()->setActionsLeft(3);
        state.get()->changePlayerTurn(1);
    }
    else{
        runner.get()->getCurrentPlayer().get()->setActionsLeft(3);
    state.get()->changePlayerTurn(getrunner().get()->getCurrentPlayer().get()->getPlayerId() + 1);

    }
    bool loyty = false;
    for(auto pawn : pawnMap){
        std::cout << pawnMap.size() << " size" << std::endl;
        if (pawn.second.get()->getPlayerId() == runner.get()->getCurrentPlayer().get()->getPlayerId()){
            loyty = true;
        }

    }
    if (loyty == false){
        nextTurn();
    }
    state.get()->changeGamePhase(Common::GamePhase::MOVEMENT);

    spinnermovement->clear();
    sceneptr_->removeItem(proxy);
    this->updateInfobox(this->getstate().get()->currentGamePhase(), this->getstate().get()->currentPlayer());
    }

    //pelin loppu
    else{
        std::vector<int> winners;
        int highscore = 0;
        for(auto player : getstate().get()->getPlayerPointVector()){
            int id = player.first;
            int score = player.second;
            std::cout << id << " " << score << std::endl;
            if (score > highscore){
                std::cout << "huu" << std::endl;
                highscore = score;
                winners.clear();
                winners.push_back(id);
            }
            else if(score == highscore){
                winners.push_back(id);
            }
        }
        std::cout << winners.size() << "öööl" << std::endl;
        if(winners.size() > 1){
            std::cout << "tie" << std::endl;

            infobox.get()->gameOver(true, 0);
        }
        else{std::cout << "viineri" << std::endl;
            infobox.get()->gameOver(false, winners.at(0));
        }
    }
}

std::map<int, Paatti *> GameBoard::getPaattiMap()
{
    return paattiMap;
}



bool GameBoard::checkPoints(Common::CubeCoordinate pawnNewCoord)
{
    int playerId = state.get()->currentPlayer();
    if(HexMap.at(pawnNewCoord).get()->getPieceType() == "Coral"){
        for(auto player : state.get()->getPlayerPointVector()){
            if(player.first == playerId){
                state.get()->addPointsToPlayer(playerId,1);
                return true;
            }
        }
    }
    return false;
}

bool GameBoard::checkIfGameOver()
{
    if(pawnMap.size() == 0 ){
        // joku configwindowin tapainen asia ja kun exec->exit(0)

        return true;
    }
    return false;
}

void GameBoard::setScene()
{

    sceneptr_ = new QGraphicsScene;
}

void GameBoard::addHextoScene()
{
    for(auto hex : HexMap){
        std::shared_ptr<Common::Hex> newHex = hex.second;

        int z = newHex.get()->getCoordinates().z;
        int x = newHex.get()->getCoordinates().x;
        int y = newHex.get()->getCoordinates().y;

        Widget* super = new Widget(newHex, newHex.get()->getPieceType(), x, y, z, this, newHex.get()->getCoordinates());
        sceneptr_->addItem(super);
    }



}

void GameBoard::addActorsToScene(int actorId)
{
}

void GameBoard::addPawnsToScene()
{
    for(auto pawn : pawnMap){
        std::shared_ptr<Common::Pawn> pawni = pawn.second;
        Pawnitem* apina = new Pawnitem(pawni.get()->getPlayerId(),
                                       pawn.first, pawni.get()->getCoordinates(),
                                       HexMap.at(pawni.get()->getCoordinates()),
                                       sceneptr_);
        //pawnitemille oikea hex
        apina->setHex(HexMap.at(pawni.get()->getCoordinates()));
        //pawnitem oikeaan positioon
        apina->updateGraphics(HexMap.at(pawni.get()->getCoordinates()).get()->getPawnAmount());
        pawnItemMap.insert(std::make_pair(pawn.first, apina));
        sceneptr_->addItem(apina);
    }
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

    return pawnMap;
}

void GameBoard::addtopawnmap(int id, std::shared_ptr<Common::Pawn> pawnptr){
    pawnMap.insert(std::make_pair(id,pawnptr));
}



void GameBoard::setrunner(std::shared_ptr<Common::IGameRunner> runneri)
{
  runner = runneri;

}

