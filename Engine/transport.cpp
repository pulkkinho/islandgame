#include "transport.hh"
#include "hex.hh"
#include <memory>
#include <algorithm>

namespace Common{

Transport::Transport( int id ):
    id_(id){}

Transport::~Transport(){}

void Transport::addPawn(std::shared_ptr<Pawn> pawn )
{
    if ( getCapacity() > 0 ){
        pawns_.push_back(pawn);
    }
}

int Transport::getCapacity() const
{
    return 1234;
}

void Transport::addHex( std::shared_ptr<Common::Hex> hex )
{
    hex->addTransport(shared_from_this());
    hex_->removeTransport(shared_from_this());
    hex_ = hex;
}

bool Transport::isPawnInTransport(std::shared_ptr<Pawn> pawn)
{
    return (std::find(pawns_.begin(),pawns_.end(),pawn) != pawns_.end());
}

int Transport::getId()
{
    return id_;
}

}
