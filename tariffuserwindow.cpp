#include "tariffuserwindow.h"
#include "ui_tariffuserwindow.h"

TariffUserWindow::TariffUserWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffUserWindow)
{
    ui->setupUi(this);
}

TariffUserWindow::~TariffUserWindow()
{
    delete ui;
}
