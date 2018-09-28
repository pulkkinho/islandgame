#ifndef HEX_HH
#define HEX_HH

#include "cubecoordinate.hh"
#include <memory>
#include <string>
#include <vector>

/**
 * @file
 * @brief Hex. Represents tiles on the gameboard.
 */

namespace Common {

class Hex : public std::enable_shared_from_this<Hex> {

  public:

    /**
     * @brief Constructor.
     */
    Hex();

    /**
     * @brief setCoordinates sets a new coordinate for the hex.
     * @param newCoordinates The new coordinate of the hex.
     */
    void setCoordinates(Common::CubeCoordinate newCoordinates);

    /**
     * @brief setPieceType sets a new piece type for the hex.
     * @param piece The new piece type of the hex.
     */
    void setPieceType(std::string piece);

    /**
     * @brief setActorType sets a new actor type for the hex.
     * @param piece The new actor type of the hex.
     */
    void setActorType(std::string actor);

    /**
     * @brief changeOccupation
     * @param pawnAmountChanged
     */
    void changeOccupation(int pawnAmountChanged);

    /**
     * @brief getCoordinates gets the location of the hex.
     * @return The location of the hex in coordinates.
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
