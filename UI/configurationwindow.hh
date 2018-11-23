#ifndef CONFIGURATIONWINDOW_HH
#define CONFIGURATIONWINDOW_HH

#include <QDialog>

namespace Ui {
class configurationWindow;
}

class configurationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit configurationWindow(QWidget *parent = 0);
    ~configurationWindow();

    int getvalue();
signals:

    void sendvalue(int count);

public slots:
    virtual void accept();
    virtual void reject();

private:
    Ui::configurationWindow *ui;
};

#endif // CONFIGURATIONWINDOW_HH
