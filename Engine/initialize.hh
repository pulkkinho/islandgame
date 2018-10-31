#ifndef INITIALIZE_HH
#define INITIALIZE_HH

#include "igameboard.hh"
#include "igamerunner.hh"
#include "igamestate.hh"
#include "iplayer.hh"

#include <memory>

/**
 * @file
 * @brief Declaration of intialization functions
 */

namespace Common {

/**
 * @brief This module contains the functions related to the initialization of the game.
 * This is used to integrate the code from the studend side to the GameLogic.
 */
namespace Initialization {

/**
 * @brief getGameRunner Creates an instance of the class that implements IGameRunner interface.
 * @param boardPtr Shared pointer to the game board.
 * @param statePtr Shared pointer to the game state.
 * @param playerVector Vector that contains players.
 * @exception IOException Could not open file Assets/actors.json or Assets/pieces.json for reading.
 * @exception FormatException Format of file Assets/actors.json or Assets/pieces.json is invalid.
 * @return Created instance of IGameRunner.
 * @post GameBoard added
 */
std::shared_ptr<IGameRunner> getGameRunner(std::shared_ptr<IGameBoard> boardPtr,
                                           std::shared_ptr<IGameState> statePtr,
                                           std::vector<std::shared_ptr<IPlayer>> playerVector);

}
}

#endif
