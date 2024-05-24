#include "routechangewindow.h"
#include "ui_routechangewindow.h"

RouteChangeWindow::RouteChangeWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RouteChangeWindow)
{
    ui->setupUi(this);
}

RouteChangeWindow::~RouteChangeWindow()
{
    delete ui;
}
