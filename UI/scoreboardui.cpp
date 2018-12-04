#include "scoreboardui.hh"
#include "QLabel"
#include "iostream"

scoreboardUI::scoreboardUI(    std::vector<std::pair<int,int>> _playerPointVector,QWidget *parent):
    _playerPointVector(_playerPointVector),
    QWidget(parent)
{


    this->resize(30,30);

    std::string playernumber;
    std::string numberOfPoints;

    for(auto player : _playerPointVector){

        playernumber = std::to_string(player.first);
        numberOfPoints= std::to_string(player.second);

        QString playernumber2 =QString::fromStdString( playernumber);
        QString numberOfPoints2 =QString::fromStdString( numberOfPoints);

        QLabel *kakko = new QLabel;
        kakko->setPixmap(QPixmap ("://pawn"+playernumber2+".png").scaledToHeight(25));
        kuvavektor.push_back(std::make_shared<QLabel>(kakko));

        QLabel *kukko = new QLabel;
        kukko->setText("Player" +playernumber2+"   Points:  "+numberOfPoints2);
        tekstivektor.push_back(std::make_shared<QLabel>(kukko));
    }


    updateGraphics(_playerPointVector);
}

void scoreboardUI::updateGraphics(std::vector<std::pair<int, int> > playerVector)
{



    QGridLayout *vbl = new QGridLayout(this);

    std::string playernumber;
    std::string numberOfPoints;
    int row = 0;

    for(auto player : playerVector){

        playernumber = std::to_string(player.first);
        numberOfPoints= std::to_string(player.second);


        QString playernumber2 =QString::fromStdString( playernumber);
        QString numberOfPoints2 =QString::fromStdString( numberOfPoints);

        int indeksi = player.first - 1;
        tekstivektor.at(indeksi).get()->setText("Player" +playernumber2+"   Points:  "+numberOfPoints2);

        vbl->addWidget(tekstivektor.at(indeksi).get(),row,0);

        row = row + 1;
    }


}

void scoreboardUI::setNew(std::vector<std::pair<int, int> > playerVector)
{
    _playerPointVector = playerVector;
}

void scoreboardUI::rip()
{

}



