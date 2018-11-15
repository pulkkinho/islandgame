#include "mainwindow.hh"
#include "ui_mainwindow.h"


MainWindow::MainWindow( QWidget *parent) :
    QMainWindow(parent),
    view_(this)


{

    GameBoard peliloota;

    view_.setScene(peliloota.getscene());
    setCentralWidget(&view_);
    setMinimumHeight(800);
    setMinimumWidth(900);
    peliloota.getscene()->setSceneRect(0, 0, 1200, 1200);


    std::shared_ptr<Common::IGameState> statePtr;
    std::vector<std::shared_ptr<Common::IPlayer>> players;

    std::shared_ptr<Common::IGameRunner> peli = Common::Initialization::getGameRunner(
                std::make_shared<GameBoard>(peliloota),statePtr,players);


}

MainWindow::~MainWindow()
{
}
