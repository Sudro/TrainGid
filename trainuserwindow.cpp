#include "trainuserwindow.h"
#include "ui_trainuserwindow.h"

TrainUserWindow::TrainUserWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainUserWindow)
{
    ui->setupUi(this);
}

TrainUserWindow::~TrainUserWindow()
{
    delete ui;
}
