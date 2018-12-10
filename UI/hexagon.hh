#ifndef HEXAGON_HH
#define HEXAGON_HH

#include <QWidget>
#include <QPainterPath>
#include "gameboard.hh"
#include <QPoint>
#include <QVector>
#include <QGraphicsItem>
#include <QObject>

/**
 * @brief The Widget class
 * Luokka hexojen piirtämiselle ja klikkauksille
 */
class Widget : public QGraphicsPolygonItem
{

public:
    /**
     * @brief Widget
     * Luokan constructor
     * @param Hexi
     * @param Tyyppi
     * @param x
     * @param y
     * @param z
     * @param board
     * @param coord
     * @param parent
     */
    Widget(std::shared_ptr<Common::Hex> Hexi, std::string Tyyppi,
           int x, int y, int z, GameBoard* board,
           Common::CubeCoordinate coord, QGraphicsPolygonItem *parent = NULL);



protected:
    /**
     * @brief paint
     * Piirtofunktio hexoille
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter,
                const QStyleOptionGraphicsItem *option,
                QWidget *widget);
    QRectF boundingRect() const;

    /**
      * @brief mouseDoubleClickEvent
      * Klikkauksen funktio
      * @param event
      */
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

#endif // HEXAGON_HH
