#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "configurationwindow.hh"


MainWindow::MainWindow( QWidget *parent) :
    QMainWindow(parent),
    view_(this)


{

    configurationWindow kopo;
    kopo.exec();
    std::cout<<kopo.getvalue()<<"   kaurapuuroa"<<std::endl;


    GameBoard peliloota;
    std::shared_ptr<GameBoard> boardptr = std::make_shared<GameBoard>(peliloota);
    view_.setScene(peliloota.getscene());

    GameState gamesteitti;
    std::shared_ptr<GameState> statePtr = std::make_shared<GameState>(gamesteitti);

    std::vector<std::shared_ptr<Common::IPlayer>> pelaajavektori;
    int x=0;
    while(x<kopo.getvalue()){
        Player peluri;
        std::shared_ptr<Player> playerptr = std::make_shared<Player>(peluri);
        pelaajavektori.push_back(playerptr);
        x=x+1;
    }



    //setkuupo();

    std::cout << boardptr << " mainwindow boardptr" << std::endl;
    std::shared_ptr<Common::IGameRunner> peli = Common::Initialization::getGameRunner(boardptr,statePtr,pelaajavektori);
    boardptr.get()->setrunner(peli);


    setCentralWidget(&view_);
    setMinimumHeight(500);
    setMinimumWidth(900);

}

MainWindow::~MainWindow()
{
}


