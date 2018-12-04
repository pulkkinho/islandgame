#include "infobox.hh"
#include "iostream"

infoBox::infoBox(Common::GamePhase currentGamePhase, int playerInTurn, QWidget *parent):
    currentGamePhase_(currentGamePhase),
    playerInTurn_(playerInTurn),
    QWidget(parent)
{

    playernumber = QString::number(playerInTurn_);

    kukko = new QLabel();
    updateGraphics();
}


void infoBox::updateGraphics()
{
    this->resize(30,30);

    QGridLayout *vbl = new QGridLayout(this);

    if(currentGamePhase_ == 1){
        phase = QString::fromStdString(" please move your pawn(s)");
    }
    if(currentGamePhase_ == 2){
        phase = QString::fromStdString(" please sink a tile");
    }
    if(currentGamePhase_ == 3){
        phase = QString::fromStdString(" please move an actor the spinner points to");
    }


    kukko->setText("Player " +playernumber+phase);

    vbl->addWidget(kukko,0,1);

}

void infoBox::setNew(Common::GamePhase currenPhase, int playerInTurn)
{
    currentGamePhase_ = currenPhase;
    playerInTurn_ = playerInTurn;

}