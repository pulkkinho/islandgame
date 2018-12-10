#ifndef SCOREBOARDUI_HH
#define SCOREBOARDUI_HH

#include <QObject>
#include <QWidget>
#include "QtWidgets"
#include "iplayer.hh"
#include "ostream"
#include "igamerunner.hh"

/**
 * @brief The scoreboardUI class
 * Pelin pistetaulukon luokka
 */
class scoreboardUI : public QWidget
{
public:

    /**
     * @brief scoreboardUI
     * Pistetaulukon constructor
     * @param _playerPointVector
     * Vektori, jossa sisällä pareina pelaajien ID:t,
     * sekä pelaajien pistemäärät
     * @param parent
     */
    scoreboardUI(std::vector<std::pair<int,int>> _playerPointVector,QWidget* parent =NULL);

    /**
     * @brief updateGraphics
     * Pistetaulukon päivittämisen funktio
     * @param playerVector
     * Vektori, jossa sisällä pareina pelaajien ID:t,
     * sekä pelaajien pistemäärät
     */
    void updateGraphics(std::vector<std::pair<int, int> > playerVector);

    /**
     * @brief setNew
     * Asettaa pistetaulukolle päivitetyn vektorin
     * @param playerVector
     * Vektori, jossa sisällä pareina pelaajien ID:t,
     * sekä pelaajien pistemäärät
     */
    void setNew(std::vector<std::pair<int,int>> playerVector);

private:
    std::vector<std::pair<int,int>> _playerPointVector;
    QWidget* widget;
    std::vector<std::shared_ptr<QLabel>> tekstivektor;
    std::vector<std::shared_ptr<QLabel>> kuvavektor;
};

#endif // SCOREBOARDUI_HH
