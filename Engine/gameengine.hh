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
#include <map>

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
    GameEngine(std::shared_ptr<Common::IGameBoard> boardPtr,
               std::shared_ptr<Common::IGameState> statePtr,
               std::vector<std::shared_ptr<Common::IPlayer>> players);

    /**
     * @copydoc Common::IGameRunner::movePawn()
     */
    virtual int movePawn(Common::CubeCoordinate origin,
                         Common::CubeCoordinate target,
                         int pawnId);

    /**
     * @copydoc Common::IGameRunner::checkPawnMovement()
     */
    virtual int checkPawnMovement(Common::CubeCoordinate origin,
                                  Common::CubeCoordinate target,
                                  int pawnId);
    /**
     * @copydoc Common::IGameRunner::moveActor()
     */
    virtual void moveActor(Common::CubeCoordinate origin,
                           Common::CubeCoordinate target,
                           int actorId,
                           std::string moves);

    /**
     * @copydoc Common::IGameRunner::checkActorMovement()
     */
    virtual bool checkActorMovement(Common::CubeCoordinate origin,
                                    Common::CubeCoordinate target,
                                    int actorId,
                                    std::string moves);
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

    std::vector<Common::CubeCoordinate> addHexToBoard(Common::CubeCoordinate coord,
                                                      std::string pieceType);
    void initializeBoard();

    std::vector<std::shared_ptr<Common::IPlayer>> playerVector_;
    std::shared_ptr<Common::IGameBoard> board_;
    std::shared_ptr<Common::IGameState> gameState_;

    //! Actortypes.
    std::vector<std::string> animalActors_;
    std::vector<std::string> commonActors_;

    //! Piecetypes.
    std::vector<std::pair<std::string,int>> islandPieces_;

};

}

#endif
