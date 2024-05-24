#include "tariffdeletewindow.h"
#include "ui_tariffdeletewindow.h"

TariffDeleteWindow::TariffDeleteWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffDeleteWindow)
{
    ui->setupUi(this);
}

TariffDeleteWindow::~TariffDeleteWindow()
{
    delete ui;
}
