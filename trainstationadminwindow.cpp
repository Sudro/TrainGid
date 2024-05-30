#include "trainstationadminwindow.h"
#include "ui_trainstationadminwindow.h"

TrainStationAdminWindow::TrainStationAdminWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainStationAdminWindow)
{
    ui->setupUi(this);
}

TrainStationAdminWindow::~TrainStationAdminWindow()
{
    delete ui;
}
