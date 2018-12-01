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

    std::cout<<_playerInTurn<<"  no mutta hyvvöö päovöö"<<std::endl;

    return _playerInTurn;
}

void GameState::changeGamePhase(Common::GamePhase nextPhase)
{

    std::cout<<runner.get()->currentPlayer()<<"  pollo"<<std::endl;
    std::cout<<_playerInTurn<<"  greetings"<<std::endl;
    // tähän kaatuu koska currentplayeris ei oo mittää järkevää --> miten?, ei kaadu jos on firstplayerid
    std::cout<<    runner.get()->getCurrentPlayer().get()->getPlayerId()<<"  pallero"<<std::endl;
    std::cout<<    runner.get()->playerAmount()<<"  pollllero"<<std::endl;

    std::cout<<_gamePhaseId<<"  kuukkuu"<<std::endl;

    _gamePhaseId = nextPhase;
    std::cout<<_gamePhaseId<<"  muuruu"<<std::endl;
}

void GameState::changePlayerTurn(int nextPlayer)
{
    // ei mee tänne, mut en tiiä johtuuks täst
    _playerInTurn = nextPlayer ;
    std::cout<<_playerInTurn<<"  wololoo"<<std::endl;

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



