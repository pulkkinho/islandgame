#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "configurationwindow.hh"

MainWindow::MainWindow( QWidget *parent) :
    QMainWindow(parent),
    view_(this)
{

    configurationWindow kopo;
    if(kopo.exec()){

    GameBoard peliloota;
    std::shared_ptr<GameBoard> boardptr = std::make_shared<GameBoard>(peliloota);
    view_.setScene(peliloota.getscene());

    GameState gamesteitti;
    std::shared_ptr<GameState> statePtr = std::make_shared<GameState>(gamesteitti);


    std::vector<std::shared_ptr<Common::IPlayer>> pelaajavektori;
    int x=0;

    while (x<kopo.getvalue()){

        std::shared_ptr<Player> uusipelaaja (nullptr);
        uusipelaaja = std::make_shared<Player>();
        uusipelaaja.get()->setPlayerId(x+1);
        uusipelaaja.get()->setActionsLeft(3);
        pelaajavektori.push_back(uusipelaaja);
        x=x+1;
    }
    x=0;


    std::shared_ptr<Common::IGameRunner> peli = Common::Initialization::getGameRunner(boardptr,statePtr,pelaajavektori);

    std::shared_ptr<Common::SpinnerLayout> wheel(nullptr);

    wheel = std::make_shared<Common::SpinnerLayout>();

    boardptr.get()->drawwheel();

    while(x<kopo.getvalue()){
        int pawncounter = 0;
        while (pawncounter<3) {
            pawncounter = pawncounter+1;
            int pawnid = 3*x+pawncounter;
            int playerid = x+1;

            bool lammio = false;
            while (lammio == false){

                int xx = rand() % 22 - 11;
                int yy = rand() % 22 - 11;
                int zz = rand() % 22 - 11;
                for(auto untamo : boardptr.get()->getHexMap()){

                    if(untamo.second.get()->getPieceType() == "Beach"){

                        if (untamo.second.get()->getPawnAmount() < 3){

                            if(untamo.first.x == xx && untamo.first.y == yy && untamo.first.z == zz){
                                Common::CubeCoordinate koordit (xx, yy, zz) ;
                                std::shared_ptr<Common::Pawn> nappu(nullptr);
                                nappu = std::make_shared<Common::Pawn>(pawnid,playerid,koordit);
                                pawn_.setId(3*x+pawncounter,x);
                                boardptr.get()->addtopawnmap(nappu.get()->getId(),nappu);
                                boardptr.get()->addPawn(pelaajavektori.at(x).get()->getPlayerId(),nappu.get()->getId(),untamo.first);
                                lammio = true;
                            }
                        }
                    }
                    else{
                        xx = rand() % 22 - 11;
                        yy = rand() % 22 - 11;
                        zz = rand() % 22 - 11;
                    }
                }
            }
        }
        x=x+1;
    }
    boardptr.get()->setrunner(peli);

    statePtr.get()->setrunner(peli);

    boardptr.get()->setState(statePtr);

    statePtr.get()->changeGamePhase(Common::GamePhase::MOVEMENT);
    statePtr.get()->initializePlayerPointVector();

    boardptr.get()->showInfoBox(statePtr.get()->currentGamePhase(),statePtr.get()->currentPlayer());
    boardptr.get()->showScoreBoard(statePtr.get()->getPlayerPointVector());

    setCentralWidget(&view_);
    setMinimumHeight(500);
    setMinimumWidth(900);
    }
    else{
        exit(0);
    }
}

MainWindow::~MainWindow()
{
}
