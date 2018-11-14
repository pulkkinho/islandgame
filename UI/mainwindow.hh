#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gameboard.hh"
#include "initialize.hh"
#include "gameengine.hh"
#include <QGraphicsItem>
#include <QGraphicsView>

#include <QDebug>
#include <QLayout>
#include <QWidget>
#include <QTimer>

#include <QPushButton>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QGraphicsScene &scene, QWidget *parent = 0);
    ~MainWindow();


private:

    QGraphicsView view_;


};




#endif // MAINWINDOW_H
