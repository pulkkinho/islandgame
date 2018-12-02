#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include <map>
#include <unordered_map>
#include "QGraphicsScene"
#include <QGraphicsItem>
#include <QGraphicsView>
#include "igamerunner.hh"
#include "cmath"
#include "gamestate.hh"
#include "gameengine.hh"
#include "mainwindow.hh"

#include "igameboard.hh"
#include <iostream>


class GameBoard : public Common::IGameBoard
{


public:
    GameBoard();
    ~GameBoard();

    virtual int checkTileOccupation(Common::CubeCoordinate tileCoord) const;

    virtual bool isWaterTile(Common::CubeCoordinate tileCoord) const;

    virtual std::shared_ptr<Common::Hex> getHex(Common::CubeCoordinate hexCoord) const;

    virtual void addPawn(int playerId, int pawnId);

    virtual void addPawn(int playerId, int pawnId, Common::CubeCoordinate coord);

    virtual void movePawn(int pawnId, Common::CubeCoordinate pawnCoord);

    virtual void removePawn(int pawnId);

    virtual void addActor(std::shared_ptr<Common::Actor> actor, Common::CubeCoordinate actorCoord);

    virtual void moveActor(int actorId, Common::CubeCoordinate actorCoord);

    virtual void removeActor(int actorId);

    virtual void addHex(std::shared_ptr<Common::Hex> newHex);

    virtual void addTransport(std::shared_ptr<Common::Transport> transport, Common::CubeCoordinate coord);

    virtual void moveTransport(int id, Common::CubeCoordinate coord);

    virtual void removeTransport(int id);

    void drawwheel(std::shared_ptr<Common::SpinnerLayout> gamewheel);

    void setwheel(std::shared_ptr<Common::SpinnerLayout> wheel);

    std::shared_ptr<GameState> getstate();


    QGraphicsScene* getscene();

    void setMoveTile(Common::CubeCoordinate coord, int id);

    void setTargetTile(Common::CubeCoordinate coord);

    void setrunner(std::shared_ptr<Common::IGameRunner> runneri);

    std::shared_ptr<Common::IGameRunner> getrunner();

    std::unordered_map<int, std::shared_ptr<Common::Pawn>> getpawnmap();

    std::map<Common::CubeCoordinate, std::shared_ptr<Common::Hex>> getHexMap();

    void addtopawnmap(int,std::shared_ptr<Common::Pawn>);

    int getMoveCount();

    int getMoveFromId();

    void setState(std::shared_ptr<GameState> steitti);


    Common::CubeCoordinate getMoveFrom();

    std::map<int, Pawnitem*> getPawnItemMap();
   // std::unordered_map<int, std::shared_ptr<Common::Pawn>> getactormap();
   //
   // void addtoactormap(int,std::shared_ptr<Common::Pawn>);










private:

    std::map<Common::CubeCoordinate, std::shared_ptr<Common::Hex>> HexMap;
    std::unordered_map<int, std::shared_ptr<Common::Pawn>> pawnMap;
    std::map<int, Pawnitem*> pawnItemMap;
    std::map<int, Common::CubeCoordinate> actorMap;
    std::vector<Common::CubeCoordinate> coordinates;

    std::shared_ptr<GameBoard> matti;

    std::shared_ptr<Common::IGameRunner> runner;

    std::shared_ptr<Common::SpinnerLayout> wheel_;

    std::shared_ptr<GameState> state;
    //Logic::GameEngine runner;

    QGraphicsScene* sceneptr_;
    Common::CubeCoordinate moveFrom;
    Common::CubeCoordinate moveTo;
    int moveFromId;
    int moveCount = 0;



};

#endif // GAMEBOARD_HH

