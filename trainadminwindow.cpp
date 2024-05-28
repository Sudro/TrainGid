#include "trainadminwindow.h"
#include "ui_trainadminwindow.h"
#include "tariffadminwindow.h"
#include "stationadminwindow.h"
#include "routeadminwindow.h" // Включаем заголовочный файл для RouteUserwindow
#include "trainaddwindow.h"
//#include "traindeletewindow.h"
#include "trainchangewindow.h"
#include "mainwindow.h"
#include <QMouseEvent>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QVBoxLayout>
#include "DatabaseManager.h" // Включаем заголовочный файл для DatabaseManager

TrainAdminWindow* TrainAdminWindow::instance = nullptr; //

TrainAdminWindow* TrainAdminWindow::getInstance(QWidget *parent) { //
    if (!instance)
        instance = new TrainAdminWindow(parent);
    return instance;
}

TrainAdminWindow::TrainAdminWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainAdminWindow)
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
        model->setTable("trains");
        model->select();

        // Устанавливаем режим растягивания столбцов
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        // Устанавливаем модель в tableView
        ui->tableView->setModel(model);

        // Скрываем столбец train_id
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
    ui->pushButton_6->installEventFilter(this);
    ui->pushButton_7->installEventFilter(this);
    ui->pushButton_8->installEventFilter(this);
    ui->pushButton_9->installEventFilter(this);
    ui->pushButton_10->installEventFilter(this);
    ui->pushButton_11->installEventFilter(this);

    // Соединение сигнала о выборе элемента с методом открытия окна изменения
    //connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &TrainAdminWindow::on_pushButton_10_clicked);

    ui->pushButton_10->disconnect(); // Отключаем все сигналы, связанные с этой кнопкой
    connect(ui->pushButton_10, &QPushButton::clicked, this, &TrainAdminWindow::on_pushButton_10_clicked);
}

TrainAdminWindow::~TrainAdminWindow()
{
    delete ui;
    instance = nullptr;
}

// Определяем слот для закрытия текущего окна
void TrainAdminWindow::on_pushButton_2_clicked()
{
    // Закрываем текущее окно (TrainAdminWindow)
    this->close();
    instance = nullptr;
}

// Определяем слот для сворачивания текущего окна
void TrainAdminWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (TrainAdminWindow)
    this->showMinimized();
}

void TrainAdminWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void TrainAdminWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void TrainAdminWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

// Определяем обработчик для кнопки pushButton_8
void TrainAdminWindow::on_pushButton_8_clicked()
{
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
    // Закрываем текущее окно (TrainAdminWindow)
    this->close();
    */
}


void TrainAdminWindow::on_pushButton_7_clicked()
{
    /*
    // Создаем экземпляр окна StationAdminWIndow
    StationAdminWIndow *stationAdminWindow = new StationAdminWIndow();
    // Показываем окно StationAdminWIndow
    stationAdminWindow->show();
    // Закрываем текущее окно (TrainAdminWindow)
    this->close();
    */

    StationAdminWIndow *stationAdminWindow = StationAdminWIndow::getInstance();
    stationAdminWindow->raise();
    stationAdminWindow->activateWindow();
    stationAdminWindow->show();
    this->close();
}


void TrainAdminWindow::on_pushButton_6_clicked()
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
    // Закрываем текущее окно (TrainAdminWindow)
    this->close();
    */
}

void TrainAdminWindow::on_pushButton_4_clicked()
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
    // Закрываем текущее окно (TrainAdminWindow)
    this->close();
    */
}

bool TrainAdminWindow::eventFilter(QObject *obj, QEvent *event)
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
                } else if (button == ui->pushButton_6) {
                    updateButtonIcon(button, ":/routeButton3.png");
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
                }
            } else if (event->type() == QEvent::Leave) {
                // Здесь можно вернуть исходную иконку кнопки
                if (button == ui->pushButton_2) {
                    updateButtonIcon(button, ":/closeIcon.png");
                } else if (button == ui->pushButton_3) {
                    updateButtonIcon(button, ":/swapIcon.png");
                } else if (button == ui->pushButton_4) {
                    updateButtonIcon(button, ":/homeButton2_New.png");
                } else if (button == ui->pushButton_6) {
                    updateButtonIcon(button, ":/routeButton2New.png");
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
                }
            }
        }
        return true;
    }
    return QWidget::eventFilter(obj, event);
}

void TrainAdminWindow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
}

void TrainAdminWindow::on_pushButton_9_clicked()
{
    TrainAddWindow *trainAddWindow = TrainAddWindow::getInstance();
    trainAddWindow->raise();
    trainAddWindow->activateWindow();
    connect(trainAddWindow, &TrainAddWindow::dataChanged, this, &TrainAdminWindow::updateModel);
    trainAddWindow->show();
    this->close();

    /*
    // Создаем экземпляр окна TrainAddWindow
    TrainAddWindow *trainAddWindow = new TrainAddWindow();
    // Показываем окно TrainAddWindow
    trainAddWindow->show();
    // Закрываем текущее окно (TrainAdminWindow)
    this->close();
    */
}

void TrainAdminWindow::updateModel() {
    QSqlTableModel *model = static_cast<QSqlTableModel*>(ui->tableView->model());
    if (model) {
        model->select();  // Перезагружает данные из базы данных, обновляя таблицу
    }
}

void TrainAdminWindow::on_pushButton_10_clicked() {

    QModelIndexList selected = ui->tableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Предупреждение", "Не выбран ни один поезд!");
        return;
    }

    int row = selected.first().row();
    int trainId = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toInt();
    QString trainNumber = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString();

    /*
    TrainChangeWindow *changeWindow = new TrainChangeWindow(nullptr);
    changeWindow->setTrainData(trainId, trainNumber);

    // Подключение сигнала к слоту для обновления таблицы после изменения данных
    connect(changeWindow, &TrainChangeWindow::dataChanged, this, &TrainAdminWindow::updateModel);

    connect(changeWindow, &TrainChangeWindow::closing, this, &TrainAdminWindow::show);

    //qDebug() << "Current window type before hiding:" << this->metaObject()->className();
    this->hide();  // Должно скрыть TrainAdminWindow

    changeWindow->show();
    */

    TrainChangeWindow *changeWindow = TrainChangeWindow::getInstance();
    changeWindow->setTrainData(trainId, trainNumber);

    connect(changeWindow, &TrainChangeWindow::dataChanged, this, &TrainAdminWindow::updateModel);
    connect(changeWindow, &TrainChangeWindow::closing, this, &TrainAdminWindow::show);

    this->hide();
    changeWindow->show();
}



void TrainAdminWindow::on_pushButton_11_clicked()
{
    QModelIndexList selected = ui->tableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Предупреждение", "Не выбран ни один поезд!");
        return;
    }

    int row = selected.first().row();
    QString trainNumber = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString();

    QSqlQuery query;
    query.prepare("SELECT delete_train(:p_train_number)");
    query.bindValue(":p_train_number", trainNumber);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
    } else {
        query.next();
        if (query.value(0).toBool()) {
            QMessageBox::information(this, "Успех", "Поезд успешно удален.");
            updateModel();  // Обновляем модель после удаления
        } else {
            QMessageBox::warning(this, "Ошибка", "Такого поезда не существует.");
        }
    }
}

