#ifndef GAMEENGINE_HH
#define GAMEENGINE_HH

#include "cubecoordinate.hh"
#include "igameboard.hh"
#include "igamerunner.hh"
#include "igamestate.hh"
#include "iplayer.hh"

#include <memory>
#include <string>
#include <vector>

/**
 * @file
 * @brief Implements interface IGameRunner.
 */

/**
 * @brief Contains pre-existing classes that may not be referred by code written by students.
 */
namespace Logic {

/**
 * @brief Implements the interface IGamerunner.
 */
class GameEngine : public Common::IGameRunner
{

  public:

    /**
     * @brief Constructor.
     * @param boardPtr Shared pointer to the game board.
     * @param statePtr Shared pointer to the game state.
     * @param playerVector Vector that contains players.
     */
    GameEngine(std::shared_ptr<Common::IGameBoard> boardPtr, std::shared_ptr<Common::IGameState> statePtr, std::vector<Common::IPlayer*> playerVector);

    /**
     * @copydoc Common::IGameRunner::checkPawnMovement()
     */
    virtual int checkPawnMovement(Common::CubeCoordinate pawnToMove, Common::CubeCoordinate tileToMove, int pawnId);

    /**
     * @copydoc Common::IGameRunner::flipTile()
     */
    virtual std::string flipTile(Common::CubeCoordinate tileCoord);

    /**
     * @copydoc Common::IGameRunner::spinWheel()
     */
    virtual std::pair<std::string,std::string> spinWheel();

    /**
     * @copydoc Common::IGameRunner::currentPlayer()
     */
    virtual int currentPlayer() const;

    /**
     * @copydoc Common::IGameRunner::currentGamePhase()
     */
    virtual Common::GamePhase currentGamePhase() const;

  private:

    bool breadthFirst(Common::CubeCoordinate FromCoord, Common::CubeCoordinate ToCoord, unsigned int actionsLeft);

    unsigned int cubeCoordinateDistance(Common::CubeCoordinate source, Common::CubeCoordinate target) const;

    std::vector<Common::CubeCoordinate> addHexToBoard(
            Common::CubeCoordinate coord, std::string pieceType);
    void initializeBoard();

    std::vector<Common::IPlayer*> _playerVector;
    std::shared_ptr<Common::IGameBoard> _board;
    std::shared_ptr<Common::IGameState> _gameState;

    //! Actortypes.
    std::vector<std::string> _animalActors;
    std::vector<std::string> _commonActors;

    //! Piecetypes.
    std::vector<std::pair<std::string,int>> _gamePieces;

    int _beachTilesLeft;
    int _forestTilesLeft;
    int _mountainTilesLeft;

};

}

#endif
