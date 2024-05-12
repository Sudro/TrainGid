#include "trainadminwindow.h"
#include "ui_trainadminwindow.h"

TrainAdminWindow::TrainAdminWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainAdminWindow)
{
    ui->setupUi(this);
}

TrainAdminWindow::~TrainAdminWindow()
{
    delete ui;
}
