#include "koklaus.hh"

#include <QPainter>
#include <QPoint>
#include <QPainterPath>
#include <QBrush>
#include <QPolygon>
#include <QVector>

#include <QPainter>
#include <QPoint>
#include <QPainterPath>
#include <QBrush>
#include <QPolygon>
#include <QVector>

Widget::Widget(QGraphicsScene* majyur,QWidget *parent)
  : QWidget(parent),


    sceneptr_(majyur),
    points(3)
{
    points[0] = QPoint(20, 20);
    points[1] = QPoint(80, 20);
    points[2] = QPoint(50, 80);

    setFixedSize(width, height);
    setMask(getRegion());
}

Widget::~Widget()
{

}

QPainterPath Widget::getPath() const
{
    QPainterPath path;
    path.moveTo(points[0]);
    path.lineTo(points[1]);
    path.lineTo(points[2]);
    path.lineTo(points[0]);

    return path;
}

QRegion Widget::getRegion() const
{
  return QRegion(QPolygon(points));
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainterPath path = getPath();

    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.fillPath(path, QBrush(Qt::black));

    sceneptr_->addWidget(this);

}
