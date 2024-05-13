#include "trainadminwindow.h"
#include "ui_trainadminwindow.h"
#include "tariffadminwindow.h"
#include "stationadminwindow.h"
#include "routeadminwindow.h" // Включаем заголовочный файл для RouteUserwindow
#include "mainwindow.h"
#include <QMouseEvent>

TrainAdminWindow::TrainAdminWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainAdminWindow)
{
    ui->setupUi(this);

    // Устанавливаем флаг Qt::FramelessWindowHint
    setWindowFlags(Qt::FramelessWindowHint);
}

TrainAdminWindow::~TrainAdminWindow()
{
    delete ui;
}

// Определяем слот для закрытия текущего окна
void TrainAdminWindow::on_pushButton_2_clicked()
{
    // Закрываем текущее окно (TrainAdminWindow)
    this->close();
}

// Определяем слот для сворачивания текущего окна
void TrainAdminWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (TrainAdminWindow)
    this->showMinimized();
}

void TrainAdminWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void TrainAdminWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void TrainAdminWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

// Определяем обработчик для кнопки pushButton_8
void TrainAdminWindow::on_pushButton_8_clicked()
{
    // Создаем экземпляр окна TariffAdminWindow
    TariffAdminWindow *tariffAdminWindow = new TariffAdminWindow();
    // Показываем окно TariffAdminWindow
    tariffAdminWindow->show();
    // Закрываем текущее окно (TrainAdminWindow)
    this->close();
}


void TrainAdminWindow::on_pushButton_7_clicked()
{
    // Создаем экземпляр окна StationAdminWIndow
    StationAdminWIndow *stationAdminWindow = new StationAdminWIndow();
    // Показываем окно StationAdminWIndow
    stationAdminWindow->show();
    // Закрываем текущее окно (TrainAdminWindow)
    this->close();
}


void TrainAdminWindow::on_pushButton_6_clicked()
{
    // Создаем экземпляр окна RouteAdminWindow
    RouteAdminWindow *routeAdminWindow = new RouteAdminWindow();
    // Показываем окно RouteAdminWindow
    routeAdminWindow->show();
    // Закрываем текущее окно (TrainAdminWindow)
    this->close();
}

void TrainAdminWindow::on_pushButton_4_clicked()
{
    // Создаем экземпляр окна MainWindow
    MainWindow *mainWindow = new MainWindow();
    // Показываем окно MainWindow
    mainWindow->show();
    // Закрываем текущее окно (TrainAdminWindow)
    this->close();
}
