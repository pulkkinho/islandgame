#ifndef HEX_HH
#define HEX_HH

#include "cubecoordinate.hh"
#include <memory>
#include <string>
#include <vector>

/**
 * @file
 * @brief The tiles are defined in the pieces.json file.
 * @brief Default values: Beach, Forest, Mountain, Peak, Coral and sea tiles.
 *
 */

namespace Common {

class Pawn;
class Actor;
class Vehicle;

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
     * @brief setActorType sets a new actor type for the hex.
     * @param piece The new actor type of the hex.
     */
    void setActorType(std::string actor);

    /**
     * @brief changeOccupation Change the occupation count of this hex tile.
     * @param pawnAmountChanged Amount to add to the current occupation (negative amount for decreasing).
     */
    void changeOccupation(int pawnAmountChanged);

    /**
     * @brief addPawn adds the pawn to the hex
     * @param pawn a shared pointer to the pawn added
     * @post Exception quarantee: nothrow
     */
    void addPawn( std::shared_ptr<Common::Pawn> pawn );

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
     * @brief getActorType gets the actor type of the hex.
     * @return The actor type of the hex.
     */
    std::string getActorType() const;

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
     * @brief addVehicle adds the vehicle to the hex
     * @param vehicle a shared pointer to the vehicle added
     * @post Exception quarantee: nothrow
     */
    void addVehicle( std::shared_ptr<Common::Vehicle> vehicle );


    /**
     * @brief removeVehicle removes a vehicle from the hex
     * @param vehicle a shared pointer to the vehicle removed
     * @post Exception quarantee: nothrow
     */
    void removeVehicle( std::shared_ptr<Common::Vehicle> vehicle );

    /**
     * @brief getPawns tells the number of the pawns in the hex.
     * @return The number of the pawns in the hex.
     */
    int getPawns() const;

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
     * @brief giveVehicle returns the vehicle with id vehicleId
     * @param vehicleId the id of the vehicle needed
     * @return a shared pointer to the vehicle with id vehicleId or nullptr if vehicle not found
     */
    std::shared_ptr<Common::Vehicle> giveVehicle(int vehicleId) const;

    /**
     * @brief giveActor returns the actor with id actorId
     * @param actorId the id of the actor needed
     * @return a shared pointer to the actor with id actorId or nullptr if actor not found
     */
   std::shared_ptr<Common::Actor> giveActor(int actorId) const;

   /**
    * @brief clear clears the hex.
    * @post all actors and vehicles are removed from the hex
    */
   void clear();

  private:

    //! Coordinates of the hex.
    Common::CubeCoordinate _coord;

    //! Actor type of the hex.
    std::string _actor;

    //! Number of the pawns in the hex.
    int _pawns;

    //! Piece type of the hex.
    std::string _piece;

    //! Whether it is a water tile.
    int _waterTile;

    //! The neighbour hexes.
    std::vector<Common::CubeCoordinate> _neighbourVector;
    void setNeighbourVector();

};

}

#endif
