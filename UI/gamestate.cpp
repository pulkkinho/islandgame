#include "gamestate.hh"

GameState::GameState():
    Common::IGameState()


{
}
//enum GamePhase { MOVEMENT = 1, SINKING = 2, SPINNING = 3 };

GameState::~GameState()

{

}

//GamePhase GameState::currentGamePhase()
//{
//
//}

int GameState::currentPlayer() const
{

}

void GameState::changeGamePhase(Common::GamePhase nextPhase)
{

}

void GameState::changePlayerTurn(int nextPlayer)
{

}
