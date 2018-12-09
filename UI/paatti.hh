#ifndef PAATTI_HH
#define PAATTI_HH

#include <QWidget>
#include <QPainterPath>

#include "hex.hh"
#include <QPoint>
#include <QVector>
#include <QGraphicsItem>
#include <QObject>
#include "transport.hh"
#include "QGraphicsScene"

/**
 * @brief The Paatti class
 * Luokka transporteille
 */
class Paatti : public QGraphicsPixmapItem
{

public:

    /**
     * @brief Paatti
     * luokan constructor
     * @param boat
     * @param coord
     * @param scene
     * @param parent
     */
    Paatti(std::shared_ptr<Common::Transport> boat,
           Common::CubeCoordinate coord, QGraphicsScene* scene,
           QGraphicsItem* parent =NULL);

    /**
     * @brief updateGraphics
     * Funktio grafiikoiden päivitykselle
     */
    void updateGraphics();

    /**
     * @brief setNewCoord
     * Funktio transportin uusien koordinaattien päivitykselle
     * @param coordi
     */
    void setNewCoord(Common::CubeCoordinate coordi);

    /**
     * @brief getObject
     * transportin getterifunktio
     * @return
     */
    std::shared_ptr<Common::Transport> getObject();

    /**
     * @brief getCoord
     * Transportin koordinaattien getterifunktio
     * @return
     */
    Common::CubeCoordinate getCoord();

    /**
     * @brief addToScene
     * funktio, jolla transport lisätään sceneen
     */
    void addToScene();





private:
     QGraphicsScene* sceneptr_;
     std::shared_ptr<Common::Transport> paatti_;
     Common::CubeCoordinate coord_;
};

#endif // PAATTI_HH
