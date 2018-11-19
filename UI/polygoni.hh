#ifndef POLYGONI_HH
#define POLYGONI_HH
#include "mainwindow.hh"
#include <QObject>


class Polygoni : public QObject, public QGraphicsPolygonItem
{
    Q_OBJECT

public:
    Polygoni(std::shared_ptr<Common::Hex> Hex, QGraphicsScene* scene);
    ~Polygoni();

    void setRunnerptr(std::shared_ptr<Common::IGameRunner> runneri);

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;

signals:
    // Emitted when user clicks a grid square.
   void mouseClick(int x, int y);


    // TODO: Implement this method (and other methods as needed).
    //void flip(int clickX, int clixkY);

public slots:
    // TODO: Implement this method (and other methods as needed).
    void click(int clickX, int clixkY);

private:
    QGraphicsScene* sceneptr_;
    std::shared_ptr<Common::Hex> Hex_;

};

#endif // POLYGONI_HH
