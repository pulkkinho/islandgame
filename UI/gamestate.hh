#ifndef GAMESTATE_HH
#define GAMESTATE_HH

#include "igamestate.hh"
#include "igamerunner.hh"
#include "vector"


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

    int getPawnPerPlayer();

    void addPointsToPlayer(int points, int playerId);

    void deletePawn(int pawnId);

    int playerPawnsLeft(int playerId);

    std::shared_ptr<Common::IGameRunner> getrunner();

private:

    Common::GamePhase _gamePhaseId;
    int _playerInTurn = 1;
    int _pawnPerPlayer = 3;
    std::vector<std::pair<int,int>> _playerPointVector;
    std::vector<std::pair<int,int>> _playerPawnVector;
    
    std::shared_ptr<Common::IGameRunner> runner;



};

#endif // GAMESTATE_HH
