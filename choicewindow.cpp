#include "choicewindow.h"
#include "ui_choicewindow.h"

ChoiceWindow::ChoiceWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChoiceWindow)
{
    ui->setupUi(this);
}

ChoiceWindow::~ChoiceWindow()
{
    delete ui;
}
