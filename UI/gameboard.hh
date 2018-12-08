#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include <map>
#include <unordered_map>
#include "QGraphicsScene"
#include <QGraphicsItem>
#include <QGraphicsView>
#include "igamerunner.hh"
#include "cmath"
#include "gameengine.hh"
#include "mainwindow.hh"

#include "igameboard.hh"
#include <iostream>
#include "QPushButton"
#include "infobox.hh"
#include "scoreboardui.hh"
#include "monsters.hh"
#include "paatti.hh"
#include "spinneranimation.hh"

class GameBoard : public Common::IGameBoard
{



public:
    /**
     * @brief GameBoard
     */
    GameBoard();
    ~GameBoard();

    /**
     * @brief checkTileOccupation
     * @param tileCoord
     * @return
     */
    virtual int checkTileOccupation(Common::CubeCoordinate tileCoord) const;

    /**
     * @brief isWaterTile
     * @param tileCoord
     * @return
     */
    virtual bool isWaterTile(Common::CubeCoordinate tileCoord) const;

    /**
     * @brief getHex
     * @param hexCoord
     * @return
     */
    virtual std::shared_ptr<Common::Hex> getHex(Common::CubeCoordinate hexCoord) const;

    /**
     * @brief addPawn
     * @param playerId
     * @param pawnId
     */
    virtual void addPawn(int playerId, int pawnId);

    /**
     * @brief addPawn
     * @param playerId
     * @param pawnId
     * @param coord
     */
    virtual void addPawn(int playerId, int pawnId, Common::CubeCoordinate coord);

    /**
     * @brief movePawn
     * @param pawnId
     * @param pawnCoord
     */
    virtual void movePawn(int pawnId, Common::CubeCoordinate pawnCoord);

    /**
     * @brief removePawn
     * @param pawnId
     */
    virtual void removePawn(int pawnId);

    /**
     * @brief addActor
     * @param actor
     * @param actorCoord
     */
    virtual void addActor(std::shared_ptr<Common::Actor> actor, Common::CubeCoordinate actorCoord);

    /**
     * @brief moveActor
     * @param actorId
     * @param actorCoord
     */
    virtual void moveActor(int actorId, Common::CubeCoordinate actorCoord);

    /**
     * @brief removeActor
     * @param actorId
     */
    virtual void removeActor(int actorId);

    /**
     * @brief addHex
     * @param newHex
     */
    virtual void addHex(std::shared_ptr<Common::Hex> newHex);

    /**
     * @brief addTransport
     * @param transport
     * @param coord
     */
    virtual void addTransport(std::shared_ptr<Common::Transport> transport, Common::CubeCoordinate coord);

    /**
     * @brief moveTransport
     * @param id
     * @param coord
     */
    virtual void moveTransport(int id, Common::CubeCoordinate coord);

    /**
     * @brief removeTransport
     * @param id
     */
    virtual void removeTransport(int id);

    /**
     * @brief drawwheel
     */
    void drawwheel();

    /**
     * @brief getpushbutton
     * @return
     */
    QPushButton* getpushbutton();

    /**
     * @brief setLabel
     */
    void setLabel(Common::GamePhase,int);

    /**
     * @brief getstate
     * @return
     */
    std::shared_ptr<GameState> getstate();

    /**
     * @brief spinwheel
     * @return
     */
    std::pair<std::string,std::string> spinwheel();

    /**
     * @brief getscene
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
     * @param runneri
     */
    void setrunner(std::shared_ptr<Common::IGameRunner> runneri);

    /**
     * @brief getrunner
     * @return
     */
    std::shared_ptr<Common::IGameRunner> getrunner();

    /**
     * @brief getpawnmap
     * @return
     */
    std::unordered_map<int, std::shared_ptr<Common::Pawn>> getpawnmap();

    /**
     * @brief getHexMap
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

    spinneranimation* spinner;
    QGraphicsProxyWidget *proxy;
    QLabel *spinnermovement;
private:

    //!
    std::map<Common::CubeCoordinate, std::shared_ptr<Common::Hex>> HexMap;
    std::unordered_map<int, std::shared_ptr<Common::Pawn>> pawnMap;
    std::map<int, Pawnitem*> pawnItemMap;
    std::map<int, monsters*> monstersMap;

    std::map<int, Paatti*> paattiMap;
    std::map<int, Common::CubeCoordinate> actorMap;

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

