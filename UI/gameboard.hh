#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include <map>
#include <unordered_map>
#include "cmath"
#include <iostream>

#include "QPushButton"
#include "QGraphicsScene"
#include "igamerunner.hh"
#include "gameengine.hh"
#include "mainwindow.hh"

#include "igameboard.hh"
#include "infobox.hh"
#include "scoreboardui.hh"
#include "pawnitem.hh"
#include "monsters.hh"
#include "paatti.hh"
#include "spinneranimation.hh"

/**
 * @brief The GameBoard class
 * Pelilaudan luokka, periytetty
 * IGameBoardista
 */
class GameBoard : public Common::IGameBoard
{
public:
    /**
     * @brief GameBoard
     * Constructor
     */
    GameBoard();
    ~GameBoard();

    /**
     * @brief checkTileOccupation
     * Tarkastaa hexan tilan annetuilla koordinaateilla
     * @param tileCoord
     * @return
     */
    virtual int checkTileOccupation(Common::CubeCoordinate tileCoord) const;

    /**
     * @brief isWaterTile
     * Tarkastaa onko hexa vesityyppiä annetuilla koordinaateilla
     * @param tileCoord
     * @return
     */
    virtual bool isWaterTile(Common::CubeCoordinate tileCoord) const;

    /**
     * @brief getHex
     * Hexan getterifunktio
     * @param hexCoord
     * @return
     */
    virtual std::shared_ptr<Common::Hex> getHex(Common::CubeCoordinate hexCoord) const;

    /**
     * @brief addPawn
     * Pawnin lisäysfunktio. Lisäys tehdään pelaajajalle
     * jonka ID vastaa parametrin ID:tä.
     * @param playerId
     * @param pawnId
     */
    virtual void addPawn(int playerId, int pawnId);

    /**
     * @brief addPawn
     * Pawnin lisäysfunktio. Lisäys tehdään pelaajajalle
     * jonka ID vastaa parametrin ID:tä. Lisätään parametrinä
     * annetulle koordinaatille.
     * @param playerId
     * @param pawnId
     * @param coord
     */
    virtual void addPawn(int playerId, int pawnId, Common::CubeCoordinate coord);

    /**
     * @brief movePawn
     * Pawnin liikutusfunktio, jossa parametrit kertovat mitä pawnia
     * liikutetaan ja mikä on uusi kohdekoordinaatti
     * @param pawnId
     * @param pawnCoord
     */
    virtual void movePawn(int pawnId, Common::CubeCoordinate pawnCoord);

    /**
     * @brief removePawn
     * Pawnin poistofunktio
     * @param pawnId
     */
    virtual void removePawn(int pawnId);

    /**
     * @brief addActor
     * Actorin lisäysfunktio
     * @param actor
     * @param actorCoord
     */
    virtual void addActor(std::shared_ptr<Common::Actor> actor, Common::CubeCoordinate actorCoord);

    /**
     * @brief moveActor
     * Actorin liikutusfunktio
     * @param actorId
     * @param actorCoord
     */
    virtual void moveActor(int actorId, Common::CubeCoordinate actorCoord);

    /**
     * @brief removeActor
     * Actorin poistofunktio
     * @param actorId
     */
    virtual void removeActor(int actorId);

    /**
     * @brief addHex
     * Hexan luontifunktio
     * @param newHex
     */
    virtual void addHex(std::shared_ptr<Common::Hex> newHex);

    /**
     * @brief addTransport
     * Transportin lisäysfunktio
     * @param transport
     * @param coord
     */
    virtual void addTransport(std::shared_ptr<Common::Transport> transport, Common::CubeCoordinate coord);

    /**
     * @brief moveTransport
     * Transportin liikutusfunktio
     * @param id
     * @param coord
     */
    virtual void moveTransport(int id, Common::CubeCoordinate coord);

    /**
     * @brief removeTransport
     * Transportin poistofunktio
     * @param id
     */
    virtual void removeTransport(int id);

    /**
     * @brief drawwheel
     * Spinnerin piirtofunktio
     */
    void drawwheel();

    /**
     * @brief setLabel
     * Labelin setterifunktio
     */
    void setLabel(Common::GamePhase,int);

    /**
     * @brief getstate
     * GameStaten getterifunktio
     * @return
     */
    std::shared_ptr<GameState> getstate();

    /**
     * @brief spinwheel
     * SpinWheelin pyöräytysfunktio
     * @return
     */
    std::pair<std::string,std::string> spinwheel();

    /**
     * @brief getscene
     * scenen getterifunktio
     * @return
     */
    QGraphicsScene* getscene();

    /**
     * @brief setMoveTile
     * @param coord
     * @param id
     */
    void setMoveTile(Common::CubeCoordinate coord, int id);

    /**
     * @brief setTargetTile
     * @param coord
     */
    void setTargetTile(Common::CubeCoordinate coord);

    /**
     * @brief setrunner
     * IGameRunnerin setterifunktio
     * @param runneri
     */
    void setrunner(std::shared_ptr<Common::IGameRunner> runneri);

    /**
     * @brief getrunner
     * IGameRunnerin getterifunktio
     * @return
     */
    std::shared_ptr<Common::IGameRunner> getrunner();

    /**
     * @brief getpawnmap
     * Pawnmapin getterifunktio
     * @return
     */
    std::unordered_map<int, std::shared_ptr<Common::Pawn>> getpawnmap();

    /**
     * @brief getHexMap
     * Hexmapin getterifunktio
     * @return
     */
    std::map<Common::CubeCoordinate, std::shared_ptr<Common::Hex>> getHexMap();

    /**
     * @brief addtopawnmap
     */
    void addtopawnmap(int,std::shared_ptr<Common::Pawn>);

    /**
     * @brief getMoveCount
     * @return
     */
    int getMoveCount();

    /**
     * @brief getMoveFromId
     * @return
     */
    int getMoveFromId();

    /**
     * @brief setState
     * @param steitti
     */
    void setState(std::shared_ptr<GameState> steitti);

    /**
     * @brief getMoveFrom
     * @return
     */
    Common::CubeCoordinate getMoveFrom();

    /**
     * @brief getPawnItemMap
     * @return
     */
    std::map<int, Pawnitem*> getPawnItemMap();

    /**
     * @brief showScoreBoard
     */
    void showScoreBoard(std::vector<std::pair<int,int>>);

    /**
     * @brief updateScoreBoard
     */
    void updateScoreBoard(std::vector<std::pair<int,int>>);

    /**
     * @brief showInfoBox
     */
    void showInfoBox(Common::GamePhase, int);

    /**
     * @brief updateInfobox
     */
    void updateInfobox(Common::GamePhase, int);

    /**
     * @brief getSpinnerResult
     * @return
     */
    std::pair<std::string,std::string> getSpinnerResult();

    /**
     * @brief getActorId
     * @param coord
     * @param tyyppi
     * @return
     */
    int getActorId(Common::CubeCoordinate coord, std::string tyyppi);

    /**
     * @brief getPaattiId
     * @param coord
     * @return
     */
    int getPaattiId(Common::CubeCoordinate coord);

    /**
     * @brief nextTurn
     */
    void nextTurn();

    /**
     * @brief getmonstersMap
     * @return
     */
    std::map<int, monsters*> getmonstersMap();

    /**
     * @brief getPaattiMap
     * @return
     */
    std::map<int, Paatti*> getPaattiMap();

    bool checkPoints( Common::CubeCoordinate);

    bool checkIfGameOver();

    void setScene();

    void addHextoScene();

    void addPawnsToScene();

    std::string getFlipType();

    std::map<int, std::shared_ptr<Common::Actor>> getActorObjectMap();

    void addToScene(Common::CubeCoordinate);

    std::map<int, std::shared_ptr<Common::Transport>> getTransportMap();


    spinneranimation* spinner;
    QGraphicsProxyWidget *proxy;
    QLabel *spinnermovement;
private:

    //!
    std::map<Common::CubeCoordinate, std::shared_ptr<Common::Hex>> HexMap;
    std::unordered_map<int, std::shared_ptr<Common::Pawn>> pawnMap;
    std::map<int, Pawnitem*> pawnItemMap;
    std::map<int, monsters*> monstersMap;

    std::string flipType;

    std::map<int, Paatti*> paattiMap;
    std::map<int, std::shared_ptr<Common::Transport>> transportMap;
    std::map<int, Common::CubeCoordinate> actorMap;
    std::map<int, std::shared_ptr<Common::Actor>> actorObjectMap;

    std::shared_ptr<Common::IGameRunner> runner;

    std::pair<std::string,std::string> spinnerResult;

    std::shared_ptr<Common::SpinnerLayout> wheel_;

    std::shared_ptr<GameState> state;

    QGraphicsScene* sceneptr_;
    Common::CubeCoordinate moveFrom;
    Common::CubeCoordinate moveTo;
    int moveFromId;
    int moveCount = 0;

    std::shared_ptr<scoreboardUI> scoreboard;
    std::shared_ptr<infoBox> infobox;
};

#endif // GAMEBOARD_HH

