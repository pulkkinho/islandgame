#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsView>
#include "initialize.hh"
#include "gameengine.hh"
#include "igamestate.hh"
#include "igameboard.hh"
#include "pawnitem.hh"
#include <igamerunner.hh>
#include "gameboard.hh"
#include "player.hh"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( QWidget *parent = 0);
    ~MainWindow();


private:

    int kuupo;
    QGraphicsView view_;
    std::vector<std::shared_ptr<Common::IPlayer>> pelaajavihtori;
    Player* player_;
 //   Pawnitem* pawn_;
    Common::Pawn pawn_;


};




#endif // MAINWINDOW_H
