#include <QString>
#include <QtTest>
#include <vector>

#include "gameboard.hh"
#include "hex.hh"
#include "pawn.hh"
#include "transport.hh"
#include "dolphin.hh"
#include "boat.hh"
#include "actor.hh"
#include "monsters.hh"
#include "seamunster.hh"
#include "shark.hh"
#include "vortex.hh"


// Constant for aiding Hex's NeighbourVector accessing.
const int TST_MAX_SIDES = 6;

// Because Hex-tile's type can't effect the functionality of gameboard. (except for "Water" tile's)
const std::string TST_HEXTYPE = "None";

const std::string TST_DEFAULT_ACTOR_TYPE = "Shark";
const std::string TST_DEFAULT_TRANSPORT_TYPE = "Boat";

class GameStateTest : public QObject
{
    Q_OBJECT

public:
    GameStateTest();

private Q_SLOTS:
    void init();
    void testConsturctor();

    // GamePhase information
    void testcurrentGamePhase();

    // CurrentPlayer information
    void testcurrentPlayer();

    // GamePhase changer
    void testchangeGamePhase();

    // Turn changer
    void testchangePlayerTurn();

    // Sets the iGameRunner for gamestate
    void testsetrunner();

    // Gets the amount of pawns of certain player
    void testgetPawnPerPlayer();

    // adds points to certain player
    void testaddPointsToPlayer();

    // deletes a pawn of certain ID
    void testdeletePawn();

    // gets how many pawns player has left
    void testplayerPawnsLeft();

    // Sets the playerpointvector for the game
    void testinitializePlayerPointVector();


    // gets the vector with players ids and points inside
    void testgetPlayerPointVector();

    // gets the iGameRunner set for the state
    void testgetrunner();

private:
    std::shared_ptr<Common::IGameState> state_;
    std::shared_ptr<Common::IGameRunner> runner_;

  //void generateTileCircle(int range);
  //std::vector<Common::CubeCoordinate> addHex(
  //        Common::CubeCoordinate coord,
  //        std::string pieceType);
  //std::shared_ptr<Common::Pawn> addPawn(
  //        int pawnid,
  //        int playerid,
  //        Common::CubeCoordinate coord);
  //std::shared_ptr<Common::Actor> addActor(
  //        int actorid,
  //        Common::CubeCoordinate coord,
  //        std::string type);
  //std::shared_ptr<Common::Transport> addTransport(
  //        int transportid,
  //        Common::CubeCoordinate coord,
  //        std::string type);
};

GameStateTest::GameStateTest():
    state_(nullptr),
    runner_(nullptr)
{
}

void GameStateTest::init()
{
    runner_.reset();
    runner_= std::make_shared<Student::GameState>();

    state_.reset();
    state_= std::make_shared<Common::IGameRunner>();
}

void GameStateTest::testConsturctor()
{

    QVERIFY(board_->getHex(center_) == nullptr);
    
}

void GameStateTest::testcurrentGamePhase()
{
    
}

void GameStateTest::testcurrentPlayer()
{
    
}

void GameStateTest::testchangeGamePhase()
{
    
}

void GameStateTest::testchangePlayerTurn()
{
    
}

void GameStateTest::testsetrunner()
{
    
}

void GameStateTest::testgetPawnPerPlayer()
{
    
}

void GameStateTest::testaddPointsToPlayer()
{
    
}

void GameStateTest::testdeletePawn()
{
    
}

void GameStateTest::testplayerPawnsLeft()
{
    
}

void GameStateTest::testinitializePlayerPointVector()
{
    
}

void GameStateTest::testgetPlayerPointVector()
{
    
}

void GameStateTest::testgetrunner()
{
    
}


