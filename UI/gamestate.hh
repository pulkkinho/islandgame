#ifndef GAMESTATE_HH
#define GAMESTATE_HH

#include "igamestate.hh"
#include "igamerunner.hh"
#include "vector"


class GameState : public Common::IGameState
{
public:
    /**
     * @brief GameState
     */
    GameState();
    ~GameState();

    /**
     * @brief currentGamePhase
     * @return
     */
    virtual Common::GamePhase currentGamePhase() const;

    /**
     * @brief currentPlayer
     * @return
     */
    virtual int currentPlayer() const;

    /**
     * @brief changeGamePhase
     * @param nextPhase
     */
    virtual void changeGamePhase(Common::GamePhase nextPhase);

    /**
     * @brief changePlayerTurn
     * @param nextPlayer
     */
    virtual void changePlayerTurn(int nextPlayer);

    /**
     * @brief setrunner
     * @param runneri
     */
    void setrunner(std::shared_ptr<Common::IGameRunner> runneri);

    /**
     * @brief getPawnPerPlayer
     * @return
     */
    int getPawnPerPlayer();

    /**
     * @brief addPointsToPlayer
     * @param points
     * @param playerId
     */
    void addPointsToPlayer(int points, int playerId);

    /**
     * @brief deletePawn
     * @param pawnId
     */
    void deletePawn(int pawnId);

    /**
     * @brief playerPawnsLeft
     * @param playerId
     * @return
     */
    int playerPawnsLeft(int playerId);

    /**
     * @brief initializePlayerPointVector
     */
    void initializePlayerPointVector();

    /**
     * @brief getPlayerPointVector
     * @return
     */
    std::vector<std::pair<int,int>> getPlayerPointVector();

    /**
     * @brief getrunner
     * @return
     */
    std::shared_ptr<Common::IGameRunner> getrunner();

private:
    //!
    Common::GamePhase _gamePhaseId;
    int _playerInTurn = 1;
    int _pawnPerPlayer = 3;
    std::vector<std::pair<int,int>> _playerPointVector;
    std::vector<std::pair<int,int>> _playerPawnVector;
    
    std::shared_ptr<Common::IGameRunner> runner;



};

#endif // GAMESTATE_HH
