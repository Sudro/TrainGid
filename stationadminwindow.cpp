#include "stationadminwindow.h"
#include "ui_stationadminwindow.h"
#include "tariffadminwindow.h"
#include "routeadminwindow.h"
#include "trainadminwindow.h"
#include "mainwindow.h"
#include <QMouseEvent>

StationAdminWIndow::StationAdminWIndow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StationAdminWIndow)
{
    ui->setupUi(this);

    // Устанавливаем флаг Qt::FramelessWindowHint
    setWindowFlags(Qt::FramelessWindowHint);
}

StationAdminWIndow::~StationAdminWIndow()
{
    delete ui;
}

// Определяем слот для закрытия текущего окна
void StationAdminWIndow::on_pushButton_2_clicked()
{
    // Закрываем текущее окно (StationAdminWIndow)
    this->close();
}

// Определяем слот для сворачивания текущего окна
void StationAdminWIndow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (StationAdminWIndow)
    this->showMinimized();
}

void StationAdminWIndow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void StationAdminWIndow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void StationAdminWIndow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

// Определяем обработчик для кнопки pushButton_8
void StationAdminWIndow::on_pushButton_8_clicked()
{
    // Создаем экземпляр окна TariffUserWindow
    TariffAdminWindow *tariffAdminWindow = new TariffAdminWindow();
    // Показываем окно TariffUserWindow
    tariffAdminWindow->show();
    // Закрываем текущее окно (StationAdminWIndow)
    this->close();
}

void StationAdminWIndow::on_pushButton_5_clicked()
{
    // Создаем экземпляр окна TrainAdminWindow
    TrainAdminWindow *trainAdminWindow = new TrainAdminWindow();
    // Показываем окно TrainAdminWindow
    trainAdminWindow->show();
    // Закрываем текущее окно (StationAdminWIndow)
    this->close();
}

void StationAdminWIndow::on_pushButton_4_clicked()
{
    // Создаем экземпляр окна MainWindow
    MainWindow *mainWindow = new MainWindow();
    // Показываем окно MainWindow
    mainWindow->show();
    // Закрываем текущее окно (StationAdminWIndow)
    this->close();
}


void StationAdminWIndow::on_pushButton_6_clicked()
{
    // Создаем экземпляр окна RouteAdminWindow
    RouteAdminWindow *routeAdminWindow = new RouteAdminWindow();
    // Показываем окно RouteAdminWindow
    routeAdminWindow->show();
    // Закрываем текущее окно (StationAdminWIndow)
    this->close();
}

