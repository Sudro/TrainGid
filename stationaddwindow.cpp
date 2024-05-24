#include "stationaddwindow.h"
#include "ui_stationaddwindow.h"

StationAddWindow::StationAddWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StationAddWindow)
{
    ui->setupUi(this);
}

StationAddWindow::~StationAddWindow()
{
    delete ui;
}
