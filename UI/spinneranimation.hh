#ifndef SPINNERANIMATION_HH
#define SPINNERANIMATION_HH

#include <QObject>
#include <QWidget>
#include "QLabel"
#include "QtWidgets"
#include "QTimer"

/**
 * @brief The spinneranimation class which
 * näyttää hyrrän pyöritysanimaation
 * joka on spinwheelin tulos
 */

class spinneranimation : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief spinneranimation constructor
     * @param actor
     * näyttää mikä eläin liikkuu
     * @param amount
     * näyttää kuinka monta askelta liikutetaan
     * @param parent
     */
    spinneranimation(std::string actor,std::string amount,QWidget* parent =NULL);


public slots:
    /**
     * @brief startanimation
     * Käynnistää pyöräytysanimaation
     */
    void startanimation();

    /**
     * @brief stopanimation
     * pysäyttää pyöritysanimaation
     */
    void stopanimation();

private:

    std::string actor_;
    std::string amount_;
    QLabel *gif_anim;
    QMovie *movie_;
};

#endif // SPINNERANIMATION_HH
