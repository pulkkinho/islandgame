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

        //std::shared_ptr<Common::Pawn> nappu(nullptr);
        //
        //nappu = std::make_shared<Common::Pawn>(pawnid,playerid,koordit);


        std::shared_ptr<Player> uusipelaaja (nullptr);
        uusipelaaja = std::make_shared<Player>();
        uusipelaaja.get()->setPlayerId(x+1);


        std::cout<<uusipelaaja.get()->getPlayerId()<<"hermurderer"<<std::endl;
       // kattoo miten tä kannattais toteuttaa pelaajavektori.push_back(kana);


        //Player peluri;
        //std::shared_ptr<Player> playerptr = std::make_shared<Player>(peluri);
        //pelaajavektori.push_back(playerptr);
        int y = 0;
        while (y<3) {
            y=y+1;
            int pawnid = 3*x+y;
            int playerid = x+1;
            Common::CubeCoordinate koordit (-1-x*5,-1-x*5,0-x*5) ;
            std::shared_ptr<Common::Pawn> nappu(nullptr);

            nappu = std::make_shared<Common::Pawn>(pawnid,playerid,koordit);

           pawn_.setId(3*x+y,x);
        //   //pawn_->setId(kana.get()->getPlayerId(),kana.get()->getPlayerId());
        //   //std::cout<<pawn_->getId()<<"Eva"<<std::endl;
        //
            std::cout<<nappu.get()->getId()<<"pawninid   "
                    <<nappu.get()->getPlayerId()<<"  flies away   "
                   <<nappu.get()<<"  flies away   "<<nappu<<std::endl;

            boardptr.get()->addtopawnmap(nappu.get()->getId(),nappu);

            std::cout <<&peliloota<< "mur" << std::endl;
            std::cout <<boardptr<< "muuur" << std::endl;


            std::cout <<peliloota.getpawnmap().size()<< "miuuuuu" << std::endl;

           // Common::Pawn nappu;
           // std::shared_ptr<Common::Pawn> pawnptr = std::make_shared<Common::Pawn>(nappu);
           // std::cout<<nappu.getId()<<"PERKEEEEELEEEEE"<<std::endl;
           // std::cout<<pawnptr.get()->getId()<<"PERKEEEEELEEEEE"<<std::endl;
           // std::cout<<kana->getPlayerId()<<"SAATANA"<<std::endl;

          //  peliloota.addPawn(kana.get()->getPlayerId(),nappu.get()->getId(),Common::CubeCoordinate(-1-x*5,-1-x*5,0-x*5));


        }
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


