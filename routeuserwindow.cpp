#include "routeuserwindow.h"
#include "ui_routeuserwindow.h"

RouteWindow::RouteWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RouteWindow)
{
    ui->setupUi(this);
}

RouteWindow::~RouteWindow()
{
    delete ui;
}
