#include "stationadminwindow.h"
#include "ui_stationadminwindow.h"
#include "tariffadminwindow.h"
#include "routeadminwindow.h"
#include "stationaddwindow.h"
#include "trainadminwindow.h"
#include "stationchangewindow.h"
#include "stationadminwindow.h"
#include "mainwindow.h"
#include <QMouseEvent>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QVBoxLayout>
#include "DatabaseManager.h" // Включаем заголовочный файл для DatabaseManager

StationAdminWIndow* StationAdminWIndow::instance = nullptr; //

StationAdminWIndow* StationAdminWIndow::getInstance(QWidget *parent) { //
    if (!instance)
        instance = new StationAdminWIndow(parent);
    return instance;
}

StationAdminWIndow::StationAdminWIndow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StationAdminWIndow)
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
        QSqlTableModel *model = new QSqlTableModel(this, dbManager.database());
        model->setTable("stations");
        model->select();

        // Устанавливаем режим растягивания столбцов
        //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        // Устанавливаем модель в tableView
        ui->tableView->setModel(model);

        // Скрываем столбец station_id
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
    ui->pushButton_8->installEventFilter(this);
    ui->pushButton_9->installEventFilter(this);
    ui->pushButton_10->installEventFilter(this);
    ui->pushButton_11->installEventFilter(this);

    ui->pushButton_10->disconnect(); // Отключаем все сигналы, связанные с этой кнопкой
    connect(ui->pushButton_10, &QPushButton::clicked, this, &StationAdminWIndow::on_pushButton_10_clicked);
}

StationAdminWIndow::~StationAdminWIndow()
{
    delete ui;

    instance = nullptr; // Убедитесь, что instance установлен в nullptr при удалении
}

// Определяем слот для закрытия текущего окна
void StationAdminWIndow::on_pushButton_2_clicked()
{
    // Закрываем текущее окно (StationAdminWIndow)
    this->close();

    instance = nullptr;
}

// Определяем слот для сворачивания текущего окна
void StationAdminWIndow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (StationAdminWIndow)
    this->showMinimized();
}

void StationAdminWIndow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void StationAdminWIndow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void StationAdminWIndow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

// Определяем обработчик для кнопки pushButton_8
void StationAdminWIndow::on_pushButton_8_clicked()
{
    TariffAdminWindow *tariffAdminWindow = TariffAdminWindow::getInstance();
    tariffAdminWindow->raise();
    tariffAdminWindow->activateWindow();
    tariffAdminWindow->show();
    this->close();

    /*
    // Создаем экземпляр окна TariffUserWindow
    TariffAdminWindow *tariffAdminWindow = new TariffAdminWindow();
    // Показываем окно TariffUserWindow
    tariffAdminWindow->show();
    // Закрываем текущее окно (StationAdminWIndow)
    this->close();
    */
}

void StationAdminWIndow::on_pushButton_5_clicked()
{
    TrainAdminWindow *trainAdminWindow = TrainAdminWindow::getInstance();
    trainAdminWindow->raise();
    trainAdminWindow->activateWindow();
    trainAdminWindow->show();
    this->close();

    /*
    // Создаем экземпляр окна TrainAdminWindow
    TrainAdminWindow *trainAdminWindow = new TrainAdminWindow();
    // Показываем окно TrainAdminWindow
    trainAdminWindow->raise();
    trainAdminWindow->activateWindow();
    trainAdminWindow->show();
    // Закрываем текущее окно (StationAdminWIndow)
    this->close();
    */
}

void StationAdminWIndow::on_pushButton_4_clicked()
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
    mainWindow->raise();
    mainWindow->activateWindow();
    mainWindow->show();
    // Закрываем текущее окно (StationAdminWIndow)
    this->close();
    */
}


void StationAdminWIndow::on_pushButton_6_clicked()
{
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
    // Закрываем текущее окно (StationAdminWIndow)
    this->close();
    */
}

bool StationAdminWIndow::eventFilter(QObject *obj, QEvent *event)
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
            } else if (button == ui->pushButton_9) {
                updateButtonIcon(button, ":/appendAdminButton2.png");
            } else if (button == ui->pushButton_10) {
                updateButtonIcon(button, ":/changeAdminButton2.png");
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
            } else if (button == ui->pushButton_8) {
                updateButtonIcon(button, ":/tariffsButton2New.png");
            } else if (button == ui->pushButton_9) {
                updateButtonIcon(button, ":/appendAdminButton_1.png");
            } else if (button == ui->pushButton_10) {
                updateButtonIcon(button, ":/changeAdminButton.png");
            } else if (button == ui->pushButton_11) {
                updateButtonIcon(button, ":/removeAdminNewButton.png");
            }
        }
        return true;
    }
    return QWidget::eventFilter(obj, event);
}

void StationAdminWIndow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
}


void StationAdminWIndow::on_pushButton_9_clicked()
{
    StationAddWindow *stationAddWindow = StationAddWindow::getInstance();
    stationAddWindow->raise();
    stationAddWindow->activateWindow();
    connect(stationAddWindow, &StationAddWindow::dataChanged, this, &StationAdminWIndow::updateModel); //
    stationAddWindow->show();
    this->close();

    /*
    // Создаем экземпляр окна StationAddWindow
    StationAddWindow *stationAddWindow = new StationAddWindow();
    // Показываем окно StationAddWindow
    stationAddWindow->show();
    // Закрываем текущее окно (StationAdminWIndow)
    this->close();
    */
}

void StationAdminWIndow::updateModel() {
    QSqlTableModel *model = static_cast<QSqlTableModel*>(ui->tableView->model());
    if (model) {
        model->select();  // Перезагружает данные из базы данных, обновляя таблицу
    }
}

void StationAdminWIndow::on_pushButton_10_clicked() {

    QModelIndexList selected = ui->tableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Предупреждение", "Не выбрана ни одна станция!");
        return;
    }

    int row = selected.first().row();
    int stationId = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toInt();
    QString stationName = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString();

    StationChangeWindow *changeWindow = StationChangeWindow::getInstance();
    changeWindow->setStationData(stationId, stationName);

    connect(changeWindow, &StationChangeWindow::dataChanged, this, &StationAdminWIndow::updateModel);
    connect(changeWindow, &StationChangeWindow::closing, this, &StationAdminWIndow::show);

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

void StationAdminWIndow::on_pushButton_11_clicked()
{
    QModelIndexList selected = ui->tableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Предупреждение", "Не выбрана ни одна станция!");
        return;
    }

    int row = selected.first().row();
    QString stationName = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString();
    QString city = ui->tableView->model()->data(ui->tableView->model()->index(row, 2)).toString();

    QSqlQuery query;
    query.prepare("SELECT delete_station(:p_station_name, :p_city)");
    query.bindValue(":p_station_name", stationName);
    query.bindValue(":p_city", city);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
    } else {
        query.next();
        if (query.value(0).toBool()) {
            QMessageBox::information(this, "Успех", "Станция успешно удалена.");
            updateModel();  // Обновляем модель после удаления
        } else {
            QMessageBox::warning(this, "Ошибка", "Такой станции не существует.");
        }
    }
}
