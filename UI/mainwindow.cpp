#include "mainwindow.hh"
#include "ui_mainwindow.h"


MainWindow::MainWindow( QWidget *parent) :
    QMainWindow(parent),
    view_(this)


{

    GameBoard peliloota;
    view_.setScene(peliloota.getscene());
    setCentralWidget(&view_);
    setMinimumHeight(500);
    setMinimumWidth(900);


    std::shared_ptr<Common::IGameState> statePtr;
    std::vector<std::shared_ptr<Common::IPlayer>> players;

    std::shared_ptr<Common::IGameRunner> peli = Common::Initialization::getGameRunner(
                std::make_shared<GameBoard>(peliloota),statePtr,players);


  //  QObject::connect(peliloota.getscene(), SIGNAL(mouseClick(int, int)),
   //                  peliloota.getscene(), SLOT(click(int,int)));

}

MainWindow::~MainWindow()
{
}
