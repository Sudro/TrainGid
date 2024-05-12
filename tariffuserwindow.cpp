#include "tariffuserwindow.h"
#include "ui_tariffuserwindow.h"
#include "routeuserwindow.h"
#include "stationuserwindow.h"
#include "trainuserwindow.h"
#include "mainwindow.h"
#include <QMouseEvent>

TariffUserWindow::TariffUserWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffUserWindow)
{
    ui->setupUi(this);

    // Устанавливаем флаг Qt::FramelessWindowHint
    setWindowFlags(Qt::FramelessWindowHint);
}

TariffUserWindow::~TariffUserWindow()
{
    delete ui;
}

// Определяем слот для закрытия текущего окна
void TariffUserWindow::on_pushButton_2_clicked()
{
    // Закрываем текущее окно (TrainUserWindow)
    this->close();
}

// Определяем слот для сворачивания текущего окна
void TariffUserWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (TrainUserWindow)
    this->showMinimized();
}

void TariffUserWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void TariffUserWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void TariffUserWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

// Определяем обработчик для кнопки pushButton_8
void TariffUserWindow::on_pushButton_6_clicked()
{
    // Создаем экземпляр окна RouteWindow
    RouteWindow *routeWindow = new RouteWindow();
    // Показываем окно RouteWindow
    routeWindow->show();
    // Закрываем текущее окно (TariffUserWindow)
    this->close();
}


void TariffUserWindow::on_pushButton_7_clicked()
{
    // Создаем экземпляр окна StationUserWindow
    StationUserWindow *stationUserWindow = new StationUserWindow();
    // Показываем окно StationUserWindow
    stationUserWindow->show();
    // Закрываем текущее окно (TariffUserWindow)
    this->close();
}


void TariffUserWindow::on_pushButton_5_clicked()
{
    // Создаем экземпляр окна TrainUserWindow
    TrainUserWindow *trainUserWindow = new TrainUserWindow();
    // Показываем окно TrainUserWindow
    trainUserWindow->show();
    // Закрываем текущее окно (TariffUserWindow)
    this->close();
}

void TariffUserWindow::on_pushButton_4_clicked()
{
    // Создаем экземпляр окна MainWindow
    MainWindow *mainWindow = new MainWindow();
    // Показываем окно MainWindow
    mainWindow->show();
    // Закрываем текущее окно (TariffUserWindow)
    this->close();
}
