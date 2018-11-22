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

    void drawHex(std::shared_ptr<Common::Hex> newHex);

    GameState* getstate();

    QGraphicsScene* getscene();

    QPolygon getPolygon(std::shared_ptr<Common::Hex> newHex);signals:

    Common::CubeCoordinate findClickedHex(int clickX, int clickY);

    bool wasClicked(std::shared_ptr<Common::Hex> hexi, int clickX, int clickY);

    void setrunner(std::shared_ptr<Common::IGameRunner> runneri);

    std::shared_ptr<Common::IGameRunner> getrunner();

//    bool arebeachleft();
//
//    bool areforestleft();
//
//    bool aremountainleft();









private:

    std::map<Common::CubeCoordinate, std::shared_ptr<Common::Hex>> HexMap;
    std::unordered_map<int, std::shared_ptr<Common::Pawn>> pawnMap;
    std::map<int, Common::CubeCoordinate> actorMap;
    std::vector<Common::CubeCoordinate> coordinates;

    std::shared_ptr<GameBoard> matti;

    std::shared_ptr<Common::IGameRunner> runner;
    //Logic::GameEngine runner;

    QGraphicsScene* sceneptr_;
    GameState* state;
    int paattimaara;



};

#endif // GAMEBOARD_HH

