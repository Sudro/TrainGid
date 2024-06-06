#include "trainstationconnectwindow.h"
#include "trainstationadminwindow.h"
#include "ui_trainstationconnectwindow.h"
#include "databasemanager.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMouseEvent>

TrainStationConnectWindow* TrainStationConnectWindow::instance = nullptr; //

TrainStationConnectWindow* TrainStationConnectWindow::getInstance(QWidget *parent) { //
    if (!instance) {
        instance = new TrainStationConnectWindow(parent);
    }
    return instance;
}

TrainStationConnectWindow::TrainStationConnectWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainStationConnectWindow)
{
    ui->setupUi(this);

    // Устанавливаем флаг Qt::FramelessWindowHint
    setWindowFlags(Qt::FramelessWindowHint);

    ui->pushButton_2->installEventFilter(this);
    ui->pushButton_3->installEventFilter(this);
    ui->pushButton_9->installEventFilter(this);

    ui->comboBox->setPlaceholderText("Выберите поезд");
    ui->comboBox_2->setPlaceholderText("Выберите станцию");

    ui->comboBox->setFocus(); // Установка фокуса на первый lineEdit

    loadComboBoxData(); // Загружаем данные в comboBox при инициализации
    loadComboBoxStationsData(); // Загружаем данные в comboBox_2 при инициализации
}

TrainStationConnectWindow::~TrainStationConnectWindow()
{
    delete ui;

    instance = nullptr;
}

void TrainStationConnectWindow::loadComboBoxData() {
    QSqlQuery query;
    query.prepare("SELECT train_id, train_number, train_name FROM trains");

    if (!query.exec()) {
        qDebug() << "SQL Query:" << query.lastQuery();
        qDebug() << "Error:" << query.lastError().text();
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
        return;
    }

    ui->comboBox->clear();

    while (query.next()) {
        int trainId = query.value(0).toInt();
        QString trainNumber = query.value(1).toString();
        QString trainName = query.value(2).toString();

        QString itemText = trainNumber + " (" + trainName + ")";
        ui->comboBox->addItem(itemText, trainId);
    }
    ui->comboBox->setCurrentIndex(-1); // Устанавливаем пустое значение по умолчанию
}

void TrainStationConnectWindow::loadComboBoxStationsData() {
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

bool TrainStationConnectWindow::eventFilter(QObject *obj, QEvent *event)
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
                    updateButtonIcon(button, ":/connectTrainStationButton2.png");
                }
            } else if (event->type() == QEvent::Leave) {
                // Здесь можно вернуть исходную иконку кнопки
                if (button == ui->pushButton_2) {
                    updateButtonIcon(button, ":/closeIcon.png");
                } else if (button == ui->pushButton_3) {
                    updateButtonIcon(button, ":/swapIcon.png");
                } else if (button == ui->pushButton_9) {
                    updateButtonIcon(button, ":/connectTrainStationButton.png");
                }
            }
        }
        return true;
    }
    return QWidget::eventFilter(obj, event);
}

void TrainStationConnectWindow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
}

void TrainStationConnectWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void TrainStationConnectWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void TrainStationConnectWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

// Определяем слот для закрытия текущего окна
void TrainStationConnectWindow::on_pushButton_2_clicked()
{
    TrainStationAdminWindow *trainStationAdminWindow = TrainStationAdminWindow::getInstance();
    trainStationAdminWindow->raise();
    trainStationAdminWindow->activateWindow();
    trainStationAdminWindow->show();
    this->close();
    instance = nullptr;
}

void TrainStationConnectWindow::on_pushButton_9_clicked()
{
    int trainId = ui->comboBox->currentData().toInt();
    int stationId = ui->comboBox_2->currentData().toInt();

    if (trainId == 0 || stationId == 0) {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены!");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT add_trainstation(:p_train_id, :p_station_id)");
    query.bindValue(":p_train_id", trainId);
    query.bindValue(":p_station_id", stationId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
    } else if (query.next()) {
        QString result = query.value(0).toString();
        if (result == "Связь с таким поездом и станцией уже существует.") {
            QMessageBox::information(this, "Информация", result);
        } else {
            QMessageBox::information(this, "Успех", result);
            emit dataChanged();
            ui->comboBox->setCurrentIndex(-1);
            ui->comboBox_2->setCurrentIndex(-1);

            qDebug() << "Adding TrainStationAdminWindow as" << DatabaseManager::instance().currentUserName();
        }
    }
}

// Определяем слот для сворачивания текущего окна
void TrainStationConnectWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (TrainStationConnectWindow)
    this->showMinimized();
}

void TrainStationConnectWindow::on_comboBox_activated(int index)
{

}

