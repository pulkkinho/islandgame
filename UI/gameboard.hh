#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include <map>
#include <unordered_map>

#include "igameboard.hh"
#include <iostream>

class GameBoard : public Common::IGameBoard
{
public:
    GameBoard();
    ~GameBoard();



    virtual int checkTileOccupation(Common::CubeCoordinate tileCoord) const = 0;

    virtual bool isWaterTile(Common::CubeCoordinate tileCoord) const = 0;

    virtual std::shared_ptr<Common::Hex> getHex(Common::CubeCoordinate hexCoord) const = 0;

    virtual void addPawn(int playerId, int pawnId) = 0;

    virtual void movePawn(int pawnId, Common::CubeCoordinate pawnCoord) = 0;

    virtual void removePawn(int pawnId) = 0;

    virtual void moveActor(int actorId, Common::CubeCoordinate actorCoord) = 0;

    virtual void removeActor(int actorId) = 0;

    virtual void addHex(std::shared_ptr<Common::Hex> newHex) = 0;

private:
    bool occupation_;
    std::string type_; //täh
    std::unordered_map<int, std::shared_ptr<Common::Pawn>> pawnMap;
    std::map<Common::CubeCoordinate, std::shared_ptr<Common::Hex>> HexMap;
    std::map<int, Common::CubeCoordinate> actorMap;

};

#endif // GAMEBOARD_HH

