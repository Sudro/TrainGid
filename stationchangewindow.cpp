#include "stationchangewindow.h"
#include "ui_stationchangewindow.h"

StationChangeWindow::StationChangeWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StationChangeWindow)
{
    ui->setupUi(this);
}

StationChangeWindow::~StationChangeWindow()
{
    delete ui;
}
