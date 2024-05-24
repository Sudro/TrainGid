#include "routedeletewindow.h"
#include "ui_routedeletewindow.h"

RouteDeleteWindow::RouteDeleteWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RouteDeleteWindow)
{
    ui->setupUi(this);
}

RouteDeleteWindow::~RouteDeleteWindow()
{
    delete ui;
}
