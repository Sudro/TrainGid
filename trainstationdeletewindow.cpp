#include "trainstationdeletewindow.h"
#include "ui_trainstationdeletewindow.h"

TrainStationDeleteWindow::TrainStationDeleteWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainStationDeleteWindow)
{
    ui->setupUi(this);
}

TrainStationDeleteWindow::~TrainStationDeleteWindow()
{
    delete ui;
}
