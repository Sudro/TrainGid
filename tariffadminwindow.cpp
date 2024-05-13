#include "tariffadminwindow.h"
#include "ui_tariffadminwindow.h"
#include "routeadminwindow.h"
#include "stationadminwindow.h"
#include "trainadminwindow.h"
#include "mainwindow.h"
#include <QMouseEvent>

TariffAdminWindow::TariffAdminWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffAdminWindow)
{
    ui->setupUi(this);

    // Устанавливаем флаг Qt::FramelessWindowHint
    setWindowFlags(Qt::FramelessWindowHint);
}

TariffAdminWindow::~TariffAdminWindow()
{
    delete ui;
}


// Определяем слот для закрытия текущего окна
void TariffAdminWindow::on_pushButton_2_clicked()
{
    // Закрываем текущее окно (TariffAdminWindow)
    this->close();
}

// Определяем слот для сворачивания текущего окна
void TariffAdminWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (TariffAdminWindow)
    this->showMinimized();
}

void TariffAdminWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void TariffAdminWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void TariffAdminWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

// Определяем обработчик для кнопки pushButton_8
void TariffAdminWindow::on_pushButton_6_clicked()
{
    // Создаем экземпляр окна RouteAdminWindow
    RouteAdminWindow *routeAdminWindow = new RouteAdminWindow();
    // Показываем окно RouteAdminWindow
    routeAdminWindow->show();
    // Закрываем текущее окно (TariffAdminWindow)
    this->close();
}


void TariffAdminWindow::on_pushButton_7_clicked()
{
    // Создаем экземпляр окна StationAdminWindow
    StationAdminWIndow *stationAdminWindow = new StationAdminWIndow();
    // Показываем окно StationAdminWindow
    stationAdminWindow->show();
    // Закрываем текущее окно (TariffAdminWindow)
    this->close();
}


void TariffAdminWindow::on_pushButton_5_clicked()
{
    // Создаем экземпляр окна TrainAdminWindow
    TrainAdminWindow *trainAdminWindow = new TrainAdminWindow();
    // Показываем окно trainAdminWindow
    trainAdminWindow->show();
    // Закрываем текущее окно (TariffAdminWindow)
    this->close();
}

void TariffAdminWindow::on_pushButton_4_clicked()
{
    // Создаем экземпляр окна MainWindow
    MainWindow *mainWindow = new MainWindow();
    // Показываем окно MainWindow
    mainWindow->show();
    // Закрываем текущее окно (TariffAdminWindow)
    this->close();
}
