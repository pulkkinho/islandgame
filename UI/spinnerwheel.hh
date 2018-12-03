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
    spinnerwheel(std::shared_ptr<Common::SpinnerLayout>, QGraphicsItem* parent =NULL);

    void paintwheel();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;



private:
     std::shared_ptr<Common::SpinnerLayout> layout_;

};

#endif // SPINNERWHEEL_HH
