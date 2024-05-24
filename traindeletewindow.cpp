#include "traindeletewindow.h"
#include "ui_traindeletewindow.h"

TrainDeleteWindow::TrainDeleteWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainDeleteWindow)
{
    ui->setupUi(this);
}

TrainDeleteWindow::~TrainDeleteWindow()
{
    delete ui;
}
