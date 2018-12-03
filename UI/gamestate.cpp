#include "gamestate.hh"
#include "iostream"
#include "igamerunner.hh"

GameState::GameState():
    Common::IGameState()

{
}
enum GamePhase { MOVEMENT = 1, SINKING = 2, SPINNING = 3 };

GameState::~GameState()

{

}

Common::GamePhase GameState::currentGamePhase() const
{
    return _gamePhaseId;

}

int GameState::currentPlayer() const
{

    return _playerInTurn;
}

void GameState::changeGamePhase(Common::GamePhase nextPhase)
{
    _gamePhaseId = nextPhase;
}

void GameState::changePlayerTurn(int nextPlayer)
{
    _playerInTurn = nextPlayer ;

}
void GameState::setrunner(std::shared_ptr<Common::IGameRunner> runneri)
{
  runner = runneri;

}

void GameState::addPointsToPlayer(int points, int playerId)
{
    // points --> player
}

void GameState::deletePawn(int pawnId)
{
    // deletoi pawni
}

int GameState::playerPawnsLeft(int playerId)
{
    // returnaa napujen määrä?

}

int GameState::getPawnPerPlayer()
{
    return _pawnPerPlayer;

}

std::shared_ptr<Common::IGameRunner> GameState::getrunner()
{
  return runner;
}



