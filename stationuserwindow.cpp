#include "stationuserwindow.h"
#include "ui_stationuserwindow.h"
#include "tariffuserwindow.h"
#include "routeuserwindow.h"
#include "trainuserwindow.h"
#include "mainwindow.h"
#include <QMouseEvent>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QVBoxLayout>
#include "DatabaseManager.h" // Включаем заголовочный файл для DatabaseManager

StationUserWindow::StationUserWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StationUserWindow)
{
    ui->setupUi(this);

    ui->tableView->verticalHeader()->hide();
    ui->tableView->verticalHeader()->setVisible(false);

    // Устанавливаем флаг Qt::FramelessWindowHint
    setWindowFlags(Qt::FramelessWindowHint);

    // Получаем экземпляр DatabaseManager и открываем базу данных
    DatabaseManager& dbManager = DatabaseManager::instance();
    if (dbManager.openDatabase())
    {
        // Создаем модель для отображения данных
        QSqlTableModel *model = new QSqlTableModel(this, dbManager.database());
        model->setTable("stations");
        model->select();

        // Устанавливаем режим растягивания столбцов
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        // Устанавливаем модель в tableView
        ui->tableView->setModel(model);
    }
    else
    {
        qDebug() << "Failed to open database";
    }

    // Устанавливаем фильтр событий для кнопок
    ui->pushButton_2->installEventFilter(this);
    ui->pushButton_3->installEventFilter(this);
    ui->pushButton_4->installEventFilter(this);
    ui->pushButton_5->installEventFilter(this);
    ui->pushButton_6->installEventFilter(this);
    ui->pushButton_8->installEventFilter(this);
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

bool StationUserWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::Enter || event->type() == QEvent::Leave) {
        QPushButton *button = qobject_cast<QPushButton*>(obj);
        if (event->type() == QEvent::Enter) {
            if (button == ui->pushButton_2) {
                updateButtonIcon(button, ":/closeIcon2.png");
            } else if (button == ui->pushButton_3) {
                updateButtonIcon(button, ":/swapIcon2.png");
            } else if (button == ui->pushButton_4) {
                updateButtonIcon(button, ":/homeButton4.png");
            } else if (button == ui->pushButton_5) {
                updateButtonIcon(button, ":/trainButton3.png");
            } else if (button == ui->pushButton_6) {
                updateButtonIcon(button, ":/routeButton3.png");
            } else if (button == ui->pushButton_8) {
                updateButtonIcon(button, ":/tariffsButton3.png");
            }
        } else if (event->type() == QEvent::Leave) {
            // Здесь можно вернуть исходную иконку кнопки
            if (button == ui->pushButton_2) {
                updateButtonIcon(button, ":/closeIcon.png");
            } else if (button == ui->pushButton_3) {
                updateButtonIcon(button, ":/swapIcon.png");
            } else if (button == ui->pushButton_4) {
                updateButtonIcon(button, ":/homeButton2_New.png");
            } else if (button == ui->pushButton_5) {
                updateButtonIcon(button, ":/trainButton2New.png");
            } else if (button == ui->pushButton_6) {
                updateButtonIcon(button, ":/routeButton2New.png");
            } else if (button == ui->pushButton_8) {
                updateButtonIcon(button, ":/tariffsButton2New.png");
            }
        }
        return true;
    }
    return QWidget::eventFilter(obj, event);
}

void StationUserWindow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
}

