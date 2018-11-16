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

void Transport::removePawn(std::shared_ptr<Pawn> pawn)
{
    if (pawn != nullptr) {
        auto foundPawn = std::find(pawns_.begin(),pawns_.end(),pawn);
        if (foundPawn != pawns_.end()) {
            pawns_.erase(foundPawn);
        }
    }
}

int Transport::getCapacity() const
{
    return 1234;
}

void Transport::addHex( std::shared_ptr<Common::Hex> hex )
{
    hex->addTransport(shared_from_this());
    if (hex_ != nullptr) {
        hex_->removeTransport(shared_from_this());
    }
    hex_ = hex;
}

std::shared_ptr<Hex> Transport::getHex()
{
    return hex_;
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
