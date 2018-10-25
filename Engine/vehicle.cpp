#include "vehicle.hh"
#include "hex.hh"
#include <memory>

namespace Common{

Vehicle::Vehicle( int vehicleId ) {}
Vehicle::~Vehicle(){}

void Vehicle::addPawn( int pawnId ) {}

void Vehicle::move(std::shared_ptr<Hex> to) {}

int Vehicle::getCapacity() const{}

bool Vehicle::canMove( int playerId ) const {}

void addHex( std::shared_ptr<Common::Hex> hex ){}

}
