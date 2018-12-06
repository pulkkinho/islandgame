#include "mainwindow.hh"
#include <memory>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(w.width(),w.height());
    w.showMaximized();

    return a.exec();
}
