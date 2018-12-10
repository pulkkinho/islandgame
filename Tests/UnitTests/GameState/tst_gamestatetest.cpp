#include <QString>
#include <QtTest>
#include <vector>

#include "gamestate.hh"

#include "hex.hh"
#include "pawn.hh"
#include "transport.hh"
#include "dolphin.hh"
#include "boat.hh"
#include "actor.hh"
#include "seamunster.hh"
#include "shark.hh"
#include "vortex.hh"

const std::string TST_HEXTYPE = "None";

class GameStateTest : public QObject
{
    Q_OBJECT

public:
    GameStateTest();

private Q_SLOTS:
    void init();
    void testConsturctor();
    void testChangeState();
    void testChangePlayer();

private:
    Common::CubeCoordinate center_;
    std::shared_ptr<Common::IGameState> state_;
};

GameStateTest::GameStateTest():
    center_(0, 0 ,0),
    state_(nullptr)
{
}

void GameStateTest::init()
{
    state_.reset();
    state_ = std::make_shared<GameState>();
}

void GameStateTest::testConsturctor()
{

    QVERIFY(state_ != nullptr);

}

void GameStateTest::testChangeState()
{

    QVERIFY(state_.get()->currentGamePhase() != 2);
    state_.get()->changeGamePhase(Common::GamePhase::SINKING);
    QVERIFY(state_.get()->currentGamePhase() == 2);
}

void GameStateTest::testChangePlayer()
{

    QVERIFY(state_.get()->currentPlayer() != 2);
    state_.get()->changePlayerTurn(2);
    QVERIFY(state_.get()->currentPlayer() == 2);
}

QTEST_APPLESS_MAIN(GameStateTest)

#include "tst_gamestatetest.moc"
