#include "spinnerwheel.hh"
#include "QTransform"

spinnerwheel::spinnerwheel(std::shared_ptr<Common::SpinnerLayout> spinneri, QGraphicsItem* parent):
    QGraphicsItem(parent),layout_(spinneri)


{
    update();



}



void spinnerwheel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::white);
    painter->drawPixmap(-175,-150,50,50,QPixmap ("://dolphin.png"));
    painter->drawPixmap(-250,-100,50,50,QPixmap ("://shark.png"));
    painter->drawPixmap(-175,-25,50,50,QPixmap ("://kraken.png"));
    painter->drawPixmap(-100,-100,50,50,QPixmap ("://monster.png"));






}

QRectF spinnerwheel::boundingRect() const
{
    return QRectF(-150,-150,50,50);
}
