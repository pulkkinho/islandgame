#ifndef SCOREBOARDUI_HH
#define SCOREBOARDUI_HH

#include <QObject>
#include <QWidget>
#include "QtWidgets"
#include "iplayer.hh"
#include "ostream"
#include "igamerunner.hh"



class scoreboardUI : public QWidget
{
public:
    scoreboardUI(std::vector<std::pair<int,int>> _playerPointVector,QWidget* parent =NULL);

    void updateGraphics(std::vector<std::pair<int, int> > playerVector);

    void setNew(std::vector<std::pair<int,int>>);

    void rip();

private:
    std::vector<std::pair<int,int>> _playerPointVector;


    //pawnItemMap.insert(std::make_pair(pawnId, apina));
    std::vector<std::shared_ptr<QLabel>> tekstivektor;
    std::vector<std::shared_ptr<QLabel>> kuvavektor;


};

#endif // SCOREBOARDUI_HH
