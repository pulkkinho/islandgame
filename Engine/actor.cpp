#include "actor.hh"
#include <string>
#include <memory>

namespace Common
{

Actor::Actor( int typeId ) : typeid_( typeId ){}

Actor::~Actor(){}

void Actor::move(std::shared_ptr<Hex> to) {}

void Actor::doAction(){}

std::string Actor::getActorType() const {}

int Actor::getId() const
{
    return typeid_;
}

void addHex( std::shared_ptr<Common::Hex> hex ){}

}
