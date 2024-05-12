#include "tariffadminwindow.h"
#include "ui_tariffadminwindow.h"

TariffAdminWindow::TariffAdminWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffAdminWindow)
{
    ui->setupUi(this);
}

TariffAdminWindow::~TariffAdminWindow()
{
    delete ui;
}
