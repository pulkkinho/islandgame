#ifndef KOKLAUS_HH
#define KOKLAUS_HH

#include <QWidget>
#include <QPainterPath>

#include "mainwindow.hh"
#include <QPoint>
#include <QVector>
#include <QGraphicsItem>
#include <QObject>

class Widget : public QGraphicsPolygonItem
{

public:
    Widget(std::shared_ptr<Common::Hex> Hexi, std::string Tyyppi,
           int x, int y, int z, std::shared_ptr<GameBoard> board, Common::CubeCoordinate coord,
           std::shared_ptr<Common::IGameRunner> runner, QGraphicsPolygonItem *parent = NULL);

    //void setRunner(std::shared_ptr<Common::IGameRunner> runner);


protected:
    void paint(QPainter *painter,
                const QStyleOptionGraphicsItem *option,
                QWidget *widget);
    QRectF boundingRect() const;
     void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
     bool Pressed;
     bool flip;

private:
     std::shared_ptr<Common::Hex> hexptr;
     std::string tyyppi;
     std::shared_ptr<GameBoard> board_;
     Common::CubeCoordinate coord_;
     std::shared_ptr<Common::IGameRunner> runnerptr;
     int x_;
     int y_;
     int z_;
     QPolygon poly;
     QColor vari;

};

#endif // KOKLAUS_HH
