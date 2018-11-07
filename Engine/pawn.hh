#ifndef PAWN_HH
#define PAWN_HH

#include "cubecoordinate.hh"

#include <memory>

/**
 * @file
 * @brief Pawn. Implements the pawn functionality
 */

namespace Common {
/**
 * @brief Represents a player-owned game piece on the board
 */
class Pawn : public std::enable_shared_from_this<Pawn> {

public:

    /**
     * @brief Constructor.
     */
    Pawn();

    /**
     * @brief setRegularCoordinates sets location for the pawn as x,y-coordinates
     * @param x X-coordinate.
     * @param y Y-coordinate.
     */
    void setRegularCoordinates(int x, int y);

    /**
     * @brief setCoordinates sets location for the pawn in Cube coordinates.
     * @param pawnCoord The location of the pawn in coordinates.
     */
    void setCoordinates(Common::CubeCoordinate pawnCoord);

    /**
     * @brief setId adds a new pawn.
     * @param pawnId The identifier of the pawn.
     * @param playerId The identifier of the player.
     */
    void setId(int pawnId, int playerId);

    /**
     * @brief getId returns id of the pawn
     * @return  id of the pawn
     */
    int getId();

    /**
     * @brief getId returns id of the player the pawn belongs to
     * @return  id of the player who owns this pawn
     */
    int getPlayerId();

private:

    //! X-coordinate.
    int xCoord_;
    //! Y-coordinate.
    int yCoord_;

    //! Cube coordinate.
    Common::CubeCoordinate _coord;

    //! The identifier of the pawn.
    int pawnId_;
    //! The identifier of the player.
    int playerId_;

};

}

#endif
