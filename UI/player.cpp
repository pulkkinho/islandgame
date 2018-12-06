#include "player.hh"
#include "piecefactory.hh"
#include "hex.hh"
#include "QGraphicsPolygonItem"
#include "QGraphicsScene"
#include "QPainter"
#include "iostream"

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

 int Player::setPlayerId(int ID)
 {
     playerID_ =  ID;
 }

 void Player::setActionsLeft(unsigned int actionsLeft)
 {
     //tekeekö itsestään nämä?
    // maalla actionsLeft = actionsLeft -1;
    // uiden actionsLeft = actionsLeft - actionsLeft;

    actionsLeft_ = actionsLeft;
 }

 unsigned int Player::getActionsLeft() const
 {
     return actionsLeft_;
 }
