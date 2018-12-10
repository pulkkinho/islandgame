#include "spinnerwheel.hh"

spinnerwheel::spinnerwheel( QGraphicsItem* parent):
    QGraphicsItem(parent)

{
    update();
}

// Luodaan kiekon kuvat, johon osoitetaan kiekon toiminnan
// mukaisella tavalla
void spinnerwheel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    widget->isActiveWindow();

    if(option){}
    painter->setBrush(Qt::white);
    painter->drawPixmap(-175,-150,50,50,QPixmap ("://dolphin.png"));
    painter->drawPixmap(-250,-100,50,50,QPixmap ("://shark.png"));
    painter->drawPixmap(-175,-25,50,50,QPixmap ("://kraken.png"));
    painter->drawPixmap(-100,-100,50,50,QPixmap ("://monster.png"));
}

QRectF spinnerwheel::boundingRect() const
{
    return QRectF(-150,-150,200,200);
}
