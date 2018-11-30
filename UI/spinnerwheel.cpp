#include "spinnerwheel.hh"

spinnerwheel::spinnerwheel(std::shared_ptr<Common::SpinnerLayout> spinneri, QGraphicsItem* parent):
    QGraphicsPixmapItem(parent),layout_(spinneri)


{

    updateGraphics();
}

void spinnerwheel::updateGraphics()
{


    // ei hajuukaan toimiiks tää näin tms


        QPixmap laivunen("://wheel.png");
        setPixmap(laivunen.scaledToHeight(50));


    this->setPos(-150,-100);
}
