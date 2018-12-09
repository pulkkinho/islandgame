#ifndef SKIPBUTTON_HH
#define SKIPBUTTON_HH

#include <QObject>
#include <QWidget>
#include "QPushButton"
#include "QtWidgets"
#include "gameboard.hh"

class skipbutton : public QWidget
{
    Q_OBJECT

public:
    skipbutton(GameBoard *board,QWidget* parent = NULL);


public slots:

    bool skipMovement();

private:
    QPushButton* skipMovementButton;
    GameBoard* board_;

};

#endif // SKIPBUTTON_HH
