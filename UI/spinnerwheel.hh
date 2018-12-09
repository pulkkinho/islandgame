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

/**
 * @brief The spinnerwheel class
 * Luo kuvat johon spinnerin pyörivä
 * osuus osoittaa
 */
class spinnerwheel : public QGraphicsItem
{
public:

    /**
     * @brief spinnerwheel
     * Constructor
     * @param parent
     */
    spinnerwheel( QGraphicsItem* parent =NULL);

protected:
    /**
     * @brief paint
     * Spinnerwheelin kuvien piirtofunktio
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const;

};

#endif // SPINNERWHEEL_HH
