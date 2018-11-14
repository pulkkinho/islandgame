#include "gameboard.hh"
#include "gamestate.hh"
#include "player.hh"
#include "mainwindow.hh"
#include "configurationwindow.hh"
#include <memory>
#include <QApplication>

#include "igameboard.hh"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QGraphicsScene scene;
    MainWindow w(scene);
    configurationWindow c;
    w.show();
    c.show();
    //GameBoard* kollo;


    //GameEngine engine(Kiikkulauta);
    //
    //MainWindow w(Kiikkulauta);
    //
    //QObject::connect(&Kiikkulauta, SIGNAL(mouseClick(int, int)),
    //                 &engine, SLOT(launchSplash(int, int)));
    //QObject::connect(&engine, SIGNAL(quitGame()), &w, SLOT(close()));
    //
    //w.show();
    return a.exec();
}
