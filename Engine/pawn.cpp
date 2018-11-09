#include "pawn.hh"

namespace Common {

Pawn::Pawn(): xCoord_(0), yCoord_(0), coord_(0,0,0) {}

void Pawn::setRegularCoordinates(int x, int y)
{

    int newX = ((-2) - ((y - x)/2));
    int newY = (6 - ((y + x)/2));
    int newZ = (y -4);

    Common::CubeCoordinate newCoordinates (newX,newY,newZ);
    setCoordinates(newCoordinates);

}

void Pawn::setCoordinates(Common::CubeCoordinate newCoordinates)
{

    coord_ = newCoordinates;

}

CubeCoordinate Pawn::getCoordinates()
{
    return coord_;
}

void Pawn::setId(int pawnId, int playerId)
{

    pawnId_ = pawnId;
    playerId_ = playerId;

}

int Pawn::getPlayerId()
{
    return playerId_;
}

int Pawn::getId()
{
    return pawnId_;
}

}
