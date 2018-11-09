#include "actor.hh"
#include <string>
#include <memory>

namespace Common
{

Actor::Actor(int id ):
    id_( id ),
    hex_(nullptr){}

Actor::~Actor(){}

void Actor::move(std::shared_ptr<Hex> to)
{
    addHex(to);
}

void Actor::doAction(){}

std::string Actor::getActorType() const
{
    return "DefaultActorType";
}

int Actor::getId() const
{
    return id_;
}

void Actor::addHex( std::shared_ptr<Common::Hex> hex )
{
    hex->addActor(shared_from_this());
    hex_->removeActor(shared_from_this());
    hex_ = hex;
}

}
