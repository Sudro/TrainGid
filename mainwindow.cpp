#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "choicewindow.h" // Добавляем заголовочный файл для ChoiceWindow
#include "tariffuserwindow.h" // Добавляем заголовочный файл для TariffUserWindow
#include "stationuserwindow.h" // Добавляем заголовочный файл для StationUserWindow
#include "routeuserwindow.h" // Включаем заголовочный файл для RouteUserwindow
#include "trainuserwindow.h" // Включаем заголовочный файл для TrainUserwindow
#include "trainstationwindow.h"
#include <QMouseEvent>

MainWindow* MainWindow::instance = nullptr; //

MainWindow* MainWindow::getInstance(QWidget *parent) { //
    if (!instance)
        instance = new MainWindow(parent);
    return instance;
}

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

    // Устанавливаем фильтр событий для кнопок
    ui->pushButton->installEventFilter(this);
    ui->pushButton_2->installEventFilter(this);
    ui->pushButton_3->installEventFilter(this);
    ui->pushButton_5->installEventFilter(this);
    ui->pushButton_6->installEventFilter(this);
    ui->pushButton_7->installEventFilter(this);
    ui->pushButton_8->installEventFilter(this);
    ui->pushButton_9->installEventFilter(this);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete choiceWindow; // Освобождаем память, выделенную под ChoiceWindow

    instance = nullptr; //
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::Enter || event->type() == QEvent::Leave) {
        QPushButton *button = qobject_cast<QPushButton*>(obj);
        if (button) {
            if (event->type() == QEvent::Enter) {
                if (button == ui->pushButton_2) {
                    updateButtonIcon(button, ":/closeIcon2.png");
                } else if (button == ui->pushButton_3) {
                    updateButtonIcon(button, ":/swapIcon2.png");
                } else if (button == ui->pushButton_5) {
                    updateButtonIcon(button, ":/trainButton2New.png");
                } else if (button == ui->pushButton_6) {
                    updateButtonIcon(button, ":/routeButton2New.png");
                } else if (button == ui->pushButton_7) {
                    updateButtonIcon(button, ":/stationsButton2New.png");
                } else if (button == ui->pushButton_8) {
                    updateButtonIcon(button, ":/tariffsButton2New.png");
                } else if (button == ui->pushButton_9) {
                    updateButtonIcon(button, ":/trainStationButton2.png");
                } else if (button == ui->pushButton) {
                    updateButtonIcon(button, ":/mainButtonFrame2.png");
                }
            } else if (event->type() == QEvent::Leave) {
                // Здесь можно вернуть исходную иконку кнопки
                if (button == ui->pushButton_2) {
                    updateButtonIcon(button, ":/closeIcon.png");
                } else if (button == ui->pushButton_3) {
                    updateButtonIcon(button, ":/swapIcon.png");
                } else if (button == ui->pushButton_5) {
                    updateButtonIcon(button, ":/trainButton.png");
                } else if (button == ui->pushButton_6) {
                    updateButtonIcon(button, ":/routeButton.png");
                } else if (button == ui->pushButton_7) {
                    updateButtonIcon(button, ":/stationsButton.png");
                } else if (button == ui->pushButton_8) {
                    updateButtonIcon(button, ":/tariffsButton.png");
                } else if (button == ui->pushButton_9) {
                    updateButtonIcon(button, ":/trainStationButton.png");
                } else if (button == ui->pushButton) {
                    updateButtonIcon(button, ":/mainButtonFrame.png");
                }
            }
        }
        return true;
    }
    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
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



void MainWindow::on_pushButton_9_clicked()
{
    // Создаем экземпляр окна TrainStationWindow
    TrainStationWindow *trainStationUserWindow = new TrainStationWindow();
    // Показываем окно trainStationUserWindow
    trainStationUserWindow->show();
    // Закрываем текущее окно (MainWindow)
    this->close();
}

