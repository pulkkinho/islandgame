#include "spinneranimation.hh"
#include "iostream"

spinneranimation::spinneranimation(std::string actor,std::string amount,QWidget *parent):
    actor_(actor),
    amount_(amount),
    QWidget(parent)
{

    this->resize(40,40);

       gif_anim = new QLabel(this);
       movie_ = new QMovie("://spinneri.gif");
       movie_->setScaledSize(this->size());
       movie_->setSpeed(1000);
       startanimation();

       QTimer::singleShot(3000, this, SLOT(stopanimation()));
}


void spinneranimation::startanimation()
{

  //  QMovie *movie = new QMovie("://spinneri.gif");
    gif_anim->setMovie(movie_);
    movie_->start();
    this->setGeometry(-170,-90,40,40);
    //spinbutton->isChecked()


    //movie->jumpToFrame(7);
    //tehhää timer, annetaan spinnerin pyörii, katotaan sit
    //mikä spinnerin antama monsteri on ja pysäytetään spinneri siihen frameen mikä osottaa sinne
    //qdialogil esitetään numero
    //movie->setPaused(true);



}

void spinneranimation::stopanimation()
{
    if(actor_ == "dolphin"){
        while(movie_->jumpToFrame(6) == false)
        {
        movie_->jumpToNextFrame();
        }
    }
    if(actor_ == "seamunster"){
        while(movie_->jumpToFrame(9) == false)
        {
        movie_->jumpToNextFrame();
        }
    }
    if(actor_ == "kraken"){
        while(movie_->jumpToFrame(2) == false)
        {
        movie_->jumpToNextFrame();
        }
    }
    if(actor_ == "shark"){
        while(movie_->jumpToFrame(4) == false)
        {
        movie_->jumpToNextFrame();
        }
    }
    movie_->stop();




}
