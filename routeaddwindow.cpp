#include "routeaddwindow.h"
#include "ui_routeaddwindow.h"

RouteAddWindow::RouteAddWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RouteAddWindow)
{
    ui->setupUi(this);
}

RouteAddWindow::~RouteAddWindow()
{
    delete ui;
}
