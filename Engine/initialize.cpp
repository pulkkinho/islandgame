#include "gameengine.hh"
#include "piecefactory.hh"
#include "hex.hh"
#include "initialize.hh"

namespace Common {

std::shared_ptr<IGameRunner> getGameRunner(std::shared_ptr<IGameBoard> boardPtr,
                                           std::shared_ptr<IGameState> statePtr,
                                           std::vector<IPlayer*> playerVector)
{

    std::shared_ptr <Logic::GameEngine> runner =
            std::make_shared<Logic::GameEngine>(boardPtr,statePtr,playerVector);

    return runner;

}

}
