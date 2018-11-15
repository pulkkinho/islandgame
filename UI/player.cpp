#include "player.hh".hh"
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
    // maalla actionsLeft = actionsLeft -1;
    // uiden actionsLeft = actionsLeft - actionsLeft;
    // banaanin syötyä ei muutu
 }

 unsigned int Player::getActionsLeft() const
 {
     return actionsLeft_;
 }

