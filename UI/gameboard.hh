#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include <map>
#include <unordered_map>
#include "QGraphicsScene"
#include <QGraphicsItem>
#include <QGraphicsView>
#include "igamerunner.hh"
#include "cmath"
#include "polygoni.hh"

#include "igameboard.hh"
#include <iostream>


class GameBoard : public Common::IGameBoard
{


public:
    GameBoard();
    virtual ~GameBoard();

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

    QGraphicsScene* getscene();

    QPolygon getPolygon(std::shared_ptr<Common::Hex> newHex);signals:

    Common::CubeCoordinate findClickedHex(int clickX, int clickY);

    bool wasClicked(std::shared_ptr<Common::Hex> hexi, int clickX, int clickY);






private:

    std::map<Common::CubeCoordinate, std::shared_ptr<Common::Hex>> HexMap;
    std::unordered_map<int, std::shared_ptr<Common::Pawn>> pawnMap;
    std::map<int, Common::CubeCoordinate> actorMap;
    std::map<Common::CubeCoordinate, std::shared_ptr<QGraphicsItem>> polygonMap;
    std::vector<Common::CubeCoordinate> coordinates;

    QGraphicsScene* sceneptr_;



};

#endif // GAMEBOARD_HH

