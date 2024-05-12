#include "stationuserwindow.h"
#include "ui_stationuserwindow.h"

StationUserWindow::StationUserWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StationUserWindow)
{
    ui->setupUi(this);
}

StationUserWindow::~StationUserWindow()
{
    delete ui;
}
