#ifndef KOKLAUS_HH
#define KOKLAUS_HH

#include <QWidget>
#include <QPainterPath>

#include "mainwindow.hh"
#include <QPoint>
#include <QVector>

class Widget : public QWidget
{
  Q_OBJECT

public:
  Widget(QGraphicsScene* majyur,QWidget *parent = 0);
  ~Widget();

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  QPainterPath getPath() const;
  QRegion getRegion() const;

private:
  int width = 100;
  int height = 100;
  QVector<QPoint> points;

  QGraphicsScene* sceneptr_;
};

#endif // KOKLAUS_HH
