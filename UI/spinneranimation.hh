#ifndef SPINNERANIMATION_HH
#define SPINNERANIMATION_HH

#include <QObject>
#include <QWidget>
#include "QLabel"
#include "QtWidgets"
#include "QTimer"

class spinneranimation : public QWidget
{
    Q_OBJECT

public:
    spinneranimation(std::string actor,std::string amount,QWidget* parent =NULL);


public slots:

    void startanimation();

    void stopanimation();

private:

    std::string actor_;
    std::string amount_;

    QLabel *gif_anim;

    QMovie *movie_;

};

#endif // SPINNERANIMATION_HH
