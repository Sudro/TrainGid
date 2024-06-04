#include "trainstationadminwindow.h"
#include "ui_trainstationadminwindow.h"
#include "tariffadminwindow.h"
#include "stationadminwindow.h"
#include "routeadminwindow.h"
#include "trainadminwindow.h"
#include "trainstationconnectwindow.h"
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

TrainStationAdminWindow* TrainStationAdminWindow::instance = nullptr; //

TrainStationAdminWindow* TrainStationAdminWindow::getInstance(QWidget *parent) { //
    if (!instance)
        instance = new TrainStationAdminWindow(parent);
    return instance;
}

TrainStationAdminWindow::TrainStationAdminWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainStationAdminWindow)
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
        model->setTable("trainstation");
        model->select();

        // Устанавливаем пользовательские заголовки
        model->setHeaderData(model->fieldIndex("train_id"), Qt::Horizontal, "Номер поезда (Название поезда)"); //
        model->setHeaderData(model->fieldIndex("station_id"), Qt::Horizontal, "Название станции (Название города)"); //

        // Устанавливаем режим растягивания столбцов
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        // Устанавливаем модель в tableView
        ui->tableView->setModel(model);

        // Скрываем столбец train_id
        //ui->tableView->hideColumn(0);

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
    ui->pushButton_8->installEventFilter(this);
    ui->pushButton_9->installEventFilter(this);
    ui->pushButton_11->installEventFilter(this);

    // Соединение сигнала о выборе элемента с методом открытия окна изменения
    //connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &TrainAdminWindow::on_pushButton_10_clicked);

    //ui->pushButton_10->disconnect(); // Отключаем все сигналы, связанные с этой кнопкой
    //connect(ui->pushButton_10, &QPushButton::clicked, this, &TrainAdminWindow::on_pushButton_10_clicked);
}

TrainStationAdminWindow::~TrainStationAdminWindow()
{
    delete ui;
    instance = nullptr;
}

// Определяем слот для закрытия текущего окна
void TrainStationAdminWindow::on_pushButton_2_clicked()
{
    // Закрываем текущее окно (TrainStationAdminWindow)
    this->close();
    instance = nullptr;
}

// Определяем слот для сворачивания текущего окна
void TrainStationAdminWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (TrainStationAdminWindow)
    this->showMinimized();
}

void TrainStationAdminWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void TrainStationAdminWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void TrainStationAdminWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

void TrainStationAdminWindow::on_pushButton_4_clicked()
{
    qDebug() << "Opening MainWindow as" << DatabaseManager::instance().currentUserName();
    MainWindow *mainWindow = MainWindow::getInstance();
    mainWindow->raise();
    mainWindow->activateWindow();
    mainWindow->show();
    this->close();
}

void TrainStationAdminWindow::on_pushButton_5_clicked()
{
    qDebug() << "Opening TrainAdminWindow as" << DatabaseManager::instance().currentUserName();
    TrainAdminWindow *trainAdminWindow = TrainAdminWindow::getInstance();
    trainAdminWindow->raise();
    trainAdminWindow->activateWindow();
    trainAdminWindow->show();
    this->close();
}

void TrainStationAdminWindow::on_pushButton_6_clicked()
{
    qDebug() << "Opening RouteAdminWindow as" << DatabaseManager::instance().currentUserName();
    RouteAdminWindow *routeAdminWindow = RouteAdminWindow::getInstance();
    routeAdminWindow->raise();
    routeAdminWindow->activateWindow();
    routeAdminWindow->show();
    this->close();
}

void TrainStationAdminWindow::on_pushButton_7_clicked()
{
    qDebug() << "Opening StationAdminWIndow as" << DatabaseManager::instance().currentUserName();
    StationAdminWIndow *stationAdminWindow = StationAdminWIndow::getInstance();
    stationAdminWindow->raise();
    stationAdminWindow->activateWindow();
    stationAdminWindow->show();
    this->close();
}

void TrainStationAdminWindow::on_pushButton_8_clicked()
{
    qDebug() << "Opening TariffAdminWindow as" << DatabaseManager::instance().currentUserName();
    TariffAdminWindow *tariffAdminWindow = TariffAdminWindow::getInstance();
    tariffAdminWindow->raise();
    tariffAdminWindow->activateWindow();
    tariffAdminWindow->show();
    this->close();
}

bool TrainStationAdminWindow::eventFilter(QObject *obj, QEvent *event)
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
                } else if (button == ui->pushButton_8) {
                    updateButtonIcon(button, ":/tariffsButton3.png");
                } else if (button == ui->pushButton_9) {
                    updateButtonIcon(button, ":/appendAdminButton2.png");
                } else if (button == ui->pushButton_11) {
                    updateButtonIcon(button, ":/removeAdminNewButton2.png");
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
                } else if (button == ui->pushButton_8) {
                    updateButtonIcon(button, ":/tariffsButton2New.png");
                } else if (button == ui->pushButton_9) {
                    updateButtonIcon(button, ":/appendAdminButton_1.png");
                } else if (button == ui->pushButton_11) {
                    updateButtonIcon(button, ":/removeAdminNewButton.png");
                }
            }
        }
        return true;
    }
    return QWidget::eventFilter(obj, event);
}

void TrainStationAdminWindow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
}

void TrainStationAdminWindow::updateModel() {
    QSqlTableModel *model = static_cast<QSqlTableModel*>(ui->tableView->model());
    if (model) {
        model->select();  // Перезагружает данные из базы данных, обновляя таблицу
    }
}

void TrainStationAdminWindow::on_pushButton_9_clicked()
{
    qDebug() << "Opening TrainStationConnectWindow as" << DatabaseManager::instance().currentUserName();
    TrainStationConnectWindow *trainStationConnectWindow = TrainStationConnectWindow::getInstance();
    trainStationConnectWindow->raise();
    trainStationConnectWindow->activateWindow();
    connect(trainStationConnectWindow, &TrainStationConnectWindow::dataChanged, this, &TrainStationAdminWindow::updateModel); //
    trainStationConnectWindow->show();
    this->close();
}


void TrainStationAdminWindow::on_pushButton_11_clicked()
{
    QModelIndexList selected = ui->tableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Предупреждение", "Не выбрана ни одна связь!");
        return;
    }

    int row = selected.first().row();
    QModelIndex index = ui->tableView->model()->index(row, 0);

    CustomSqlTableModel *model = qobject_cast<CustomSqlTableModel*>(ui->tableView->model());
    if (!model) {
        QMessageBox::critical(this, "Ошибка", "Не удалось получить модель данных.");
        return;
    }

    int trainId = model->getTrainId(index);
    int stationId = model->getStationId(index);
    //QString tariffName = ui->tableView->model()->data(ui->tableView->model()->index(row, 3)).toString();



    // Чекаем для отладки
    //qDebug() << "Route ID: " << routeId;
    //qDebug() << "Station ID: " << stationId;
    //qDebug() << "Tariff Name: " << tariffName;

    // Удаляем запись на основе route_id, station_id и tariff_name
    QSqlQuery deleteQuery(DatabaseManager::instance().database());
    deleteQuery.prepare("SELECT delete_trainstation(:train_id, :station_id)");
    deleteQuery.bindValue(":train_id", trainId);
    deleteQuery.bindValue(":station_id", stationId);

    if (!deleteQuery.exec()) {
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + deleteQuery.lastError().text());
    } else {
        deleteQuery.next();
        if (deleteQuery.value(0).toBool()) {
            QMessageBox::information(this, "Успех", "Cвязь успешно удалена.");
            updateModel();  // Обновляем модель после удаления
            qDebug() << "Deleting TrainStationAdminWindow as" << DatabaseManager::instance().currentUserName();
        } else {
            QMessageBox::warning(this, "Ошибка", "Такой связи не существует.");
        }
    }
}

