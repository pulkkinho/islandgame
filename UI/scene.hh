#ifndef SCENE_HH
#define SCENE_HH

#include "QGraphicsScene"
#include <iostream>
#include "mainwindow.hh"

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene(GameBoard* board, QObject* parent = nullptr);
    ~Scene();


protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);

signals:
    // Emitted when user clicks a grid square.
   void mouseClick(int x, int y);


    // TODO: Implement this method (and other methods as needed).
    //void flip(int clickX, int clixkY);

public slots:
    // TODO: Implement this method (and other methods as needed).
    void click(int clickX, int clixkY);



private:

    std::shared_ptr<Common::IGameRunner> runnerptr_;
    GameBoard* board_;
};

#endif // SCENE_HH
