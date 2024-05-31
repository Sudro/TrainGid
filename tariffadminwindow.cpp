#include "tariffadminwindow.h"
#include "ui_tariffadminwindow.h"
#include "tariffaddwindow.h"
#include "tariffchangewindow.h"
#include "routeadminwindow.h"
#include "stationadminwindow.h"
#include "trainadminwindow.h"
#include "trainstationadminwindow.h"
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

TariffAdminWindow* TariffAdminWindow::instance = nullptr; //

TariffAdminWindow* TariffAdminWindow::getInstance(QWidget *parent) { //
    if (!instance)
        instance = new TariffAdminWindow(parent);
    return instance;
}

TariffAdminWindow::TariffAdminWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffAdminWindow)
{
    ui->setupUi(this);

    ui->tableView->verticalHeader()->hide();
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); // Разрешает выбор только одной строки за раз
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); // Указывает, что при выборе должны выделяться строки

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

        // Устанавливаем режим растягивания столбцов
        //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        // Устанавливаем модель в tableView
        ui->tableView->setModel(model);

        // Скрываем столбец tariff_id
        ui->tableView->hideColumn(0);

        // Устанавливаем режим растягивания столбцов
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
        ui->tableView->horizontalHeader()->setStretchLastSection(true);


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
    ui->pushButton_10->installEventFilter(this);
    ui->pushButton_11->installEventFilter(this);
    ui->pushButton_12->installEventFilter(this);

    ui->pushButton_10->disconnect(); // Отключаем все сигналы, связанные с этой кнопкой
    connect(ui->pushButton_10, &QPushButton::clicked, this, &TariffAdminWindow::on_pushButton_10_clicked);
}

TariffAdminWindow::~TariffAdminWindow()
{
    delete ui;

    instance = nullptr; //
}


// Определяем слот для закрытия текущего окна
void TariffAdminWindow::on_pushButton_2_clicked()
{
    // Закрываем текущее окно (TariffAdminWindow)
    this->close();

    instance = nullptr;
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
    RouteAdminWindow *routeAdminWindow = RouteAdminWindow::getInstance();
    routeAdminWindow->raise();
    routeAdminWindow->activateWindow();
    routeAdminWindow->show();
    this->close();

    /*
    // Создаем экземпляр окна RouteAdminWindow
    RouteAdminWindow *routeAdminWindow = new RouteAdminWindow();
    // Показываем окно RouteAdminWindow
    routeAdminWindow->show();
    // Закрываем текущее окно (TariffAdminWindow)
    this->close();
    */
}


void TariffAdminWindow::on_pushButton_7_clicked()
{
    // Создаем экземпляр окна StationAdminWindow
    StationAdminWIndow *stationAdminWindow = StationAdminWIndow::getInstance();
    stationAdminWindow->raise();
    stationAdminWindow->activateWindow();
    stationAdminWindow->show();
    this->close();

    /*
    // Создаем экземпляр окна StationAdminWindow
    StationAdminWIndow *stationAdminWindow = new StationAdminWIndow();
    // Показываем окно StationAdminWindow
    stationAdminWindow->show();
    // Закрываем текущее окно (TariffAdminWindow)
    this->close();
    */
}


void TariffAdminWindow::on_pushButton_5_clicked()
{
    // Создаем экземпляр окна TrainAdminWindow
    TrainAdminWindow *trainAdminWindow = TrainAdminWindow::getInstance();
    trainAdminWindow->raise();
    trainAdminWindow->activateWindow();
    trainAdminWindow->show();
    this->close();

    /*
    // Создаем экземпляр окна TrainAdminWindow
    TrainAdminWindow *trainAdminWindow = new TrainAdminWindow();
    // Показываем окно trainAdminWindow
    trainAdminWindow->show();
    // Закрываем текущее окно (TariffAdminWindow)
    this->close();
    */
}

void TariffAdminWindow::on_pushButton_4_clicked()
{
    MainWindow *mainWindow = MainWindow::getInstance();
    mainWindow->raise();
    mainWindow->activateWindow();
    mainWindow->show();
    this->close();

    /*
    // Создаем экземпляр окна MainWindow
    MainWindow *mainWindow = new MainWindow();
    // Показываем окно MainWindow
    mainWindow->show();
    // Закрываем текущее окно (TariffAdminWindow)
    this->close();
    */
}

bool TariffAdminWindow::eventFilter(QObject *obj, QEvent *event)
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
                    updateButtonIcon(button, ":/appendAdminButton2.png");
                } else if (button == ui->pushButton_10) {
                    updateButtonIcon(button, ":/changeAdminButton2.png");
                } else if (button == ui->pushButton_11) {
                    updateButtonIcon(button, ":/removeAdminNewButton2.png");
                } else if (button == ui->pushButton_12) {
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
                    updateButtonIcon(button, ":/appendAdminButton_1.png");
                } else if (button == ui->pushButton_10) {
                    updateButtonIcon(button, ":/changeAdminButton.png");
                } else if (button == ui->pushButton_11) {
                    updateButtonIcon(button, ":/removeAdminNewButton.png");
                } else if (button == ui->pushButton_12) {
                    updateButtonIcon(button, ":/trainStationButton2.png");
                }
            }
        }
        return true;
    }
    return QWidget::eventFilter(obj, event);
}

void TariffAdminWindow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
}

void TariffAdminWindow::on_pushButton_9_clicked()
{
    TariffAddWindow *tariffAddWindow = TariffAddWindow::getInstance();
    tariffAddWindow->raise();
    tariffAddWindow->activateWindow();
    connect(tariffAddWindow, &TariffAddWindow::dataChanged, this, &TariffAdminWindow::updateModel); //
    tariffAddWindow->show();
    this->close();
}

void TariffAdminWindow::updateModel() {
    // CustomSqlTableModel *model = static_cast<CustomSqlTableModel*>(ui->tableView->model()); // ПОМЕНЯТЬ НА CustomSqlTableModel
    //QSqlTableModel *model = static_cast<QSqlTableModel*>(ui->tableView->model());

    CustomSqlTableModel *model = static_cast<CustomSqlTableModel*>(ui->tableView->model());

    if (model) {
        model->select();  // Перезагружает данные из базы данных, обновляя таблицу
    }
}

void TariffAdminWindow::on_pushButton_10_clicked() {
    QModelIndexList selected = ui->tableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Предупреждение", "Не выбран ни один тариф!");
        return;
    }

    int row = selected.first().row();
    int tariffId = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toInt();
    QString tariffName = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString();
    QString route = ui->tableView->model()->data(ui->tableView->model()->index(row, 2)).toString();
    QString station = ui->tableView->model()->data(ui->tableView->model()->index(row, 3)).toString();
    QString details = ui->tableView->model()->data(ui->tableView->model()->index(row, 4)).toString(); // ???????????????????????????????????????????????????????????????????????????????????
    QString price = ui->tableView->model()->data(ui->tableView->model()->index(row, 5)).toString(); // ???????????????????????????????????????????????????????????????????????????????????

    TariffChangeWindow *changeWindow = TariffChangeWindow::getInstance();
    changeWindow->setTariffData(tariffId, tariffName, route, station, details, price);

    connect(changeWindow, &TariffChangeWindow::dataChanged, this, &TariffAdminWindow::updateModel);
    connect(changeWindow, &TariffChangeWindow::closing, this, &TariffAdminWindow::show);

    this->hide();
    changeWindow->show();
}

void TariffAdminWindow::on_pushButton_11_clicked()
{
    QModelIndexList selected = ui->tableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Предупреждение", "Не выбран ни один тариф!");
        return;
    }

    int row = selected.first().row();
    QModelIndex index = ui->tableView->model()->index(row, 0);

    CustomSqlTableModel *model = qobject_cast<CustomSqlTableModel*>(ui->tableView->model());
    if (!model) {
        QMessageBox::critical(this, "Ошибка", "Не удалось получить модель данных.");
        return;
    }

    int routeId = model->getRouteId(index);
    int stationId = model->getStationId(index);
    QString tariffName = ui->tableView->model()->data(ui->tableView->model()->index(row, 3)).toString();

    // Чекаем для отладки
    //qDebug() << "Route ID: " << routeId;
    //qDebug() << "Station ID: " << stationId;
    //qDebug() << "Tariff Name: " << tariffName;

    // Удаляем запись на основе route_id, station_id и tariff_name
    QSqlQuery deleteQuery(DatabaseManager::instance().database());
    deleteQuery.prepare("SELECT delete_tariff(:route_id, :station_id, :tariff_name)");
    deleteQuery.bindValue(":route_id", routeId);
    deleteQuery.bindValue(":station_id", stationId);
    deleteQuery.bindValue(":tariff_name", tariffName);

    if (!deleteQuery.exec()) {
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + deleteQuery.lastError().text());
    } else {
        deleteQuery.next();
        if (deleteQuery.value(0).toBool()) {
            QMessageBox::information(this, "Успех", "Тариф успешно удалён.");
            updateModel();  // Обновляем модель после удаления
        } else {
            QMessageBox::warning(this, "Ошибка", "Такого тарифа не существует.");
        }
    }
}

/*
void TariffAdminWindow::on_pushButton_11_clicked()
{
    QModelIndexList selected = ui->tableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Предупреждение", "Не выбран ни один тариф!");
        return;
    }

    int row = selected.first().row();
    int routeId = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toInt();
    int stationId = ui->tableView->model()->data(ui->tableView->model()->index(row, 2)).toInt();
    QString tariffName = ui->tableView->model()->data(ui->tableView->model()->index(row, 3)).toString();

    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT delete_tariff(:route_id, :station_id, :tariff_name)");
    query.bindValue(":route_id", routeId);
    query.bindValue(":station_id", stationId);
    query.bindValue(":tariff_name", tariffName);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
    } else {
        query.next();
        if (query.value(0).toBool()) {
            QMessageBox::information(this, "Успех", "Тариф успешно удален.");
            updateModel();  // Обновляем модель после удаления
        } else {
            QMessageBox::warning(this, "Ошибка", "Такого тарифа не существует.");
        }
    }
}
*/


void TariffAdminWindow::on_pushButton_12_clicked()
{
    TrainStationAdminWindow *trainStationAdminWindow = TrainStationAdminWindow::getInstance();
    trainStationAdminWindow->raise();
    trainStationAdminWindow->activateWindow();
    trainStationAdminWindow->show();
    this->close();
}

