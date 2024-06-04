#include "stationchangewindow.h"
#include "stationadminwindow.h"
#include "ui_stationchangewindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMouseEvent>
#include <QWidget>
#include "DatabaseManager.h" // Включаем заголовочный файл для DatabaseManager

StationChangeWindow* StationChangeWindow::instance = nullptr; //

StationChangeWindow* StationChangeWindow::getInstance(QWidget *parent) { //
    if (!instance)
        instance = new StationChangeWindow(parent);
    return instance;
}

StationChangeWindow::StationChangeWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StationChangeWindow)
{
    ui->setupUi(this);

    // Устанавливаем флаг Qt::FramelessWindowHint
    setWindowFlags(Qt::FramelessWindowHint);

    ui->lineEdit->setReadOnly(true); // Сделать поле номера поезда только для чтения

    // Устанавливаем фильтр событий для кнопок
    ui->pushButton_2->installEventFilter(this);
    ui->pushButton_3->installEventFilter(this);
    ui->pushButton_10->installEventFilter(this);
}

void StationChangeWindow::setStationData(int stationId, const QString &stationName) {
    // ui->lineEdit->setText(stationName); // Название станции уже установлена и только для чтения
    ui->lineEdit->setText("Станция: " + stationName); // Название станции уже установлена и только для чтения
    ui->lineEdit->setReadOnly(true);
    this->stationId = stationId; // Сохраняем ID для использования в запросе на обновление

    ui->lineEdit_2->setPlaceholderText("Введите новый город станции");
    ui->lineEdit_3->setPlaceholderText("Введите новый адрес станции");
    ui->lineEdit_4->setPlaceholderText("Введите новое количество платформ");
}

StationChangeWindow::~StationChangeWindow()
{
    delete ui;

    instance = nullptr; //
}

// Вставьте эту функцию в начало файла trainchangewindow.cpp
StationAdminWIndow* findExistingStationAdminWindow() {
    foreach (QWidget *widget, QApplication::topLevelWidgets()) {
        StationAdminWIndow *adminWindow = qobject_cast<StationAdminWIndow*>(widget);
        if (adminWindow) {
            return adminWindow;
        }
    }
    return nullptr;
}

bool StationChangeWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::Enter || event->type() == QEvent::Leave) {
        QPushButton *button = qobject_cast<QPushButton*>(obj);
        if (button) {
            if (event->type() == QEvent::Enter) {
                if (button == ui->pushButton_2) {
                    updateButtonIcon(button, ":/closeIcon2.png");
                } else if (button == ui->pushButton_3) {
                    updateButtonIcon(button, ":/swapIcon2.png");
                } else if (button == ui->pushButton_10) {
                    updateButtonIcon(button, ":/changeAdminButton2.png");
                }
            } else if (event->type() == QEvent::Leave) {
                // Здесь можно вернуть исходную иконку кнопки
                if (button == ui->pushButton_2) {
                    updateButtonIcon(button, ":/closeIcon.png");
                } else if (button == ui->pushButton_3) {
                    updateButtonIcon(button, ":/swapIcon.png");
                } else if (button == ui->pushButton_10) {
                    updateButtonIcon(button, ":/changeAdminButton.png");
                }
            }
        }
        return true;
    }
    return QWidget::eventFilter(obj, event);
}


void StationChangeWindow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
}

void StationChangeWindow::on_pushButton_10_clicked() {
    QString newCity = ui->lineEdit_2->text();
    QString newStationAddress = ui->lineEdit_3->text();
    QString newPlatformsCount = ui->lineEdit_4->text();

    if (newCity.isEmpty() || newStationAddress.isEmpty() || newPlatformsCount.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены!");
        return;
    }

    // Удаляем надпись ""Станция: " перед сохранением
    QString stationName = ui->lineEdit->text().remove("Станция: ");

    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT update_station(:station_id, :station_name, :new_city, :new_station_address, :new_platforms_count)");
    query.bindValue(":station_id", stationId);
    // query.bindValue(":station_name", ui->lineEdit->text());
    query.bindValue(":station_name", stationName); //
    query.bindValue(":new_city", newCity);
    query.bindValue(":new_station_address", newStationAddress);
    query.bindValue(":new_platforms_count", newPlatformsCount);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
    } else if (query.next()) {
        QString result = query.value(0).toString();
        if (result == "Станция с таким именем и городом уже существует.") {
            QMessageBox::information(this, "Информация", result);
        } else {
            QMessageBox::information(this, "Успех", result);
            // Закрываем окно или очищаем поля для ввода
            // this->close(); // или

            //ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();

            emit dataChanged();  // Сигнал, который нужно определить в StationChangeWindow
            this->close();
            qDebug() << "Changing StationAdminWIndow as" << DatabaseManager::instance().currentUserName();
        }
    }

    /*
    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Успех", "Данные поезда успешно обновлены.");
        emit dataChanged();  // Сигнал, который нужно определить в StationChangeWindow
        this->close();
    }*/
}

void StationChangeWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void StationChangeWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void StationChangeWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

// Вставьте или замените этот код в trainchangewindow.cpp в слоте on_pushButton_2_clicked
void StationChangeWindow::on_pushButton_2_clicked()
{
    StationAdminWIndow *existingWindow = StationAdminWIndow::getInstance();
    if (existingWindow) {
        existingWindow->show();
        existingWindow->raise();
        existingWindow->activateWindow();
    }
    this->close();

    /*
    StationAdminWIndow *existingWindow = findExistingStationAdminWindow();
    if (existingWindow) {
        existingWindow->show();
        existingWindow->raise();  // Делает окно активным
        existingWindow->activateWindow();  // Перемещает фокус в это окно
    } else {
        StationAdminWIndow *newWindow = new StationAdminWIndow();
        newWindow->show();
    }
    this->close();  // Закрывает текущее окно изменения
    */
}

// Определяем слот для сворачивания текущего окна
void StationChangeWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (StationChangeWindow)
    this->showMinimized();
}

void StationChangeWindow::closeEvent(QCloseEvent *event) {
    emit closing();
    QWidget::closeEvent(event);
}
