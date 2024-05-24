#include "trainstationconnectwindow.h"
#include "ui_trainstationconnectwindow.h"

TrainStationConnectWindow::TrainStationConnectWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainStationConnectWindow)
{
    ui->setupUi(this);
}

TrainStationConnectWindow::~TrainStationConnectWindow()
{
    delete ui;
}
