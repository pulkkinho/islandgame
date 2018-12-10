#ifndef PAWNITEM_HH
#define PAWNITEM_HH

#include <QObject>
#include <QWidget>

#include <QPoint>
#include <QVector>
#include <QGraphicsItem>
#include "QGraphicsPixmapItem"
#include "hex.hh"

#include "gamestate.hh"

/**
 * @brief The Pawnitem class
 * Luokka pelaajanappulalle
 */
class Pawnitem : public QGraphicsPixmapItem
{

public:
    /**
     * @brief Pawnitem Constructor
     * @param playerid
     * @param ID
     * @param coord
     * @param scene
     * @param parent
     */
    Pawnitem(int playerid,int ID, Common::CubeCoordinate coord,
             std::shared_ptr<Common::Hex>,
             QGraphicsScene* scene, QGraphicsItem* parent =NULL);

    /**
     * @brief updateGraphics
     * Nappulan grafiikan päivittämisfunktio
     * @param slotti
     * kertoo nappulan paikan hexissä
     */
    void updateGraphics(int slotti);

    /**
     * @brief setNewCoord
     * Antaa uudet koordinaatit nappulalle
     * @param newCoord
     */
    void setNewCoord(Common::CubeCoordinate newCoord);

    /**
     * @brief setHex
     * asettaa tietyn hexan pawnille
     * @param hex
     */
    void setHex(std::shared_ptr<Common::Hex> hex);

    /**
     * @brief getCoord
     * Palauttaa koordinaatit, jossa nappula
     * sijaitsee
     * @return
     */
    Common::CubeCoordinate getCoord();

    /**
     * @brief addToScene
     * Lisää nappulan grafiikoihin
     */
    void addToScene();

private:
    int playerId_;
     int pawnID_;
     Common::CubeCoordinate coord_;
     std::shared_ptr<Common::Hex> hexi_;
     QGraphicsScene* sceneptr_;

     bool vbMousePressed;
};

#endif // PAWNITEM_HH
