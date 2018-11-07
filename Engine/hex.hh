#ifndef HEX_HH
#define HEX_HH

#include "cubecoordinate.hh"
#include <memory>
#include <string>
#include <vector>
#include <map>

/**
 * @file
 * @brief The tiles are defined in the pieces.json file.
 * @brief Default values: Beach, Forest, Mountain, Peak, Coral and sea tiles.
 *
 */

namespace Common {

class Pawn;
class Actor;
class Transport;

/**
 * @brief Represents a hex tile on the gameboard.
 */

class Hex : public std::enable_shared_from_this<Hex> {

  public:

    /**
     * @brief Constructor.
     */
    Hex();

    /**
     * @brief setCoordinates sets new coordinates for this hex tile.
     * @param newCoordinates New coordinates for the hex.
     */
    void setCoordinates(Common::CubeCoordinate newCoordinates);

    /**
     * @brief setPieceType sets a new piece type for the hex.
     * @param piece The new piece type of the hex. Can be
     */
    void setPieceType(std::string piece);

    /**
     * @brief addPawn adds the pawn to the hex
     * @param pawn a shared pointer to the pawn added
     * @post Exception quarantee: nothrow
     */
    void addPawn( std::shared_ptr<Common::Pawn> pawn );

    /**
     * @brief removePawn removes a pawn from the hex
     * @param pawn a shared pointer to the pawn removed
     * @post Exception quarantee: nothrow
     */
    void removePawn(std::shared_ptr<Common::Pawn> pawn );

    /**
     * @brief getCoordinates gets the location of the hex.
     * @return The location of the hex in cube coordinates.
     */
    Common::CubeCoordinate getCoordinates() const;

    /**
     * @brief getPieceType gets the piece type of the hex.
     * @return The piece type of the hex.
     */
    std::string getPieceType() const;

    /**
     * @brief getActorType gets the actor types of the hex.
     * @return The actor types of the hex.
     */
    std::vector<std::string> getActorTypes() const;

    /**
     * @brief addActor adds the actor to the hex
     * @param actor a shared pointer to the actor added
     * @post Exception quarantee: nothrow
     */
    void addActor( std::shared_ptr<Common::Actor> actor );

    /**
     * @brief removeActor removes an actor from the hex
     * @param actor a shared pointer to the actor removed
     * @post Exception quarantee: nothrow
     */
    void removeActor( std::shared_ptr<Common::Actor> actor );

    /**
     * @brief addTransport adds the transport to the hex
     * @param transport a shared pointer to the transport added
     * @post Exception quarantee: nothrow
     */
    void addTransport( std::shared_ptr<Common::Transport> transport );


    /**
     * @brief removeTransport removes a transport from the hex
     * @param transport a shared pointer to the transport removed
     * @post Exception quarantee: nothrow
     */
    void removeTransport( std::shared_ptr<Common::Transport> transport );

    /**
     * @brief getPawnAmount tells the number of the pawns in the hex.
     * @return The number of the pawns in the hex.
     */
    int getPawnAmount() const;

    /**
     * @brief isWaterTile checks if the hex is a water tile.
     * @return true, if the hex is a water tile, else false.
     */
    bool isWaterTile() const;

    /**
     * @brief setWaterAttribute sets a water attribute to the hex.
     */
    void setWaterAttribute();

    /**
     * @brief getNeighbourVector returns the neighbour hexes.
     * @return The neighbour hexes.
     */
    std::vector<Common::CubeCoordinate> getNeighbourVector() const;


    /**
     * @brief givePawn returns the pawn with id pawnId
     * @param pawnId the id of the pawn needed
     * @return a shared pointer to the pawn with id pawnId or nullptr if pawn not found
     */
    std::shared_ptr<Common::Pawn> givePawn(int pawnId) const;

    /**
     * @brief givetransport returns the transport with id transportId
     * @param transportId the id of the transport needed
     * @return a shared pointer to the transport with id transportId or nullptr if transport not found
     */
    std::shared_ptr<Common::Transport> givetransport(int transportId) const;

    /**
     * @brief giveActor returns the actor with id actorId
     * @param actorId the id of the actor needed
     * @return a shared pointer to the actor with id actorId or nullptr if actor not found
     */
    std::shared_ptr<Common::Actor> giveActor(int actorId) const;

    /**
     * @brief clear clears the hex.
     * @post all actors and transports are removed from the hex
     */
    void clear();

  private:

    //! Coordinates of the hex.
    Common::CubeCoordinate coord_;

    //! Actors on the hex, searchable by ID
    mutable std::map<int, std::shared_ptr<Common::Actor>> _actorMap;

    //! transports on the hex, searchable by ID
    mutable std::map<int, std::shared_ptr<Common::Transport>> _transportMap;

    //! Pawns on the hex, searchable by ID
    mutable std::map<int, std::shared_ptr<Common::Pawn>> _pawnMap;

    //! Piece type of the hex.
    std::string piece_;

    //! Whether it is a water tile.
    int waterTile_;

    //! The neighbour hexes.
    std::vector<Common::CubeCoordinate> neighbourVector_;
    void setNeighbourVector();

};

}

#endif
