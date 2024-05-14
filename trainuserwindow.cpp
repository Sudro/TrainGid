#include "trainuserwindow.h"
#include "ui_trainuserwindow.h"
#include "tariffuserwindow.h"
#include "stationuserwindow.h"
#include "routeuserwindow.h" // Включаем заголовочный файл для RouteUserwindow
#include "mainwindow.h"
#include <QMouseEvent>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QVBoxLayout>

TrainUserWindow::TrainUserWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainUserWindow)
{
    ui->setupUi(this);

    ui->tableView->verticalHeader()->hide();
    ui->tableView->verticalHeader()->setVisible(false);

    // Устанавливаем флаг Qt::FramelessWindowHint
    setWindowFlags(Qt::FramelessWindowHint);


    //qDebug() << "Доступные драйверы:" << QSqlDatabase::drivers();


    //qputenv("PATH", qgetenv("PATH") + ";D:/PostgreSQL/lib");
    //qputenv("PATH", qgetenv("PATH") + ";D:/qt/6.7.0/llvm-mingw_64/plugins");

    //QCoreApplication::addLibraryPath("D:/PostgreSQL/lib");
    //QCoreApplication::addLibraryPath("D:/qt/6.7.0/llvm-mingw_64/plugins");
    //Создаем и настраиваем подключение к базе данных
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setUserName("postgres");
    db.setPassword("12345");
    db.setDatabaseName("postgres");
    db.setHostName("localhost");
    if (db.open())
    {
        qDebug() << "Connected";
    }
    else
    {
        qDebug() << "Not Connected" << db.lastError().text();
    }

    //Создаем модель для отображения данных
    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("enemy");
    model->select();



    // Устанавливаем режим растягивания столбцов
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //Устанавливаем модель в tableView
    ui->tableView->setModel(model);

}

TrainUserWindow::~TrainUserWindow()
{
    delete ui;
}

// Определяем слот для закрытия текущего окна
void TrainUserWindow::on_pushButton_2_clicked()
{
    // Закрываем текущее окно (TrainUserWindow)
    this->close();
}

// Определяем слот для сворачивания текущего окна
void TrainUserWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (TrainUserWindow)
    this->showMinimized();
}

void TrainUserWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void TrainUserWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void TrainUserWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

// Определяем обработчик для кнопки pushButton_8
void TrainUserWindow::on_pushButton_8_clicked()
{
    // Создаем экземпляр окна TariffUserWindow
    TariffUserWindow *tariffUserWindow = new TariffUserWindow();
    // Показываем окно TariffUserWindow
    tariffUserWindow->show();
    // Закрываем текущее окно (TrainUserWindow)
    this->close();
}


void TrainUserWindow::on_pushButton_7_clicked()
{
    // Создаем экземпляр окна StationUserWindow
    StationUserWindow *stationUserWindow = new StationUserWindow();
    // Показываем окно StationUserWindow
    stationUserWindow->show();
    // Закрываем текущее окно (TrainUserWindow)
    this->close();
}


void TrainUserWindow::on_pushButton_6_clicked()
{
    // Создаем экземпляр окна RouteUserWindow
    RouteWindow *routeUserWindow = new RouteWindow();
    // Показываем окно RouteUserWindow
    routeUserWindow->show();
    // Закрываем текущее окно (TrainUserWindow)
    this->close();
}

void TrainUserWindow::on_pushButton_4_clicked()
{
    // Создаем экземпляр окна RouteUserWindow
    MainWindow *mainWindow = new MainWindow();
    // Показываем окно RouteUserWindow
    mainWindow->show();
    // Закрываем текущее окно (TrainUserWindow)
    this->close();
}

