#include "routeadminwindow.h"
#include "ui_routeadminwindow.h"

RouteAdminWindow::RouteAdminWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RouteAdminWindow)
{
    ui->setupUi(this);
}

RouteAdminWindow::~RouteAdminWindow()
{
    delete ui;
}
