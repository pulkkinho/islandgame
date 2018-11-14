#include "mainwindow.hh"
#include "initialize.hh"
#include "igamestate.hh"
#include "igameboard.hh"
#include "gameengine.hh"
#include <igamerunner.hh>
#include <QGraphicsItem>
#include <QGraphicsView>
#include "ui_mainwindow.h"
#include "gameboard.hh"

#include <QDebug>
#include <QLayout>
#include <QWidget>
#include <QTimer>

MainWindow::MainWindow( QWidget *parent) :
    QMainWindow(parent),
    view_(this)


{

    //std::shared_ptr<GameBoard> aamukassa = std::make_shared<GameBoard>(GameBoard());

    //auto board = Logic::GameEngine::GameEngine.board_;
    //board on pointteri IGameBoardiin
    GameBoard aamukassa;

    //auto pObj = std::make_shared<oddball>();
   //QGraphicsScene* scene = new QGraphicsScene;
   //
   //QGraphicsView* view_ = new QGraphicsView(this);
   //
   //view_ = new QGraphicsView(this);
   //view_->setScene(scene);
   //setCentralWidget(view_);
   //setMinimumHeight(800);
   //setMinimumWidth(900);
   //scene->setSceneRect(0, 0, 600, 600);

    view_.setScene(aamukassa.getscene());
    setCentralWidget(&view_);
    setMinimumHeight(800);
    setMinimumWidth(900);
    aamukassa.getscene()->setSceneRect(0, 0, 1200, 1200);

    //std::shared_ptr<GameBoard> mauri = std::make_shared<GameBoard>(scene);

    std::shared_ptr<Common::IGameState> statePtr;
    std::vector<std::shared_ptr<Common::IPlayer>> players;

    //tämä perkele alustaa ruudulle asiat
    //Logic::GameEngine::GameEngine(boardPtr,statePtr,players);

    //tämä perkele tekee jotai
    //note2: tällä saadaan kai pointteri toho edellisee asiaa;
    //note2.1: tarvitaan pointteri gameboardiin ja stateen(?)
    std::shared_ptr<Common::IGameRunner> puu = Common::Initialization::getGameRunner(
                std::make_shared<GameBoard>(aamukassa),statePtr,players);
    puu.get();




}

MainWindow::~MainWindow()
{
}
