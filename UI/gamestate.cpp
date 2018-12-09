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

void GameState::addPointsToPlayer(int playerId, int points)
{
    int x = 0;
    for(auto pair : _playerPointVector){
        if(playerId == pair.first){
            _playerPointVector.at(x).second =_playerPointVector.at(x).second + points;
            pair.first = pair.second + points;
        }
        x = x + 1;
    }
}

void GameState::initializePlayerPointVector()
{
    int amount = getrunner().get()->playerAmount();
    int x = 1;
    while(x <= amount){//jälkimmäinen on pisteet
        _playerPointVector.push_back(std::make_pair(x,0));
        x = x+1;
    }
}

std::vector<std::pair<int,int>> GameState::getPlayerPointVector()
{
    return _playerPointVector;
}

int GameState::getPawnPerPlayer()
{
    return _pawnPerPlayer;
}

std::shared_ptr<Common::IGameRunner> GameState::getrunner()
{
  return runner;
}
