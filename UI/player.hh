#ifndef PLAYER_HH
#define PLAYER_HH

#include "iplayer.hh"
#include "ostream"
#include "memory"


class Player : public Common::IPlayer
{
public:
    Player();
    virtual ~Player();

  virtual int getPlayerId() const;


  virtual void setActionsLeft(unsigned int actionsLeft);


  virtual unsigned int getActionsLeft() const;

   std::shared_ptr<Common::IPlayer> getplayerptr();


private:
    int playerID_;
    int actionsLeft_;
    int gamepoints_;
};

#endif // PLAYER_HH

