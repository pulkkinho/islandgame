#include "gamestate.hh"
#include "iostream"

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
    std::cout << "tarkoitus ei ollut kiertää" << std::endl;
}

int GameState::currentPlayer() const
{
    std::cout << "tarkoitus ei ollut kiertää" << std::endl;
}

void GameState::changeGamePhase(Common::GamePhase nextPhase)
{
    std::cout << "tarkoitus ei ollut kiertää" << std::endl;
}

void GameState::changePlayerTurn(int nextPlayer)
{
    std::cout << "tarkoitus ei ollut kiertää" << std::endl;
}



