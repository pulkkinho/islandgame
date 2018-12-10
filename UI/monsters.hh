#ifndef MONSTERS_HH
#define MONSTERS_HH

#include <QObject>
#include <QWidget>

#include <QWidget>
#include <QPainterPath>

#include "hex.hh"
#include <QPoint>
#include <QVector>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsScene>

/**
 * @brief The monsters class
 * Luokka actoreille
 */
class monsters : public QGraphicsPixmapItem
{

public:
    /**
     * @brief monsters
     * Constructor luokalle
     * @param monsters
     * @param coord
     * @param scene
     * @param parent
     */
    monsters(std::shared_ptr<Common::Actor> monsters,
             Common::CubeCoordinate coord,
             QGraphicsScene* scene, QGraphicsItem* parent =NULL);

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
     * @brief getType
     * Actorin tyypin getterifunktio
     * @return
     */
    std::string getType();

    /**
     * @brief getActor
     * Actorin getterifunktio
     * @return
     */
    std::shared_ptr<Common::Actor> getActor();

    /**
     * @brief setmonsters
     * Actorin setterifunktio
     * @param aktori
     */
    void setmonsters(std::shared_ptr<Common::Actor> aktori);

    /**
     * @brief getCoord
     * Acotrin koordinaattien getterifunktio
     * @return
     */
    Common::CubeCoordinate getCoord();

    /**
     * @brief addToScene
     * Funktio, jolla actor lisätään grafiikoihin
     */
    void addToScene();
private:
     std::shared_ptr<Common::Actor> monsters_;
     Common::CubeCoordinate coord_;
     QGraphicsScene* sceneptr_;



};
#endif // MONSTERS_HH
