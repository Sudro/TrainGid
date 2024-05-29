#include "routechangewindow.h"
#include "routeadminwindow.h"
#include "ui_routechangewindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMouseEvent>
#include <QWidget>
#include "DatabaseManager.h" // Включаем заголовочный файл для DatabaseManager

RouteChangeWindow* RouteChangeWindow::instance = nullptr; //

RouteChangeWindow* RouteChangeWindow::getInstance(QWidget *parent) { //
    if (!instance)
        instance = new RouteChangeWindow(parent);
    return instance;
}

RouteChangeWindow::RouteChangeWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RouteChangeWindow)
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

RouteChangeWindow::~RouteChangeWindow()
{
    delete ui;

    instance = nullptr; //
}

// СДЕЛАТЬ ЧТОБЫ БЫЛО МОСКВА -> КРАСНОДАР (2 часа)// СДЕЛАТЬ ЧТОБЫ БЫЛО МОСКВА -> КРАСНОДАР (2 часа)// СДЕЛАТЬ ЧТОБЫ БЫЛО МОСКВА -> КРАСНОДАР (2 часа)// СДЕЛАТЬ ЧТОБЫ БЫЛО МОСКВА -> КРАСНОДАР (2 часа)
void RouteChangeWindow::setRouteData(int routeId, const QString &routeDescription, const QString &departurePoint, const QString &destination, const QString &tripDuration) {
    qDebug() << "RouteChangeWindow::setRouteData - routeId:" << routeId;

    ui->lineEdit->setText(routeDescription); // СДЕЛАТЬ ЧТОБЫ БЫЛО МОСКВА -> КРАСНОДАР (2 часа)// СДЕЛАТЬ ЧТОБЫ БЫЛО МОСКВА -> КРАСНОДАР (2 часа)// СДЕЛАТЬ ЧТОБЫ БЫЛО МОСКВА -> КРАСНОДАР (2 часа)
    //ui->lineEdit->setText("Маршрут: " + routeDescription); // Маршрут уже установлен и только для чтения
    ui->lineEdit->setReadOnly(true);
    this->routeId = routeId; // Сохраняем ID для использования в запросе на обновление

    ui->lineEdit_2->setPlaceholderText("Введите новый город отправления");
    ui->lineEdit_3->setPlaceholderText("Введите новый город прибытия");
    ui->lineEdit_4->setPlaceholderText("Введите новую продолжительность поездки");

    // Добавляем qDebug для отладки
    qDebug() << "RouteChangeWindow::setRouteData - routeId:" << routeId
             << "routeDescription:" << routeDescription
             << "departurePoint:" << departurePoint
             << "destination:" << destination
             << "tripDuration:" << tripDuration;
}
// СДЕЛАТЬ ЧТОБЫ БЫЛО МОСКВА -> КРАСНОДАР (2 часа)// СДЕЛАТЬ ЧТОБЫ БЫЛО МОСКВА -> КРАСНОДАР (2 часа)// СДЕЛАТЬ ЧТОБЫ БЫЛО МОСКВА -> КРАСНОДАР (2 часа)// СДЕЛАТЬ ЧТОБЫ БЫЛО МОСКВА -> КРАСНОДАР (2 часа)


// НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?
/*
StationAdminWIndow* findExistingStationAdminWindow() {
    foreach (QWidget *widget, QApplication::topLevelWidgets()) {
        StationAdminWIndow *adminWindow = qobject_cast<StationAdminWIndow*>(widget);
        if (adminWindow) {
            return adminWindow;
        }
    }
    return nullptr;
}*/

// НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?НАДО ИЛИ НЕТ?

bool RouteChangeWindow::eventFilter(QObject *obj, QEvent *event)
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

void RouteChangeWindow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
}

void RouteChangeWindow::on_pushButton_10_clicked() {
    QString newDeparturePoint = ui->lineEdit_2->text();
    QString newDestination = ui->lineEdit_3->text();
    QString newTripDuration = ui->lineEdit_4->text();

    if (!newTripDuration.contains("час")) {
        newTripDuration += " часа";
    }

    if (newDeparturePoint.isEmpty() || newDestination.isEmpty() || newTripDuration.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены!");
        return;
    }

    /*
    // Удаляем надпись "Маршрут:" перед сохранением
    QString routeDescription = ui->lineEdit->text();
    if (routeDescription.startsWith("Маршрут: ")) {
        routeDescription = routeDescription.mid(QString("Маршрут: ").length());
    }
    */

    qDebug() << "RouteChangeWindow::on_pushButton_10_clicked - routeId:" << routeId
             << "newDeparturePoint:" << newDeparturePoint
             << "newDestination:" << newDestination
             << "newTripDuration:" << newTripDuration;

    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT update_route(:route_id, :new_departure_point, :new_destination, :new_trip_duration)");
    query.bindValue(":route_id", routeId);
    query.bindValue(":new_departure_point", newDeparturePoint);
    query.bindValue(":new_destination", newDestination);
    query.bindValue(":new_trip_duration", newTripDuration);

    qDebug() << "Executing query:" << query.executedQuery();

    if (!query.exec()) {
        qDebug() << "Database error:" << query.lastError().text();
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
    } else if (query.next()) {
        QString result = query.value(0).toString();
        qDebug() << "Query result:" << result;
        if (result == "Маршрут с такой точкой отправления, точкой прибытия и временем уже существует.") {
            QMessageBox::information(this, "Информация", result);
        } else {
            QMessageBox::information(this, "Успех", result);
            // Закрываем окно или очищаем поля для ввода
            // this->close(); // или
            //emit dataChanged();
            //ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();

            emit dataChanged();  // Сигнал, который нужно определить в StationChangeWindow
            this->close();
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

void RouteChangeWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void RouteChangeWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void RouteChangeWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

// Вставьте или замените этот код в trainchangewindow.cpp в слоте on_pushButton_2_clicked
void RouteChangeWindow::on_pushButton_2_clicked()
{
    RouteAdminWindow *existingWindow = RouteAdminWindow::getInstance();
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
void RouteChangeWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (RouteChangeWindow)
    this->showMinimized();
}

void RouteChangeWindow::closeEvent(QCloseEvent *event) {
    emit closing();
    QWidget::closeEvent(event);
}
