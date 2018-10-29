#include "configurationwindow.hh"
#include "ui_configurationwindow.h"

configurationWindow::configurationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configurationWindow)
{
    ui->setupUi(this);
}

configurationWindow::~configurationWindow()
{
    delete ui;
}
