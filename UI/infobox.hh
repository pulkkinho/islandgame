#ifndef INFOBOX_HH
#define INFOBOX_HH
#include <QObject>
#include <QWidget>
#include "QtWidgets"
#include "iplayer.hh"
#include "gamestate.hh"

class infoBox : public QWidget
{
public:
    infoBox(Common::GamePhase currentGamePhase, int playerInTurn, QWidget* parent = NULL);

    void updateGraphics();
    void setNew(Common::GamePhase, int);

private:
    Common::GamePhase currentGamePhase_;
    int playerInTurn_;
    QString playernumber;

    QLabel *kukko;
    QString phase;
};

#endif // INFOBOX_HH