#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "choicewindow.h" // Добавляем заголовочный файл для ChoiceWindow
#include "tariffuserwindow.h" // Добавляем заголовочный файл для TariffUserWindow
#include "stationuserwindow.h" // Добавляем заголовочный файл для StationUserWindow
#include "routeuserwindow.h" // Включаем заголовочный файл для RouteUserwindow
#include "trainuserwindow.h" // Включаем заголовочный файл для TrainUserwindow
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Устанавливаем флаг Qt::FramelessWindowHint
    setWindowFlags(Qt::FramelessWindowHint);

    // Инициализируем указатель choiceWindow
    choiceWindow = new ChoiceWindow();

    // Подключаем обработчик сигнала clicked кнопки pushButton
    //connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);

    // Добавляем обработчик для кнопки pushButton_2
    //connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked);

    // Добавляем обработчик для кнопки pushButton_3
    //connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_pushButton_3_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete choiceWindow; // Освобождаем память, выделенную под ChoiceWindow
}

// Определяем слот для открытия окна ChoiceWindow
void MainWindow::on_pushButton_clicked()
{
    // Показываем окно ChoiceWindow
    choiceWindow->show();
    // Закрываем текущее окно (MainWindow)
    this->close();
}


// Определяем слот для закрытия текущего окна
void MainWindow::on_pushButton_2_clicked()
{
    // Закрываем текущее окно (MainWindow)
    this->close();
}

// Определяем слот для сворачивания текущего окна
void MainWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (MainWindow)
    this->showMinimized();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

// Определяем обработчик для кнопки pushButton_8
void MainWindow::on_pushButton_8_clicked()
{
    // Создаем экземпляр окна TariffUserWindow
    TariffUserWindow *tariffUserWindow = new TariffUserWindow();
    // Показываем окно TariffUserWindow
    tariffUserWindow->show();
    // Закрываем текущее окно (MainWindow)
    this->close();
}


void MainWindow::on_pushButton_7_clicked()
{
    // Создаем экземпляр окна StationUserWindow
    StationUserWindow *stationUserWindow = new StationUserWindow();
    // Показываем окно StationUserWindow
    stationUserWindow->show();
    // Закрываем текущее окно (MainWindow)
    this->close();
}


void MainWindow::on_pushButton_6_clicked()
{
    // Создаем экземпляр окна RouteUserWindow
    RouteWindow *routeUserWindow = new RouteWindow();
    // Показываем окно RouteUserWindow
    routeUserWindow->show();
    // Закрываем текущее окно (MainWindow)
    this->close();
}


void MainWindow::on_pushButton_5_clicked()
{
    // Создаем экземпляр окна TrainUserWindow
    TrainUserWindow *trainUserWindow = new TrainUserWindow();
    // Показываем окно RouteUserWindow
    trainUserWindow->show();
    // Закрываем текущее окно (MainWindow)
    this->close();
}


