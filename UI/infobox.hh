#ifndef INFOBOX_HH
#define INFOBOX_HH
#include <QObject>
#include <QWidget>
#include "QtWidgets"
#include "gamestate.hh"

/**
 * @brief The infoBox class
 * Pelin tilasta kertovan infolaatikon
 * luokka
 */
class infoBox : public QWidget
{
public:
    int playerInTurn_;
    /**
     * @brief infoBox
     * Luokan Constructor
     * @param currentGamePhase
     * @param playerInTurn
     * @param parent
     */
    infoBox(Common::GamePhase currentGamePhase, int playerInTurn, QWidget* parent = NULL);

    /**
     * @brief updateGraphics
     * Funktio grafiikoiden päivitykselle
     */
    void updateGraphics();

    /**
     * @brief setNew
     * Funktio uuden informaation päivitykselle
     */
    void setNew(Common::GamePhase, int);

    /**
     * @brief gameOver
     * Funktio, jonka informaatio laitetaan infoboksiin kun peli päättyy
     */
    void gameOver(bool, int);

private:
    Common::GamePhase currentGamePhase_;
    QString playernumber;
    QLabel *textLabel;
    QString phase;
};

#endif // INFOBOX_HH
