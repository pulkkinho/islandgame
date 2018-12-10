#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsView>
#include "initialize.hh"
#include "pawnitem.hh"
#include "gameboard.hh"
#include "player.hh"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( QWidget *parent = 0);
    ~MainWindow();

private:
    QGraphicsView view_;
    Player* player_;
};

#endif // MAINWINDOW_H
