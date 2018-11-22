#include "player.hh"
#include "piecefactory.hh"
#include "hex.hh"
#include "QGraphicsPolygonItem"
#include "QGraphicsScene"
#include "QPainter"



Player::Player():
    Common::IPlayer()
{

}
 Player::~Player()
 {

 }

 int Player::getPlayerId() const
 {
     return playerID_;
 }

 void Player::setActionsLeft(unsigned int actionsLeft)
 {
     //tekeekö itsestään nämä?
    // maalla actionsLeft = actionsLeft -1;
    // uiden actionsLeft = actionsLeft - actionsLeft;
    // banaanin syötyä ei muutu

    actionsLeft_ = actionsLeft;
 }

 unsigned int Player::getActionsLeft() const
 {
     return actionsLeft_;
 }

 std::shared_ptr<Common::IPlayer> Player::getplayerptr()
 {
     return playerptr;
 }

