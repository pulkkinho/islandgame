#ifndef GAMESTATE_HH
#define GAMESTATE_HH

#include "igamestate.hh"
#include "igamerunner.hh"


class GameState : public Common::IGameState
{
public:
    GameState();
    ~GameState();
    virtual Common::GamePhase currentGamePhase() const;

    virtual int currentPlayer() const;

    virtual void changeGamePhase(Common::GamePhase nextPhase);

    virtual void changePlayerTurn(int nextPlayer);

    void setrunner(std::shared_ptr<Common::IGameRunner> runneri);

    std::shared_ptr<Common::IGameRunner> getrunner();

private:

    // crashaa jos tätä ei oo, en tiiä miks
    int firstplayerid_ = 1;
    Common::GamePhase currentPhase_;
    int currentplayerid_;
    std::shared_ptr<Common::IGameRunner> runner;



};

#endif // GAMESTATE_HH
