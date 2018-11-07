#include "configurationwindow.hh"
#include "ui_configurationwindow.h"


configurationWindow::configurationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configurationWindow)
{
    ui->setupUi(this);
    connect(ui->OkButton, &QPushButton::clicked,
            this, &configurationWindow::accept);
    connect(ui->CancelButton, &QPushButton::clicked,
            this, &configurationWindow::reject);

}

configurationWindow::~configurationWindow()
{
    delete ui;
}

void configurationWindow::accept()
{
    QDialog::accept();
    emit sendvalue(ui->PlayerSpinBox->value());

}

void configurationWindow::reject()
{
    QDialog::reject();
}
