#ifndef GAMESTATE_HH
#define GAMESTATE_HH

#include "igamestate.hh"


class GameState : public Common::IGameState
{
public:
    GameState();
    ~GameState();
    virtual Common::GamePhase currentGamePhase() const;

    virtual int currentPlayer() const;

    virtual void changeGamePhase(Common::GamePhase nextPhase);

    virtual void changePlayerTurn(int nextPlayer);
};

#endif // GAMESTATE_HH
