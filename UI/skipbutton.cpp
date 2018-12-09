#include "skipbutton.hh"


skipbutton::skipbutton(GameBoard* boardptr,QWidget *parent):
    QWidget(parent),
    board_(boardptr)
{
    skipMovementButton = new QPushButton("Skip movements", this);
    skipMovementButton->show();
    skipMovementButton->isCheckable();
    connect(skipMovementButton, SIGNAL(clicked(bool)), this, SLOT(skipMovement()));

}



bool skipbutton::skipMovement()
{
    //skipMovementButton = new QPushButton("Keep", this);
    board_->getstate().get()->changeGamePhase(Common::GamePhase::SINKING);
    skipMovementButton->setDisabled(true);
    return true;
}


