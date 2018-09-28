#ifndef IGAMERUNNER_HH
#define IGAMERUNNER_HH

#include "cubecoordinate.hh"
#include "igamestate.hh"

#include <string>

/**
 * @file
 * @brief Interface class that is used to control the flow of the game.
 */

namespace Common {

/**
 * @brief Offers an interface, which is used to control the game logic.
 */
class IGameRunner {

  public:

    /**
     * @brief Default constructor, exists solely for documentation.
     */
    IGameRunner() = default;

    /**
     * @brief Virtual destructor. Does nothing, since this is an interface class.
     */
    virtual ~IGameRunner() = default;

    /**
     * @brief checkPawnMovement tells if move is possible.
     * @param pawnToMove The origin of the proposed move.
     * @param tileToMove The destination of the proposed move.
     * @param pawnId The identifier of the pawn.
     * @return 0-3 (number of moves left) or -1 (movement is impossible)
     * @post Exception quarantee: nothrow
     */
    virtual int checkPawnMovement(CubeCoordinate pawnToMove, CubeCoordinate tileToMove, int pawnId) = 0;

    /**
     * @brief flipTile tells the actor on the bottom of the tile.
     * @param tileCoord Coordinate of the selected tile.
     * @return The actor on the bottom of the tile or empty string (fail).
     * @exception IllegalMoveException, if any error occured.
     * @post Exception quarantee: strong
     */
    virtual std::string flipTile(CubeCoordinate tileCoord) = 0;

    /**
     * @brief spinWheel tells which animal moves and how much it moves.
     * @return a pair <the identifier of the animal,number of movements>
     * @post game phase set to three. Exception quarantee: strong
     * @brief spinWheel tells what animal moves and how much it moves.
     * @return Pair: <the identifier of the animal,number of movements>
     */
    virtual std::pair<std::string,std::string> spinWheel() = 0;

    /**
     * @brief currentPlayer tells the player in turn.
     * @return The player id in the turn.
     * @post Exception quarantee: nothrow
     */
    virtual int currentPlayer() const = 0;

    /**
     * @brief currentGamePhase tells the game phase of the game.
     * @return The game phase of the game.
     * @post Exception quarantee: nothrow
     */
    virtual Common::GamePhase currentGamePhase() const = 0;


};

}

#endif
