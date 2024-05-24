#include "trainaddwindow.h"
#include "ui_trainaddwindow.h"

TrainAddWindow::TrainAddWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainAddWindow)
{
    ui->setupUi(this);
}

TrainAddWindow::~TrainAddWindow()
{
    delete ui;
}
