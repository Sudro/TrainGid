#include "tariffchangewindow.h"
#include "ui_tariffchangewindow.h"

TariffChangeWindow::TariffChangeWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffChangeWindow)
{
    ui->setupUi(this);
}

TariffChangeWindow::~TariffChangeWindow()
{
    delete ui;
}
