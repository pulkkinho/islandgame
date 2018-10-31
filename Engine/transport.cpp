#include "transport.hh"
#include "hex.hh"
#include <memory>

namespace Common {

Transport::Transport( int transportId ): id_(transportId) {}
Transport::~Transport(){}

void Transport::addPawn( int pawnId ) {}

void Transport::move(std::shared_ptr<Hex> to)
{
    addHex(to);
}

int Transport::getCapacity() const{}

bool Transport::canMove( int playerId ) const {}

void Transport::addHex( std::shared_ptr<Common::Hex> hex )
{
    hex->addTransport(shared_from_this());
}

int Transport::getId()
{
    return id_;
}

}
