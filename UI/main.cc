#include "player.hh"
#include "mainwindow.hh"
#include "configurationwindow.hh"
#include <memory>
#include <QApplication>

#include "igameboard.hh"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    configurationWindow c;

    if(c.exec() == 1){
        w.show();
    }
    return a.exec();
}
