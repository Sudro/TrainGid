#include "routeaddwindow.h"
#include "routeadminwindow.h"
#include "ui_routeaddwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMouseEvent>

RouteAddWindow* RouteAddWindow::instance = nullptr; //

RouteAddWindow* RouteAddWindow::getInstance(QWidget *parent) { //
    if (!instance) {
        instance = new RouteAddWindow(parent);
    }
    return instance;
}

RouteAddWindow::RouteAddWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RouteAddWindow)
{
    ui->setupUi(this);

    // Устанавливаем флаг Qt::FramelessWindowHint
    setWindowFlags(Qt::FramelessWindowHint);

    ui->pushButton_2->installEventFilter(this);
    ui->pushButton_3->installEventFilter(this);
    ui->pushButton_9->installEventFilter(this);

    ui->lineEdit->setPlaceholderText("Введите город отправления");
    ui->lineEdit_2->setPlaceholderText("Введите город прибытия");
    ui->lineEdit_3->setPlaceholderText("Продолжительность поездки");
    ui->comboBox->setPlaceholderText("Выберите маршрут родителя");

    ui->lineEdit->setFocus(); // Установка фокуса на первый lineEdit

    loadComboBoxData(); // Загружаем данные в comboBox при инициализации
}

RouteAddWindow::~RouteAddWindow()
{
    delete ui;

    instance = nullptr;
}

void RouteAddWindow::loadComboBoxData() {
    QSqlQuery query;
    query.prepare("SELECT route_id, departure_point, destination, trip_duration FROM routes");

    if (!query.exec()) {
        qDebug() << "SQL Query:" << query.lastQuery();
        qDebug() << "Error:" << query.lastError().text();
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
        return;
    }

    /*
    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось загрузить данные для маршрутов: " + query.lastError().text());
        return;
    }
    */

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


    /*
    QSqlQuery query("SELECT departure_point, destination, trip_duration FROM routes");
    while (query.next()) {
        QString departurePoint = query.value(0).toString();
        QString destination = query.value(1).toString();
        QString tripDuration = query.value(2).toString();

        if (!tripDuration.contains("час")) {
            tripDuration += " часа";
        }

        QString itemText = departurePoint + " -> " + destination + " (" + tripDuration + ")";
        ui->comboBox->addItem(itemText, query.value(0));
    }
    ui->comboBox->setCurrentIndex(-1); // Устанавливаем пустое значение по умолчанию
    */
}

bool RouteAddWindow::eventFilter(QObject *obj, QEvent *event)
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

void RouteAddWindow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
}

void RouteAddWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void RouteAddWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void RouteAddWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

// Определяем слот для закрытия текущего окна
void RouteAddWindow::on_pushButton_2_clicked()
{
    /*
    // Создаем экземпляр окна StationAdminWindow
    StationAdminWIndow *stationAdminWindow = new StationAdminWIndow();
    // Показываем окно StationAdminWindow
    stationAdminWindow->show();
    // Закрываем текущее окно (StationAddWindow)
    this->close();
    */

    RouteAdminWindow *routeAdminWindow = RouteAdminWindow::getInstance();
    routeAdminWindow->raise();
    routeAdminWindow->activateWindow();
    routeAdminWindow->show();
    this->close();
    instance = nullptr;
}

void RouteAddWindow::on_pushButton_9_clicked()
{

    QString departurePoint = ui->lineEdit->text();
    QString destination = ui->lineEdit_2->text();
    QString trip_duration = ui->lineEdit_3->text();
    //QString parent_route_id = ui->comboBox->currentText();

    if (!trip_duration.contains("час")) {
        trip_duration += " часа";
    }

    QVariant parentRouteId = ui->comboBox->currentData();

    if (departurePoint.isEmpty() || destination.isEmpty() || trip_duration.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Верхние три поля должны быть заполнены!");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT add_route(:p_departure_point, :p_destination, :p_trip_duration, :p_parent_route_id)");
    query.bindValue(":p_departure_point", departurePoint);
    query.bindValue(":p_destination", destination);
    query.bindValue(":p_trip_duration", trip_duration);

    if (parentRouteId.isNull()) { //
        query.bindValue(":p_parent_route_id", QVariant(QVariant::Int)); //
        qDebug() << "Parent Route ID is NULL";
    } else { //
        query.bindValue(":p_parent_route_id", parentRouteId.toInt()); //
        qDebug() << "Parent Route ID:" << parentRouteId.toInt();
    }

    qDebug() << "Executing SQL Query:" << query.executedQuery();
    qDebug() << "Bound Values:" << query.boundValues();

    /*
    if (!query.exec()) {
        qDebug() << "SQL Query:" << query.lastQuery();
        qDebug() << "Error:" << query.lastError().text();
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
    }
    */

    if (!query.exec()) {
        qDebug() << "SQL Query Error (on_pushButton_9_clicked):" << query.lastQuery();
        qDebug() << "Error:" << query.lastError().text();
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
    } else if (query.next()) {
        QString result = query.value(0).toString();
        if (result == "Маршрут с такой точкой отправления, точкой прибытия и временем уже существует.") {
            QMessageBox::information(this, "Информация", result);
        } else {
            QMessageBox::information(this, "Успех", result);
            emit dataChanged();
            // Закрываем окно или очищаем поля для ввода
            // this->close(); // или
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->comboBox->setCurrentIndex(-1); // очистка выбора
        }
    }



    /*
    QString departurePoint = ui->lineEdit->text();
    QString destination = ui->lineEdit_2->text();
    QString trip_duration = ui->lineEdit_3->text();
    //QString parent_route_id = ui->comboBox->currentText();

    if (!trip_duration.contains("час")) {
        trip_duration += " часа";
    }

    QVariant parent_route_id; //
    if (ui->comboBox->currentIndex() == -1) { //
        parent_route_id = QVariant(QVariant::Int); //
    } else { //
        parent_route_id = ui->comboBox->currentData(); //
    }

    // Проверяем, что все поля заполнены
    if (departurePoint.isEmpty() || destination.isEmpty() || trip_duration.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Верхние три поля должны быть заполнены!");
        return;
    }
    */


    //if (ui->comboBox->currentIndex() == -1) { // значит ничего не выбрано
    //    parent_route_id = NULL; // ???????? КАК ПРОВЕРИТЬ НА ТО ЧТО ОН НИЧЕГО НЕ ВЗЯЛ (ЧТОБЫ ПОСТАВИТЬ NULL)
    //}


    /*
    QSqlQuery query;
    query.prepare("SELECT add_route(:p_departure_point, :p_destination, :p_trip_duration, :p_parent_route_id)");
    query.bindValue(":p_departure_point", departurePoint);
    query.bindValue(":p_destination", destination);
    query.bindValue(":p_trip_duration", trip_duration);

    // query.bindValue(":p_parent_route_id", parent_route_id); //
    //if (parentRouteId.isNull()) { //
    //    query.bindValue(":p_parent_route_id", QVariant(QVariant::Int)); //
    //} else { //
    //    query.bindValue(":p_parent_route_id", parentRouteId.toInt()); //
    //} //

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
    } else if (query.next()) {
        QString result = query.value(0).toString();
        if (result == "Маршрут с такой точкой отправления, точкой прибытия и временем уже существует.") {
            QMessageBox::information(this, "Информация", result);
        } else {
            QMessageBox::information(this, "Успех", result);
            emit dataChanged();
            // Закрываем окно или очищаем поля для ввода
            // this->close(); // или
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->comboBox->setCurrentIndex(-1); // очистка выбора
        }
    }
    */

}

// Определяем слот для сворачивания текущего окна
void RouteAddWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (RouteAddWindow)
    this->showMinimized();
}
