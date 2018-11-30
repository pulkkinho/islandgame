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
    return currentPhase_;

}

int GameState::currentPlayer() const
{

    std::cout<<currentplayerid_<<"  no mutta hyvvöö päovöö"<<std::endl;

    return currentplayerid_;
}

void GameState::changeGamePhase(Common::GamePhase nextPhase)
{

    std::cout<<runner.get()->currentPlayer()<<"  pollo"<<std::endl;
    std::cout<<currentplayerid_<<"  greetings"<<std::endl;
    // tähän kaatuu koska currentplayeris ei oo mittää järkevää --> miten?, ei kaadu jos on firstplayerid
    std::cout<<    runner.get()->getCurrentPlayer().get()->getPlayerId()<<"  pallero"<<std::endl;

    std::cout<<currentPhase_<<"  kuukkuu"<<std::endl;

    currentPhase_ = nextPhase;
    std::cout<<currentPhase_<<"  muuruu"<<std::endl;
}

void GameState::changePlayerTurn(int nextPlayer)
{
    // ei mee tänne, mut en tiiä johtuuks täst
    currentplayerid_ = nextPlayer ;
    std::cout<<currentplayerid_<<"  wololoo"<<std::endl;

}


void GameState::setrunner(std::shared_ptr<Common::IGameRunner> runneri)
{
  runner = runneri;

}

std::shared_ptr<Common::IGameRunner> GameState::getrunner()
{
  return runner;
}



