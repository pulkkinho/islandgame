#include "pawn.hh"

namespace Common {

Pawn::Pawn(): _xCoord(0), _yCoord(0), _coord(0,0,0) {}

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

    _coord = newCoordinates;

}

void Pawn::setId(int pawnId, int playerId)
{

    _pawnId = pawnId;
    _playerId = playerId;

}

}
