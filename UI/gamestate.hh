#ifndef GAMESTATE_HH
#define GAMESTATE_HH

#include "igamestate.hh"


class GameState : public Common::IGameState
{
//    enum GamePhase { MOVEMENT = 1, SINKING = 2, SPINNING = 3 };
public:
    GameState();
    ~GameState();

//    virtual GamePhase currentGamePhase()  ;


    virtual int currentPlayer() const;


    virtual void changeGamePhase(Common::GamePhase nextPhase);


    virtual void changePlayerTurn(int nextPlayer);
};

#endif // GAMESTATE_HH
