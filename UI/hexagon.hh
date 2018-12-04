#ifndef KOKLAUS_HH
#define KOKLAUS_HH

#include <QWidget>
#include <QPainterPath>

#include "mainwindow.hh"
#include <QPoint>
#include <QVector>
#include <QGraphicsItem>
#include <QObject>
#include "gamestate.hh"

class Widget : public QGraphicsPolygonItem
{

public:
    Widget(std::shared_ptr<Common::Hex> Hexi, std::string Tyyppi,
           int x, int y, int z, GameBoard* board, Common::CubeCoordinate coord, QGraphicsPolygonItem *parent = NULL);



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
     int x_;
     int y_;
     int z_;
     GameBoard* board_;
     Common::CubeCoordinate coord_;
     QPolygon poly;
     QColor vari;

};

#endif // KOKLAUS_HH
