#include "scoreboardui.hh"
#include "QLabel"
#include "iostream"

scoreboardUI::scoreboardUI(    std::vector<std::pair<int,int>> _playerPointVector,QWidget *parent):
    _playerPointVector(_playerPointVector),
    QWidget(parent)

{
    // Alustetaan pistetaulukko.

    this->resize(30,30);
    std::string playernumber;
    std::string numberOfPoints;

    // Käy läpi pelaajat yksi kerrallaan ja asettaa näiden
    // pelaajanumerot ja pisteet, sekä pelaajan pelinappulaa
    // indikoivan kuvan vektoreihin
    for(auto player : _playerPointVector){

        playernumber = std::to_string(player.first);
        numberOfPoints= std::to_string(player.second);

        QString playernumber2 =QString::fromStdString( playernumber);
        QString numberOfPoints2 =QString::fromStdString( numberOfPoints);

        QLabel *imagePixmap = new QLabel;
        imagePixmap->setPixmap(QPixmap ("://pawn"+playernumber2+".png").scaledToHeight(25));
        kuvavektor.push_back(std::make_shared<QLabel>(imagePixmap));

        QLabel *textLabel = new QLabel;
        textLabel->setText("Player" +playernumber2+"   Points:  "+numberOfPoints2);
        tekstivektor.push_back(std::make_shared<QLabel>(textLabel));
    }
    updateGraphics(_playerPointVector);
}

// Päivitetään pistetaulukko ja lisätään tiedot
// layouttiin
void scoreboardUI::updateGraphics(std::vector<std::pair<int, int> > playerVector)
{
    QGridLayout *layout = new QGridLayout(this);
    std::string playernumber;
    std::string numberOfPoints;
    int row = 0;

    // Käy läpi pelaajat yksi kerrallaan ja asettaa näiden
    // pelaajanumerot ja pisteet, sekä pelaajan pelinappulaa
    // indikoivan kuvan vektoreihin
    for(auto player : playerVector){
        playernumber = std::to_string(player.first);
        numberOfPoints= std::to_string(player.second);

        QString playernumber2 =QString::fromStdString( playernumber);
        QString numberOfPoints2 =QString::fromStdString( numberOfPoints);

        int indeksi = player.first - 1;
        tekstivektor.at(indeksi).get()->setText("Player" +playernumber2+"   Points:  "+numberOfPoints2);
        kuvavektor.at(indeksi).get()->setPixmap( QPixmap ("://pawn"+playernumber2+".png").scaledToHeight(25));

        layout->addWidget(kuvavektor.at(indeksi).get(),row,0);
        layout->addWidget(tekstivektor.at(indeksi).get(),row,1);
        row = row + 1;
    }
}
// Asetetaan päivitetyt tiedot pistelautaan
void scoreboardUI::setNew(std::vector<std::pair<int, int> > playerVector)
{
    _playerPointVector = playerVector;
}
