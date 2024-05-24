#include "trainchangewindow.h"
#include "ui_trainchangewindow.h"

TrainChangeWindow::TrainChangeWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainChangeWindow)
{
    ui->setupUi(this);
}

TrainChangeWindow::~TrainChangeWindow()
{
    delete ui;
}
