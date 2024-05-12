#include "stationadminwindow.h"
#include "ui_stationadminwindow.h"

StationAdminWIndow::StationAdminWIndow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StationAdminWIndow)
{
    ui->setupUi(this);
}

StationAdminWIndow::~StationAdminWIndow()
{
    delete ui;
}
