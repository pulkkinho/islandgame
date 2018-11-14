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

MainWindow::MainWindow(QGraphicsScene& scene, QWidget *parent) :
    QMainWindow(parent),
    view_(this)


{


    //auto board = Logic::GameEngine::GameEngine.board_;
    //board on pointteri IGameBoardiin


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


    view_.setScene(&scene);
    setCentralWidget(&view_);
    setMinimumHeight(800);
    setMinimumWidth(900);
    scene.setSceneRect(0, 0, 800, 900);
    QPolygon poly(6);
    poly.setPoint(0, 75, 150);
    poly.setPoint(1,  150, 112.5);
    poly.setPoint(2, 150, 37.5);
    poly.setPoint(3, 75, 0);
    poly.setPoint(4, 0, 37.5);
    poly.setPoint(5, 0, 112.5);
    QPen matti;
    QBrush pentti;
    pentti.setColor(Qt::yellow);
    pentti.setStyle(Qt::SolidPattern);
    scene.addPolygon(poly,matti,pentti);

    //std::shared_ptr<GameBoard> mauri = std::make_shared<GameBoard>(scene);

    std::shared_ptr<Common::IGameState> statePtr;
    std::vector<std::shared_ptr<Common::IPlayer>> players;

    //tämä perkele alustaa ruudulle asiat
    //Logic::GameEngine::GameEngine(boardPtr,statePtr,players);

    //tämä perkele tekee jotai
    //note2: tällä saadaan kai pointteri toho edellisee asiaa;
    //note2.1: tarvitaan pointteri gameboardiin ja stateen(?)
    std::shared_ptr<Common::IGameRunner> puu = Common::Initialization::getGameRunner(
                std::make_shared<GameBoard>(),statePtr,players);
    puu.get();




}

MainWindow::~MainWindow()
{
}
