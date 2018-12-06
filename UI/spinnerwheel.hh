#ifndef SPINNERWHEEL_HH
#define SPINNERWHEEL_HH

#include <QObject>
#include <QWidget>
#include <QPainterPath>

#include "mainwindow.hh"
#include <QPoint>
#include <QVector>
#include <QGraphicsItem>
#include <QObject>

class spinnerwheel : public QGraphicsItem
{
public:
    spinnerwheel( QGraphicsItem* parent =NULL);

    void paintwheel();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

};

#endif // SPINNERWHEEL_HH
