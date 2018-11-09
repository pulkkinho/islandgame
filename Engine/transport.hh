#ifndef TRANSPORT_HH
#define TRANSPORT_HH
#include "hex.hh"
#include "pawn.hh"

#include <memory>
#include <vector>

/**
 * @file  The Transport class
 * @brief Implements abstract base class Transport
 * @brief Transports are: boat
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
     * @brief Constructor of Transport
     * @param id Unique identifier for the transport.
     */
    Transport(int id );
    /**
     * @brief desctructor
     * @post Exception quarantee: nothrow
     */
    virtual ~Transport();

    /**
     * @brief addPawn adds pawn to transport
     * @param pawn
     * @post If there is space, pawn is added to transport
     * @post If transport is full, pawn is not added
     */
    void addPawn( std::shared_ptr<Common::Pawn> pawn);

    /**
     * @brief move moves the transport from the current hex hex to another
     * @param to target hex
     * @pre move must be legal
     * @post Transport moved to the hex hex to
     * @post Exception quarantee: strong
     */
    virtual void move( std::shared_ptr<Common::Hex> to) = 0;

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
    virtual bool canMove( int playerId ) const = 0;

    /**
     * @brief addHex adds the transport to the hex
     * @param the hex hex where the transport will be added to
     * @post transport added to hex
     * @post exception quarantee: nothrow
     */
    virtual void addHex( std::shared_ptr<Common::Hex> hex );

    /**
     * @brief isPawnInTransport checks if pawn is in transport
     * @param pawn
     * @return true if pawn is in transport otherwise false
     */
    bool isPawnInTransport(std::shared_ptr<Common::Pawn> pawn);

    /**
     * @brief getId returns id of the transport
     * @return id of the transport
     */
    int getId();

protected:
    using PawnVector = std::vector<std::shared_ptr<Common::Pawn>>;
    int capacity_;
    PawnVector pawns_;
    std::shared_ptr<Common::Hex> hex_;

private:
    int id_;



};

}
#endif // TRANSPORT_HH
