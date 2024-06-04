#include "routeadminwindow.h"
#include "ui_routeadminwindow.h"
#include "tariffadminwindow.h"
#include "routeaddwindow.h"
#include "routechangewindow.h"
#include "stationadminwindow.h"
#include "trainadminwindow.h"
#include "trainstationadminwindow.h"
#include "mainwindow.h"
#include <QMouseEvent>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QVBoxLayout>
#include "DatabaseManager.h" // Включаем заголовочный файл для DatabaseManager
#include "customsqltablemodel.h"

RouteAdminWindow* RouteAdminWindow::instance = nullptr; //

RouteAdminWindow* RouteAdminWindow::getInstance(QWidget *parent) { //
    if (!instance)
        instance = new RouteAdminWindow(parent);
    return instance;
}

RouteAdminWindow::RouteAdminWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RouteAdminWindow)
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
        CustomSqlTableModel *model = new CustomSqlTableModel(this, dbManager.database());
        model->setTable("routes");
        model->select();

        // Устанавливаем пользовательские заголовки
        model->setHeaderData(model->fieldIndex("departure_point"), Qt::Horizontal, "Город отправления"); // "Маршрут (Время)"
        model->setHeaderData(model->fieldIndex("destination"), Qt::Horizontal, "Город прибытия"); // "Название станции (Город)"
        model->setHeaderData(model->fieldIndex("trip_duration"), Qt::Horizontal, "Время поездки"); //
        model->setHeaderData(model->fieldIndex("parent_route_id"), Qt::Horizontal, "Основной маршрут"); //

        //qDebug() << "CustomSqlTableModel - fieldIndex for route_id:" << model->fieldIndex("route_id");

        /*
        // Создаем модель для отображения данных
        QSqlTableModel *model = new QSqlTableModel(this, dbManager.database());
        model->setTable("routes");
        model->select();

        // Добавление новой колонки для текстового представления маршрута
        while (model->canFetchMore()) {
            model->fetchMore();
        }

        for (int row = 0; row < model->rowCount(); ++row) {
            int parentRouteId = model->record(row).value("parent_route_id").toInt();
            if (!model->record(row).isNull("parent_route_id")) {
                QSqlQuery query;
                query.prepare("SELECT departure_point, destination, trip_duration FROM routes WHERE route_id = :id");
                query.bindValue(":id", parentRouteId);
                if (query.exec() && query.next()) {
                    QString departurePoint = query.value(0).toString();
                    QString destination = query.value(1).toString();
                    QString tripDuration = query.value(2).toString();
                    if (!tripDuration.contains("час")) {
                        tripDuration += " часа";
                    }
                    QString parentRouteText = departurePoint + " -> " + destination + " (" + tripDuration + ")";
                    model->setData(model->index(row, model->fieldIndex("parent_route_id")), parentRouteText);
                }
            }
        }

        */

        /*
        // Устанавливаем модель в tableView
        ui->tableView->setModel(model);

        // Скрываем столбец route_id
        ui->tableView->hideColumn(0);

        // Устанавливаем режим растягивания столбцов
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

        // Вызываем resizeColumnsToContents, чтобы столбцы равномерно растянулись
        ui->tableView->resizeColumnsToContents();

        // Перераспределяем ширину столбцов, чтобы они были одинаковыми
        int columnCount = ui->tableView->horizontalHeader()->count();
        int tableWidth = ui->tableView->viewport()->width();
        int columnWidth = tableWidth / columnCount;
        for (int i = 0; i < columnCount; ++i) {
            ui->tableView->setColumnWidth(i, columnWidth);
        }
        */


        // Устанавливаем режим растягивания столбцов
        //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        // Устанавливаем модель в tableView
        ui->tableView->setModel(model);

        // Скрываем столбец route_id
        ui->tableView->hideColumn(0);

        //ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

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
    ui->pushButton_7->installEventFilter(this);
    ui->pushButton_8->installEventFilter(this);
    ui->pushButton_9->installEventFilter(this);
    ui->pushButton_10->installEventFilter(this);
    ui->pushButton_11->installEventFilter(this);
    ui->pushButton_12->installEventFilter(this);

    ui->pushButton_10->disconnect(); // Отключаем все сигналы, связанные с этой кнопкой
    connect(ui->pushButton_10, &QPushButton::clicked, this, &RouteAdminWindow::on_pushButton_10_clicked);
}

RouteAdminWindow::~RouteAdminWindow()
{
    delete ui;

    instance = nullptr; //
}

// Определяем слот для закрытия текущего окна
void RouteAdminWindow::on_pushButton_2_clicked()
{
    // Закрываем текущее окно (TrainUserWindow)
    this->close();

    instance = nullptr;
}

// Определяем слот для сворачивания текущего окна
void RouteAdminWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (TrainUserWindow)
    this->showMinimized();
}

void RouteAdminWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void RouteAdminWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void RouteAdminWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

// Определяем обработчик для кнопки pushButton_8
void RouteAdminWindow::on_pushButton_8_clicked()
{
    qDebug() << "Opening TariffAdminWindow as" << DatabaseManager::instance().currentUserName();
    TariffAdminWindow *tariffAdminWindow = TariffAdminWindow::getInstance();
    tariffAdminWindow->raise();
    tariffAdminWindow->activateWindow();
    tariffAdminWindow->show();
    this->close();

    /*
    // Создаем экземпляр окна TariffAdminWindow
    TariffAdminWindow *tariffAdminWindow = new TariffAdminWindow();
    // Показываем окно TariffAdminWindow
    tariffAdminWindow->show();
    // Закрываем текущее окно (RouteAdminWindow)
    this->close();
    */
}


void RouteAdminWindow::on_pushButton_7_clicked()
{
    qDebug() << "Opening StationAdminWIndow as" << DatabaseManager::instance().currentUserName();
    StationAdminWIndow *stationAdminWindow = StationAdminWIndow::getInstance();
    stationAdminWindow->raise();
    stationAdminWindow->activateWindow();
    stationAdminWindow->show();
    this->close();

    /*
    // Создаем экземпляр окна StationAdminWIndow
    StationAdminWIndow *stationAdminWindow = new StationAdminWIndow();
    // Показываем окно StationAdminWIndow
    stationAdminWindow->show();
    // Закрываем текущее окно (RouteAdminWindow)
    this->close();
    */
}


void RouteAdminWindow::on_pushButton_5_clicked()
{
    qDebug() << "Opening TrainAdminWindow as" << DatabaseManager::instance().currentUserName();
    TrainAdminWindow *trainAdminWindow = TrainAdminWindow::getInstance();
    trainAdminWindow->raise();
    trainAdminWindow->activateWindow();
    trainAdminWindow->show();
    this->close();

    /*
    // Создаем экземпляр окна TrainAdminWindow
    TrainAdminWindow *trainAdminWindow = new TrainAdminWindow();
    // Показываем окно TrainAdminWindow
    trainAdminWindow->show();
    // Закрываем текущее окно (RouteAdminWindow)
    this->close();
    */
}

void RouteAdminWindow::on_pushButton_4_clicked()
{
    qDebug() << "Opening MainWindow as" << DatabaseManager::instance().currentUserName();
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
    // Закрываем текущее окно (RouteAdminWindow)
    this->close();
    */
}

bool RouteAdminWindow::eventFilter(QObject *obj, QEvent *event)
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
            } else if (button == ui->pushButton_7) {
                updateButtonIcon(button, ":/stationsButton3.png");
            } else if (button == ui->pushButton_8) {
                updateButtonIcon(button, ":/tariffsButton3.png");
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
            } else if (button == ui->pushButton_7) {
                updateButtonIcon(button, ":/stationsButton2New.png");
            } else if (button == ui->pushButton_8) {
                updateButtonIcon(button, ":/tariffsButton2New.png");
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
        return true;
    }
    return QWidget::eventFilter(obj, event);
}

void RouteAdminWindow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
}

void RouteAdminWindow::on_pushButton_9_clicked()
{
    qDebug() << "Opening RouteAddWindow as" << DatabaseManager::instance().currentUserName();
    RouteAddWindow *routeAddWindow = RouteAddWindow::getInstance();
    routeAddWindow->raise();
    routeAddWindow->activateWindow();
    connect(routeAddWindow, &RouteAddWindow::dataChanged, this, &RouteAdminWindow::updateModel); //
    routeAddWindow->show();
    this->close();
}

/*
void RouteAdminWindow::updateModel() {
    QSqlTableModel *model = static_cast<QSqlTableModel*>(ui->tableView->model());
    if (model) {
        model->select();  // Перезагружает данные из базы данных, обновляя таблицу
    }
}
*/
void RouteAdminWindow::updateModel() {
    CustomSqlTableModel *model = static_cast<CustomSqlTableModel*>(ui->tableView->model());

    if (model) {
        model->select();  // Перезагружает данные из базы данных, обновляя таблицу
    }

    /*
    QSqlTableModel *model = static_cast<QSqlTableModel*>(ui->tableView->model());

    if (model) {
        model->select();  // Перезагружает данные из базы данных, обновляя таблицу

        // Обновление текстового представления маршрутов
        while (model->canFetchMore()) {
            model->fetchMore();
        }

        for (int row = 0; row < model->rowCount(); ++row) {
            int parentRouteId = model->record(row).value("parent_route_id").toInt();
            if (!model->record(row).isNull("parent_route_id")) {
                QSqlQuery query;
                query.prepare("SELECT departure_point, destination, trip_duration FROM routes WHERE route_id = :id");
                query.bindValue(":id", parentRouteId);
                if (query.exec() && query.next()) {
                    QString departurePoint = query.value(0).toString();
                    QString destination = query.value(1).toString();
                    QString tripDuration = query.value(2).toString();
                    if (!tripDuration.contains("час")) {
                        tripDuration += " часа";
                    }
                    QString parentRouteText = departurePoint + " -> " + destination + " (" + tripDuration + ")";
                    model->setData(model->index(row, model->fieldIndex("parent_route_id")), parentRouteText);
                }
            }
        }
    }
    */
}

void RouteAdminWindow::on_pushButton_10_clicked() {
    qDebug() << "Opening RouteChangeWindow as" << DatabaseManager::instance().currentUserName();
    QModelIndexList selected = ui->tableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Предупреждение", "Не выбран ни один маршрут!");
        return;
    }

    /*
    int row = selected.first().row();
    QModelIndex routeIndex = ui->tableView->model()->index(row, 0); //
    //int routeId = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toInt();

    //int routeId = ui->tableView->model()->data(routeIndex).toInt();

    QVariant routeIdVariant = ui->tableView->model()->data(routeIndex);
    int routeId = routeIdVariant.toInt();*/
    int row = selected.first().row();
    QModelIndex routeIndex = ui->tableView->model()->index(row, 0);
    CustomSqlTableModel *model = qobject_cast<CustomSqlTableModel *>(ui->tableView->model());
    int routeId = model->getRouteId(routeIndex);

    //int routeId = routeIndex.data(Qt::DisplayRole).toInt();
    //int routeId = routeIndex.data().toInt();  // Извлечение данных напрямую

    /*
    qDebug() << "RouteAdminWindow::on_pushButton_10_clicked - row:" << row
             << "routeIndex:" << routeIndex
             //<< "routeIdVariant:" << routeIdVariant
             << "routeId:" << routeId;*/

    QString departurePoint = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString();
    QString destination = ui->tableView->model()->data(ui->tableView->model()->index(row, 2)).toString();
    QString tripDuration = ui->tableView->model()->data(ui->tableView->model()->index(row, 3)).toString();

    QString routeDescription = QString("%1 -> %2 (%3)").arg(departurePoint, destination, tripDuration);

    /*qDebug() << "RouteAdminWindow::on_pushButton_10_clicked - routeId:" << routeId
             << "routeDescription:" << routeDescription;*/

    RouteChangeWindow *changeWindow = RouteChangeWindow::getInstance();
    changeWindow->setRouteData(routeId, routeDescription, departurePoint, destination, tripDuration);

    connect(changeWindow, &RouteChangeWindow::dataChanged, this, &RouteAdminWindow::updateModel);
    connect(changeWindow, &RouteChangeWindow::closing, this, &RouteAdminWindow::show);

    this->hide();
    changeWindow->show();

    /*
    StationChangeWindow *changeWindow = new StationChangeWindow(nullptr);
    changeWindow->setStationData(stationId, stationName);

    // Подключение сигнала к слоту для обновления таблицы после изменения данных
    connect(changeWindow, &StationChangeWindow::dataChanged, this, &StationAdminWIndow::updateModel);

    connect(changeWindow, &StationChangeWindow::closing, this, &StationAdminWIndow::show);

    //qDebug() << "Current window type before hiding:" << this->metaObject()->className();
    this->hide();  // Должно скрыть StationAdminWIndow

    changeWindow->show();
    */
}

void RouteAdminWindow::on_pushButton_11_clicked()
{
    QModelIndexList selected = ui->tableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Предупреждение", "Не выбран ни один маршрут!");
        return;
    }

    int row = selected.first().row();
    QString departurePoint = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString();
    QString destination = ui->tableView->model()->data(ui->tableView->model()->index(row, 2)).toString();
    QString tripDuration = ui->tableView->model()->data(ui->tableView->model()->index(row, 3)).toString();

    QSqlQuery query;
    query.prepare("SELECT delete_route(:p_departure_point, :p_destination, :p_trip_duration)");
    query.bindValue(":p_departure_point", departurePoint);
    query.bindValue(":p_destination", destination);
    query.bindValue(":p_trip_duration", tripDuration);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
    } else {
        query.next();
        if (query.value(0).toBool()) {
            QMessageBox::information(this, "Успех", "Маршрут успешно удалён.");
            updateModel();  // Обновляем модель после удаления
            TariffAdminWindow::getInstance()->updateModel(); //
            qDebug() << "Deleting RouteAdminWindow as" << DatabaseManager::instance().currentUserName();
        } else {
            QMessageBox::warning(this, "Ошибка", "Такого маршрута не существует.");
        }
    }
}


void RouteAdminWindow::on_pushButton_12_clicked()
{
    qDebug() << "Opening TrainStationAdminWindow as" << DatabaseManager::instance().currentUserName();
    TrainStationAdminWindow *trainStationAdminWindow = TrainStationAdminWindow::getInstance();
    trainStationAdminWindow->raise();
    trainStationAdminWindow->activateWindow();
    trainStationAdminWindow->show();
    this->close();
}

