#ifndef VEHICLE_HH
#define VEHICLE_HH
#include "hex.hh"
#include <memory>

/**
 * @file  The Vehicle class
 * @brief Implements abstract base class Vehicle
 * @brief Vehicles are: boat
 */

namespace Common {


/**
 * @brief Offers an abstract base class, which is used as the base class to different vehicles i.e. boat
 */
class Vehicle : public std::enable_shared_from_this<Vehicle>
{
  public:
    /**
     * @brief default constructor
     */
    Vehicle() = default;

    /**
     * @brief Constructor of Vehicle
     * @param vehicleId the id of the vehicle created
     */
    Vehicle( int vehicleId );
    /**
     * @brief desctructor
     * @post Exception quarantee: nothrow
     */
    virtual ~Vehicle();

    virtual void addPawn( int pawnId );

    /**
     * @brief move moves the vehicle from the current hex tile to another
     * @param to indicates the target tile
     * @pre move must be legal
     * @post Vehicle moved to the hex tile to
     * @post Exception quarantee: strong
     */
    virtual void move( std::shared_ptr<Common::Hex> to);

    /**
     * @brief getCapacity returns the amount of pawns the vehicle is able to carry
     * @return the amount of free places
     */
    virtual int getCapacity() const;

    /**
     * @brief canMove checks if the player playerId is allowed to move the vehicle
     * @param playerId
     * @return true is playerId can move the vehicle, false if not
     */
    virtual bool canMove( int playerId ) const;

    /**
     * @brief addHex adds the vehicle to the hex
     * @param hex the hex tile the vehicle is added to
     * @post actor added to hex
     * @post exception quarantee: nothrow
     */
    virtual void addHex( std::shared_ptr<Common::Hex> hex );

  private:
    int id_;
    int capacity_;
};

}
#endif // VEHICLE_HH
