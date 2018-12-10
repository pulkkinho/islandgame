#ifndef PLAYER_HH
#define PLAYER_HH

#include "iplayer.hh"
#include "ostream"
#include "memory"

/**
 * @brief The Player class
 * Pelaajan luokka, joka periytetty
 * Common::IPlayeristä
 */
class Player : public Common::IPlayer
{
public:
    /**
     * @brief Player
     * constructor
     */
    Player();

    /**
     * @brief ~Player
     * Destructor
     */
    ~Player();

    /**
   * @brief getPlayerId
   * playerin ID:n getterfunktio
   * @return PlayerID
   */
    int getPlayerId() const;

    /**
     * @brief setPlayerId
     * Playerin ID:n setterfunktio
     * @param ID
     * ID joka setataan
     */
    void setPlayerId(int ID) ;

    /**
     * @brief setActionsLeft
     * Liikemäärän setterifunktio
     * @param actionsLeft
     */
    void setActionsLeft(unsigned int actionsLeft);

    /**
     * @brief getActionsLeft
     * Liikemäärän getterifunktio
     * @return actionsleft
     */
    unsigned int getActionsLeft() const;

    /**
    * @brief getplayerptr
    * Pelaajapointterin getterifunktio
    * @return playerptr
    */
   std::shared_ptr<Common::IPlayer> getplayerptr();


private:
    int playerID_;
    int actionsLeft_;
    int gamepoints_;
};

#endif // PLAYER_HH

