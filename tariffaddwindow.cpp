#include "tariffaddwindow.h"
#include "tariffadminwindow.h"
#include "ui_tariffaddwindow.h"
#include "databasemanager.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMouseEvent>

TariffAddWindow* TariffAddWindow::instance = nullptr; //

TariffAddWindow* TariffAddWindow::getInstance(QWidget *parent) { //
    if (!instance) {
        instance = new TariffAddWindow(parent);
    }
    return instance;
}

TariffAddWindow::TariffAddWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffAddWindow)
{
    ui->setupUi(this);

    // Устанавливаем флаг Qt::FramelessWindowHint
    setWindowFlags(Qt::FramelessWindowHint);

    ui->pushButton_2->installEventFilter(this);
    ui->pushButton_3->installEventFilter(this);
    ui->pushButton_9->installEventFilter(this);

    ui->lineEdit->setPlaceholderText("Введите название тарифа");
    ui->lineEdit_5->setPlaceholderText("Введите описание тарифа");
    ui->lineEdit_6->setPlaceholderText("Введите цену тарифа");
    ui->comboBox->setPlaceholderText("Выберите маршрут");
    ui->comboBox_2->setPlaceholderText("Выберите станцию");

    ui->lineEdit->setFocus(); // Установка фокуса на первый lineEdit

    loadComboBoxData(); // Загружаем данные в comboBox при инициализации
    loadComboBoxStationsData(); // Загружаем данные в comboBox_2 при инициализации
}

TariffAddWindow::~TariffAddWindow()
{
    delete ui;

    instance = nullptr;
}

void TariffAddWindow::loadComboBoxData() {
    QSqlQuery query;
    query.prepare("SELECT route_id, departure_point, destination, trip_duration FROM routes");

    if (!query.exec()) {
        qDebug() << "SQL Query:" << query.lastQuery();
        qDebug() << "Error:" << query.lastError().text();
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
        return;
    }

    ui->comboBox->clear();

    while (query.next()) {
        int routeId = query.value(0).toInt();
        QString departurePoint = query.value(1).toString();
        QString destination = query.value(2).toString();
        QString tripDuration = query.value(3).toString();

        if (!tripDuration.contains("час")) {
            tripDuration += " часа";
        }

        QString itemText = departurePoint + " -> " + destination + " (" + tripDuration + ")";
        ui->comboBox->addItem(itemText, routeId);
    }
    ui->comboBox->setCurrentIndex(-1); // Устанавливаем пустое значение по умолчанию
}

void TariffAddWindow::loadComboBoxStationsData() {
    QSqlQuery query;
    query.prepare("SELECT station_id, station_name, city FROM stations");

    if (!query.exec()) {
        qDebug() << "SQL Query:" << query.lastQuery();
        qDebug() << "Error:" << query.lastError().text();
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
        return;
    }

    ui->comboBox_2->clear();

    while (query.next()) {
        int stationId = query.value(0).toInt();
        QString stationName = query.value(1).toString();
        QString city = query.value(2).toString();

        QString itemText = stationName + " (" + city + ")";
        ui->comboBox_2->addItem(itemText, stationId);
    }
    ui->comboBox_2->setCurrentIndex(-1); // Устанавливаем пустое значение по умолчанию
}

bool TariffAddWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::Enter || event->type() == QEvent::Leave) {
        QPushButton *button = qobject_cast<QPushButton*>(obj);
        if (button) {
            if (event->type() == QEvent::Enter) {
                if (button == ui->pushButton_2) {
                    updateButtonIcon(button, ":/closeIcon2.png");
                } else if (button == ui->pushButton_3) {
                    updateButtonIcon(button, ":/swapIcon2.png");
                } else if (button == ui->pushButton_9) {
                    updateButtonIcon(button, ":/appendAdminButton2.png");
                }
            } else if (event->type() == QEvent::Leave) {
                // Здесь можно вернуть исходную иконку кнопки
                if (button == ui->pushButton_2) {
                    updateButtonIcon(button, ":/closeIcon.png");
                } else if (button == ui->pushButton_3) {
                    updateButtonIcon(button, ":/swapIcon.png");
                } else if (button == ui->pushButton_9) {
                    updateButtonIcon(button, ":/appendAdminButton_1.png");
                }
            }
        }
        return true;
    }
    return QWidget::eventFilter(obj, event);
}

void TariffAddWindow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
}

void TariffAddWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void TariffAddWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void TariffAddWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

// Определяем слот для закрытия текущего окна
void TariffAddWindow::on_pushButton_2_clicked()
{
    /*
    // Создаем экземпляр окна StationAdminWindow
    StationAdminWIndow *stationAdminWindow = new StationAdminWIndow();
    // Показываем окно StationAdminWindow
    stationAdminWindow->show();
    // Закрываем текущее окно (StationAddWindow)
    this->close();
    */

    TariffAdminWindow *tariffAdminWindow = TariffAdminWindow::getInstance();
    tariffAdminWindow->raise();
    tariffAdminWindow->activateWindow();
    tariffAdminWindow->show();
    this->close();
    instance = nullptr;
}

void TariffAddWindow::on_pushButton_9_clicked()
{
    QString tariffName = ui->lineEdit->text();
    int routeId = ui->comboBox->currentData().toInt();
    int stationId = ui->comboBox_2->currentData().toInt();
    QString tariffDetails = ui->lineEdit_5->text();
    QString price = ui->lineEdit_6->text();

    if (tariffName.isEmpty() || routeId == 0 ||  stationId == 0 || tariffDetails.isEmpty() || price.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены!");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT add_tariff(:p_route_id, :p_station_id, :p_tariff_name, :p_tariff_details, :p_price)");
    query.bindValue(":p_route_id", routeId);
    query.bindValue(":p_station_id", stationId);
    query.bindValue(":p_tariff_name", tariffName);
    query.bindValue(":p_tariff_details", tariffDetails);
    query.bindValue(":p_price", price);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
    } else if (query.next()) {
        QString result = query.value(0).toString();
        if (result == "Тариф с таким маршрутом, станцией и названием уже существует.") {
            QMessageBox::information(this, "Информация", result);
        } else {
            QMessageBox::information(this, "Успех", result);
            emit dataChanged();
            ui->lineEdit->clear();
            ui->comboBox->setCurrentIndex(-1);
            ui->comboBox_2->setCurrentIndex(-1);
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();
            qDebug() << "Adding TariffAdminWindow as" << DatabaseManager::instance().currentUserName();
        }
    }
}

// Определяем слот для сворачивания текущего окна
void TariffAddWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (TariffAddWindow)
    this->showMinimized();
}




