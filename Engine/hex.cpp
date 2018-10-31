#include "hex.hh"
#include "pawn.hh"
#include "actor.hh"
#include "transport.hh"

namespace Common {

Hex::Hex(): piece_("")
{

    neighbourVector_ = { Common::CubeCoordinate(1,-1,0),
                         Common::CubeCoordinate(1,0,-1),
                         Common::CubeCoordinate(0,1,-1),
                         Common::CubeCoordinate(-1,1,0),
                         Common::CubeCoordinate(-1,0,1),
                         Common::CubeCoordinate(0,-1,1)
                       };

}

void Hex::setCoordinates(Common::CubeCoordinate newCoordinates)
{

    coord_ = newCoordinates;

    setNeighbourVector();
    setWaterAttribute();

}

void Hex::setNeighbourVector()
{

    for(auto neighIt = neighbourVector_.begin();
        neighIt != neighbourVector_.end(); neighIt++){
        neighIt->x = neighIt->x + coord_.x;
        neighIt->y = neighIt->y + coord_.y;
        neighIt->z = neighIt->z + coord_.z;
    }

}

void Hex::setWaterAttribute()
{

    if(((abs(coord_.x - 0) + abs(coord_.y - 0)
         + abs(coord_.z - 0)) / 2) <= 3) {
        waterTile_ = 0;
    } else {
        waterTile_ = 1;
    }

}

void Hex::setPieceType(std::string piece)
{

    piece_ = piece;

}

void Hex::addPawn( std::shared_ptr<Common::Pawn> pawn )
{
    if (pawn != nullptr) {
        _pawnMap[pawn->getId()] = pawn;
    }
}

void Hex::removePawn(std::shared_ptr<Pawn> pawn)
{
    if (pawn != nullptr) {
        _pawnMap.erase(pawn->getId());
    }
}


Common::CubeCoordinate Hex::getCoordinates() const
{

    return coord_;

}

std::string Hex::getPieceType() const
{

    return piece_;

}

std::vector<std::string> Hex::getActorTypes() const
{
    std::vector<std::string> actorTypes;

    for (auto iter = _actorMap.begin(); iter != _actorMap.end(); ++iter)
    {
        actorTypes.push_back(iter->second->getActorType());
    }

    return actorTypes;

}

void Hex::addActor( std::shared_ptr<Common::Actor> actor )
{
    if (actor != nullptr) {
        _actorMap[actor->getId()] = actor;
    }
}

void Hex::removeActor( std::shared_ptr<Common::Actor> actor )
{
    if (actor != nullptr) {
        _actorMap.erase(actor->getId());
    }
}

void Hex::addTransport( std::shared_ptr<Common::Transport> transport )
{
    if (transport != nullptr) {
        _transportMap[transport->getId()] = transport;
    }
}

void Hex::removeTransport( std::shared_ptr<Common::Transport> transport )
{
    if (transport != nullptr) {
        _transportMap.erase(transport->getId());
    }
}

int Hex::getPawnAmount() const
{

    return _pawnMap.size();

}

bool Hex::isWaterTile() const
{

    return piece_ == "Water";

}

std::vector<Common::CubeCoordinate> Hex::getNeighbourVector() const
{

    return neighbourVector_;

}

std::shared_ptr<Common::Pawn> Hex::givePawn(int pawnId) const
{
    if (_pawnMap.find(pawnId) == _pawnMap.end()) {
        return nullptr;
    }
    return _pawnMap[pawnId];
}

std::shared_ptr<Common::Transport> Hex::givetransport(int transportId) const
{
    if (_transportMap.find(transportId) == _transportMap.end()) {
        return nullptr;
    }
    return _transportMap[transportId];
}

std::shared_ptr<Common::Actor> Hex::giveActor(int actorId) const
{
    if (_actorMap.find(actorId) == _actorMap.end()) {
        return nullptr;
    }
    return _actorMap[actorId];
}

void Hex::clear()
{
    _actorMap.clear();
    _transportMap.clear();
    _pawnMap.clear();
}
}
