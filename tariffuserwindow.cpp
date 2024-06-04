#include "tariffuserwindow.h"
#include "ui_tariffuserwindow.h"
#include "routeuserwindow.h"
#include "stationuserwindow.h"
#include "trainuserwindow.h"
#include "trainstationwindow.h"
#include "mainwindow.h"
#include <QMouseEvent>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QVBoxLayout>
#include "DatabaseManager.h" // Включаем заголовочный файл для DatabaseManager
#include "customsqltablemodel.h"

TariffUserWindow::TariffUserWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffUserWindow)
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
        //QSqlTableModel *model = new QSqlTableModel(this, dbManager.database());
        CustomSqlTableModel *model = new CustomSqlTableModel(this, dbManager.database());
        model->setTable("tariffs");
        model->select();

        // Устанавливаем пользовательские заголовки
        model->setHeaderData(model->fieldIndex("route_id"), Qt::Horizontal, "Маршрут"); // "Маршрут (Время)"
        model->setHeaderData(model->fieldIndex("station_id"), Qt::Horizontal, "Название станции"); // "Название станции (Город)"
        model->setHeaderData(model->fieldIndex("tariff_name"), Qt::Horizontal, "Название тарифа"); //
        model->setHeaderData(model->fieldIndex("tariff_details"), Qt::Horizontal, "Описание тарифа"); //
        model->setHeaderData(model->fieldIndex("price"), Qt::Horizontal, "Цена тарифа"); //

        // Устанавливаем режим растягивания столбцов
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        // Устанавливаем модель в tableView
        ui->tableView->setModel(model);

        // Скрываем столбец tariff_id
        ui->tableView->hideColumn(0);

        // Устанавливаем режим растягивания столбцов
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
        ui->tableView->horizontalHeader()->setStretchLastSection(true);

        //ui->tableView->horizontalHeader()->setDefaultSectionSize(205); // ???????????
        //ui->tableView->horizontalHeader()->set


        // Устанавливаем равномерное начальное распределение ширины столбцов
        int columnCount = ui->tableView->horizontalHeader()->count();
        int tableWidth = ui->tableView->viewport()->width();
        int columnWidth = tableWidth / columnCount;
        for (int i = 0; i < columnCount; ++i) {
            ui->tableView->setColumnWidth(i, columnWidth);
        }


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
    ui->pushButton_7->installEventFilter(this);
    ui->pushButton_9->installEventFilter(this);
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
    qDebug() << "Opening RouteUserWindow as" << DatabaseManager::instance().currentUserName();
    // Создаем экземпляр окна RouteWindow
    RouteWindow *routeWindow = new RouteWindow();
    // Показываем окно RouteWindow
    routeWindow->show();
    // Закрываем текущее окно (TariffUserWindow)
    this->close();
}


void TariffUserWindow::on_pushButton_7_clicked()
{
    qDebug() << "Opening StationUserWindow as" << DatabaseManager::instance().currentUserName();
    // Создаем экземпляр окна StationUserWindow
    StationUserWindow *stationUserWindow = new StationUserWindow();
    // Показываем окно StationUserWindow
    stationUserWindow->show();
    // Закрываем текущее окно (TariffUserWindow)
    this->close();
}


void TariffUserWindow::on_pushButton_5_clicked()
{
    qDebug() << "Opening TrainUserWindow as" << DatabaseManager::instance().currentUserName();
    // Создаем экземпляр окна TrainUserWindow
    TrainUserWindow *trainUserWindow = new TrainUserWindow();
    // Показываем окно TrainUserWindow
    trainUserWindow->show();
    // Закрываем текущее окно (TariffUserWindow)
    this->close();
}

void TariffUserWindow::on_pushButton_4_clicked()
{
    qDebug() << "Opening MainWindow as" << DatabaseManager::instance().currentUserName();
    // Создаем экземпляр окна MainWindow
    MainWindow *mainWindow = new MainWindow();
    // Показываем окно MainWindow
    mainWindow->show();
    // Закрываем текущее окно (TariffUserWindow)
    this->close();
}

bool TariffUserWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::Enter || event->type() == QEvent::Leave) {
        QPushButton *button = qobject_cast<QPushButton*>(obj);
        if (button) {
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
                } else if (button == ui->pushButton_7) {
                    updateButtonIcon(button, ":/stationsButton3.png");
                } else if (button == ui->pushButton_9) {
                    updateButtonIcon(button, ":/trainStationButton3.png");
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
                } else if (button == ui->pushButton_7) {
                    updateButtonIcon(button, ":/stationsButton2New.png");
                } else if (button == ui->pushButton_9) {
                    updateButtonIcon(button, ":/trainStationButton2.png");
                }
            }
        }
        return true;
    }
    return QWidget::eventFilter(obj, event);
}

void TariffUserWindow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
}

void TariffUserWindow::on_pushButton_9_clicked()
{
    qDebug() << "Opening TrainStationWindow as" << DatabaseManager::instance().currentUserName();
    // Создаем экземпляр окна TrainStationWindow
    TrainStationWindow *trainStationWindow = new TrainStationWindow();
    // Показываем окно TrainStationWindow
    trainStationWindow->show();
    // Закрываем текущее окно (TariffUserWindow)
    this->close();
}

