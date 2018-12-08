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
    playernumber = QString::number(playerInTurn_);
    phase = currentGamePhase_;
    this->resize(400,40);
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

void infoBox::gameOver(bool tie, int winner)
{
    if(tie == true){
        kukko->setText("Game over! It's a tie!");
    }
    else {

        playernumber = QString::number(winner);
        phase = QString::fromStdString(" is da winner!");
        kukko->setText("Game over! Player " +playernumber  + phase);
    }
}
