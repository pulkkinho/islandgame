#include "hex.hh"

namespace Common {

Hex::Hex(): _actor(""), _pawns(0), _piece("")
{

    _neighbourVector = { Common::CubeCoordinate(1,-1,0),
                         Common::CubeCoordinate(1,0,-1),
                         Common::CubeCoordinate(0,1,-1),
                         Common::CubeCoordinate(-1,1,0),
                         Common::CubeCoordinate(-1,0,1),
                         Common::CubeCoordinate(0,-1,1)
                       };

}

void Hex::setCoordinates(Common::CubeCoordinate newCoordinates)
{

    _coord = newCoordinates;

    setNeighbourVector();
    setWaterAttribute();

}

void Hex::setNeighbourVector()
{

    for(auto neighIt = _neighbourVector.begin();
        neighIt != _neighbourVector.end(); neighIt++){
        neighIt->x = neighIt->x + _coord.x;
        neighIt->y = neighIt->y + _coord.y;
        neighIt->z = neighIt->z + _coord.z;
    }

}

void Hex::setWaterAttribute()
{

    if(((abs(_coord.x - 0) + abs(_coord.y - 0)
         + abs(_coord.z - 0)) / 2) <= 3) {
        _waterTile = 0;
    } else {
        _waterTile = 1;
    }

}

void Hex::setPieceType(std::string piece)
{

    _piece = piece;

}

void Hex::setActorType(std::string actor)
{

    _actor = actor;

}

void Hex::changeOccupation(int pawnAmountChanged)
{

    _pawns = _pawns + pawnAmountChanged;

}

void Hex::addPawn( std::shared_ptr<Common::Pawn> pawn )
{}


Common::CubeCoordinate Hex::getCoordinates() const
{

    return _coord;

}

std::string Hex::getPieceType() const
{

    return _piece;

}

std::string Hex::getActorType() const
{

    return _actor;

}

void Hex::addActor( std::shared_ptr<Common::Actor> actor )
{}

void Hex::removeActor( std::shared_ptr<Common::Actor> actor )
{}

void Hex::addVehicle( std::shared_ptr<Common::Vehicle> vehicle )
{}

void Hex::removeVehicle( std::shared_ptr<Common::Vehicle> vehicle )
{}

int Hex::getPawns() const
{

    return _pawns;

}

bool Hex::isWaterTile() const
{

    return _piece != "Water" || _piece != "Coral";

}

std::vector<Common::CubeCoordinate> Hex::getNeighbourVector() const
{

    return _neighbourVector;

}

std::shared_ptr<Common::Pawn> Hex::givePawn(int pawnId) const
{}

std::shared_ptr<Common::Vehicle> Hex::giveVehicle(int vehicleId) const
{}

std::shared_ptr<Common::Actor> Hex::giveActor(int actorId) const
{}

void Hex::clear()
{}
}
