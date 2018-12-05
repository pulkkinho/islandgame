#include "hexagon.hh"
#include <QtGui>
#include <iostream>
#include "QBrush"

#include <QGraphicsSceneMouseEvent>
#include "illegalmoveexception.hh"

Widget::Widget(std::shared_ptr<Common::Hex> Hexi, std::string Tyyppi, int x, int y, int z,
               GameBoard* board, Common::CubeCoordinate coord,
               QGraphicsPolygonItem *parent):
    QGraphicsPolygonItem(parent), hexptr(Hexi), tyyppi(Tyyppi), x_(x), y_(y),
    z_(z), board_(board), coord_(coord)
{

    Pressed = false;
    flip = false;
}


void Widget::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{

    int y = x_;
    int x = 2 * z_ + x_;

    int s = 20;
    x= x * 16 * s / 20;
    y= y * s * 1.5;
    QGraphicsItem::mouseDoubleClickEvent(event);


    QPoint clickPosition = event->scenePos().toPoint();
    QPoint keke(clickPosition.x(),clickPosition.y());
    try {
        if(poly.containsPoint(keke,Qt::WindingFill)){
            if(poly[0].y() < clickPosition.y() && poly[3].y() >
                    clickPosition.y() && poly[1].x()-2 > clickPosition.x() &&
                    poly[5].x()+2 < clickPosition.x()){
            //pelivaihe 1
                if( board_->getrunner().get()->currentGamePhase()  == 1){


                    //promt = palyer x plz choose tile to move from
                    // -II- to <-nää jonnekki muualle)
                    if(board_->getMoveCount() == 0){
                        for (auto pawn : board_->getpawnmap()){
                            if(pawn.second.get()->getCoordinates().y == coord_.y &&
                                    pawn.second.get()->getCoordinates().x == coord_.x &&
                                    pawn.second.get()->getCoordinates().z == coord_.z && pawn.second.get()->getPlayerId() == board_->getrunner().get()->currentPlayer()){

                                board_->setMoveTile(coord_, pawn.first);
                                break;
                            }
                        }
                    }
                    else if (board_->getMoveCount() == 1){
                        board_->setTargetTile(coord_);

                        //tarkistetaan, onko kyseessä transportin liikutus
                        if(board_->getHex(board_->getMoveFrom()).get()->getTransports().size() > 0){
                            //voiko pelaaja liikuttaa paattia
                            if(board_->getPaattiMap().at(board_->getPaattiId(board_->getMoveFrom()))->getObject().get()
                                    ->canMove(board_->getrunner().get()->getCurrentPlayer().get()->getPlayerId()) == true){
                            if(board_->getHex(coord_).get()->getPieceType() == "Water"){
                            //liikutetaan alusta ja asetetaan jäljellä olevien liikkeiden määrä
                                board_->getrunner().get()->getCurrentPlayer().get()->setActionsLeft(
                                        board_->getrunner().get()->moveTransport(board_->getMoveFrom(),
                                        coord_,board_->getPaattiId(board_->getMoveFrom())));

                                //liikutetaan myös pawneja transportissa
                                for(auto pawn : board_->getHexMap().at(board_->getMoveFrom()).get()->getPawns()){

                                    board_->getPawnItemMap().at(pawn.get()->getId())->setNewCoord(coord_);
                                    board_->getpawnmap().at(pawn.get()->getId())->setCoordinates(coord_);
                                    board_->getHexMap().at(coord_).get()->addPawn(pawn);
                                    board_->getPawnItemMap().at(pawn.get()->getId())->updateGraphics(board_->getHexMap().at(coord_).get()->getPawnAmount());
                                }
                                //vaihdetaan vuoroa, mikäli tarpeen
                                if(board_->getrunner().get()->getCurrentPlayer().get()->getActionsLeft() <= 0){
                                board_->getstate().get()->changeGamePhase(Common::GamePhase::SINKING);
                                }
                                board_->updateInfobox(board_->getstate().get()->currentGamePhase(), board_->getstate().get()->currentPlayer());
                            }
                            //jos nappula siirretään transportista maalle/korallille
                            else if(board_->getrunner().get()->movePawn(board_->getMoveFrom(),coord_, board_->getMoveFromId()) == 0){
                                board_->getstate().get()->changeGamePhase(Common::GamePhase::SINKING);
                                board_->updateInfobox(board_->getstate().get()->currentGamePhase(), board_->getstate().get()->currentPlayer());
                                board_->updateScoreBoard(board_->getstate().get()->getPlayerPointVector());
                            }
                            }
                        }
                        //liikutetaan pelinappulaa
                        else if(board_->getrunner().get()->movePawn(board_->getMoveFrom(),coord_, board_->getMoveFromId()) == 0){
                            board_->getstate().get()->changeGamePhase(Common::GamePhase::SINKING);

                            board_->updateInfobox(board_->getstate().get()->currentGamePhase(), board_->getstate().get()->currentPlayer());
                            board_->updateScoreBoard(board_->getstate().get()->getPlayerPointVector());
                        }
                    }
                }
            //vaihe 2
            else if( board_->getrunner().get()->currentGamePhase()  == 2){
                if(flip == false){
                    if(poly[0].y() < clickPosition.y() && poly[3].y() > clickPosition.y()
                            && poly[1].x()-2 > clickPosition.x() && poly[5].x()+2 < clickPosition.x()){



                        board_->getrunner()->flipTile(coord_);

                    flip =  true;
                    Pressed = true;
                    if(board_->getrunner().get()->getCurrentPlayer().get()->getPlayerId() == board_->getrunner().get()->playerAmount()){

                        board_->getstate().get()->changeGamePhase(Common::GamePhase::SPINNING);
                        board_->updateInfobox(board_->getstate().get()->currentGamePhase(), board_->getstate().get()->currentPlayer());

                        board_->spinwheel();
                        return;

                    }
                    else{

                    board_->getstate().get()->changeGamePhase(Common::GamePhase::SPINNING);
                    board_->updateInfobox(board_->getstate().get()->currentGamePhase(), board_->getstate().get()->currentPlayer());


                    board_->spinwheel();
                    return;
                    }
                    }
                }
            }

                else if( board_->getrunner().get()->currentGamePhase()  == 3){


                    if(board_->getMoveCount() == 0){
                        for (auto krakeni : board_->getKrakenMap()){

                            if(krakeni.second->getActor().get()->getHex().get()->getCoordinates().y == coord_.y &&
                                    krakeni.second->getActor().get()->getHex().get()->getCoordinates().x == coord_.x &&
                                    krakeni.second->getActor().get()->getHex().get()->getCoordinates().z == coord_.z &&
                                    krakeni.first == board_->getActorId(coord_, board_->getSpinnerResult().first)){

                                board_->setMoveTile(coord_, krakeni.first);
                                break;
                            }
                        }
                    }
                    else if (board_->getMoveCount() == 1){
                        board_->setTargetTile(coord_);
                        board_->getrunner().get()->moveActor(board_->getMoveFrom(),coord_, board_->getMoveFromId(), board_->getSpinnerResult().second);
                        board_->getstate().get()->changeGamePhase(Common::GamePhase::MOVEMENT);
                        board_->updateInfobox(board_->getstate().get()->currentGamePhase(), board_->getstate().get()->currentPlayer());

                        board_->nextTurn();
                    }
                }
            }
            else Pressed = false;
        }
        else Pressed = false;

    }catch(Common::IllegalMoveException msg){
        std::cout << msg.msg() << std::endl;
    }
}

QRectF Widget::boundingRect() const{
    int y = x_;
    int x = 2 * z_ + x_;

    int q = 200;
    int w = 200;
    int s = 20;
    x= x * 16 * s / 20;
    y= y * s * 1.5;
    int a = sqrt(3)*(s/2);
    return QRectF(q-a-x,w-s-y, 40,40);
}

void Widget::paint(QPainter *painter,
                      const QStyleOptionGraphicsItem *option,
                      QWidget *widget){


    int y = x_;
    int x = 2 * z_ + x_;

    int q = 200;
    int w = 200;
    int s = 20;
    x= x * 16 * s / 20;
    y= y * s * 1.5;
    int a = sqrt(3)*(s/2);


    //lähtee alimmasta kulmasta vastapäivään
    poly << QPoint(q-x,w-s-y);
    poly << QPoint(q+a-x,w-s/2-y);
    poly << QPoint(q+a-x,w+s/2-y);
    poly << QPoint(q-x,w+s-y);
    poly << QPoint(q-a-x,w+s/2-y);
    poly << QPoint(q-a-x,w-s/2-y);
    QBrush Brushi;
    if (tyyppi == "Forest"){
        Brushi.setColor((Qt::green));
    }
    if(tyyppi == "Mountain"){
        Brushi.setColor(((Qt::gray)));
    }
    if(tyyppi == "Peak"){
        Brushi.setColor(((Qt::black)));
    }
    if(tyyppi == "Water"){
        Brushi.setColor(((Qt::blue)));
    }
    if(tyyppi == "Coral"){
        Brushi.setColor(((Qt::magenta)));
    }
    if(tyyppi == "Beach"){
        Brushi.setColor(((Qt::yellow)));
    }
    Brushi.setStyle(Qt::SolidPattern);

    if (Pressed == true){
    Brushi.setColor(Qt::blue);
    }
    this->setBrush(Brushi);
    this->setPolygon(poly);

    painter->setBrush(Brushi.color());
    painter->drawPolygon(poly,Qt::WindingFill);
}
