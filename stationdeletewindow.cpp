#include "stationdeletewindow.h"
#include "ui_stationdeletewindow.h"

StationDeleteWindow::StationDeleteWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StationDeleteWindow)
{
    ui->setupUi(this);
}

StationDeleteWindow::~StationDeleteWindow()
{
    delete ui;
}
