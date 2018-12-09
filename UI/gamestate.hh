#ifndef GAMESTATE_HH
#define GAMESTATE_HH

#include "igamestate.hh"
#include "igamerunner.hh"
#include "vector"

/**
 * @brief The GameState class
 * Gamestaten luokka, joka kertoo pelin tilasta,
 * periytetty Common::IGameStatesta
 */
class GameState : public Common::IGameState
{
public:
    /**
     * @brief GameState
     * Luokan constructor
     */
    GameState();
    ~GameState();

    /**
     * @brief currentGamePhase
     * Kertoo pelin sen hetkisen Phasen
     * @return
     */
    virtual Common::GamePhase currentGamePhase() const;

    /**
     * @brief currentPlayer
     * kertoo vuorossa olevan pelaajan
     * @return
     */
    virtual int currentPlayer() const;

    /**
     * @brief changeGamePhase
     * vaihtaa pelin Phasea seuraavaan
     * @param nextPhase
     */
    virtual void changeGamePhase(Common::GamePhase nextPhase);

    /**
     * @brief changePlayerTurn
     * Vaihtaa pelaajan vuoron seuraavalle
     * @param nextPlayer
     */
    virtual void changePlayerTurn(int nextPlayer);

    /**
     * @brief setrunner
     * statelle tuotavan IGameRunnerin setterifunktio
     * @param runneri
     */
    void setrunner(std::shared_ptr<Common::IGameRunner> runneri);

    /**
     * @brief getPawnPerPlayer
     * Palauttaa montako nappulaa pelaajilla oli alussa
     * @return
     */
    int getPawnPerPlayer();

    /**
     * @brief addPointsToPlayer
     * Lisää pisteitä halutulle pelaajalle
     * @param points
     * @param playerId
     */
    void addPointsToPlayer(int points, int playerId);

    /**
     * @brief initializePlayerPointVector
     * Pelaaja-pistevektorin alustusfunktio
     */
    void initializePlayerPointVector();

    /**
     * @brief getPlayerPointVector
     * Pelaaja-pistevektorin getterifunktio
     * @return
     */
    std::vector<std::pair<int,int>> getPlayerPointVector();

    /**
     * @brief getrunner
     * IGameRunnerin getterifunktio
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
