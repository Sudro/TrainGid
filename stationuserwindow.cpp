#include "stationuserwindow.h"
#include "ui_stationuserwindow.h"
#include "tariffuserwindow.h"
#include "routeuserwindow.h"
#include "trainuserwindow.h"
#include "mainwindow.h"
#include <QMouseEvent>

StationUserWindow::StationUserWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StationUserWindow)
{
    ui->setupUi(this);

    // Устанавливаем флаг Qt::FramelessWindowHint
    setWindowFlags(Qt::FramelessWindowHint);
}

StationUserWindow::~StationUserWindow()
{
    delete ui;
}


// Определяем слот для закрытия текущего окна
void StationUserWindow::on_pushButton_2_clicked()
{
    // Закрываем текущее окно (TrainUserWindow)
    this->close();
}

// Определяем слот для сворачивания текущего окна
void StationUserWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (TrainUserWindow)
    this->showMinimized();
}

void StationUserWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void StationUserWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void StationUserWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

// Определяем обработчик для кнопки pushButton_8
void StationUserWindow::on_pushButton_8_clicked()
{
    // Создаем экземпляр окна TariffUserWindow
    TariffUserWindow *tariffUserWindow = new TariffUserWindow();
    // Показываем окно TariffUserWindow
    tariffUserWindow->show();
    // Закрываем текущее окно (StationUserWindow)
    this->close();
}

void StationUserWindow::on_pushButton_5_clicked()
{
    // Создаем экземпляр окна TrainUserWindow
    TrainUserWindow *trainUserWindow = new TrainUserWindow();
    // Показываем окно TrainUserWindow
    trainUserWindow->show();
    // Закрываем текущее окно (StationUserWindow)
    this->close();
}

void StationUserWindow::on_pushButton_4_clicked()
{
    // Создаем экземпляр окна MainWindow
    MainWindow *mainWindow = new MainWindow();
    // Показываем окно MainWindow
    mainWindow->show();
    // Закрываем текущее окно (StationUserWindow)
    this->close();
}


void StationUserWindow::on_pushButton_6_clicked()
{
    // Создаем экземпляр окна StationUserWindow
    RouteWindow *routeWindow = new RouteWindow();
    // Показываем окно StationUserWindow
    routeWindow->show();
    // Закрываем текущее окно (StationUserWindow)
    this->close();
}

