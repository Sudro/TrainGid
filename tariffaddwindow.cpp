#include "tariffaddwindow.h"
#include "ui_tariffaddwindow.h"

TariffAddWindow::TariffAddWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffAddWindow)
{
    ui->setupUi(this);
}

TariffAddWindow::~TariffAddWindow()
{
    delete ui;
}
