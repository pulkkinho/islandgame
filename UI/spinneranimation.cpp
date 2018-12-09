#include "spinneranimation.hh"
#include "iostream"

spinneranimation::spinneranimation(std::string actor,std::string amount,QWidget *parent):
    actor_(actor),
    amount_(amount),
    QWidget(parent)
{
    this->resize(40,40);
    gif_anim = nullptr;
    movie_ = nullptr;
    gif_anim = new QLabel(this);
}

// Funktio spinnerinuolen pyörimisen aloittamiseksi
// pyörii sekunnin ajan
void spinneranimation::startanimation()
{
    movie_ = new QMovie("://spinneri.gif");
    movie_->setScaledSize(this->size());
    gif_anim->setMovie(movie_);
    movie_->start();
    this->setGeometry(-170,-90,40,40);
    QTimer::singleShot(1000, this, SLOT(stopanimation()));
}

// Funktio spinnerin pyörimisen lopettamiseksi.
// pysähtyy kohtaan, jossa nuoli indikoi liikkuvaa monsteria
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
