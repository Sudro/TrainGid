#include "changewindow.h"
#include "ui_changewindow.h"

ChangeWindow::ChangeWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChangeWindow)
{
    ui->setupUi(this);
}

ChangeWindow::~ChangeWindow()
{
    delete ui;
}
