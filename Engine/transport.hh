#ifndef TRANSPORT_HH
#define TRANSPORT_HH
#include "hex.hh"
#include <memory>

/**
 * @file  The Transport class
 * @brief Implements abstract base class transport
 * @brief transports are: boat
 */

namespace Common {


/**
 * @brief Offers an abstract base class, which is used as the base class to different transports i.e. boat
 */
class Transport : public std::enable_shared_from_this<Transport>
{
  public:
    /**
     * @brief default constructor
     */
    Transport() = default;

    /**
     * @brief Constructor of transport
     * @param transportId the id of the transport created
     */
    Transport( int transportId );
    /**
     * @brief desctructor
     * @post Exception quarantee: nothrow
     */
    virtual ~Transport();

    virtual void addPawn( int pawnId );

    /**
     * @brief move moves the transport from the current hex tile to another
     * @param to indicates the target tile
     * @pre move must be legal
     * @post transport moved to the hex tile to
     * @post Exception quarantee: strong
     */
    virtual void move( std::shared_ptr<Common::Hex> to);

    /**
     * @brief getCapacity returns the amount of pawns the transport is able to carry
     * @return the amount of free places
     */
    virtual int getCapacity() const;

    /**
     * @brief canMove checks if the player playerId is allowed to move the transport
     * @param playerId
     * @return true is playerId can move the transport, false if not
     */
    virtual bool canMove( int playerId ) const;

    /**
     * @brief addHex adds the transport to the hex
     * @param hex the hex tile the transport is added to
     * @post actor added to hex
     * @post exception quarantee: nothrow
     */
    virtual void addHex( std::shared_ptr<Common::Hex> hex );

    /**
     * @brief getId returns id of the transport
     * @return id of the transport
     */
    int getId();

  private:
    int id_;
    int capacity_;
};

}
#endif // TRANSPORT_HH
