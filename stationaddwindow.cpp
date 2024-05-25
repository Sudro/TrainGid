#include "stationaddwindow.h"
#include "stationadminwindow.h"
#include "ui_stationaddwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMouseEvent>

StationAddWindow* StationAddWindow::instance = nullptr; //

StationAddWindow* StationAddWindow::getInstance(QWidget *parent) { //
    if (!instance) {
        instance = new StationAddWindow(parent);
    }
    return instance;
}

StationAddWindow::StationAddWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StationAddWindow)
{
    ui->setupUi(this);

    // Устанавливаем флаг Qt::FramelessWindowHint
    setWindowFlags(Qt::FramelessWindowHint);

    ui->pushButton_2->installEventFilter(this);
    ui->pushButton_3->installEventFilter(this);
    ui->pushButton_9->installEventFilter(this);

    ui->lineEdit->setPlaceholderText("Введите название станции");
    ui->lineEdit_2->setPlaceholderText("Введите город станции");
    ui->lineEdit_3->setPlaceholderText("Введите адрес станции");
    ui->lineEdit_4->setPlaceholderText("Введите количество платформ");

    ui->lineEdit->setFocus(); // Установка фокуса на первый lineEdit
}

StationAddWindow::~StationAddWindow()
{
    delete ui;

    instance = nullptr;
}

bool StationAddWindow::eventFilter(QObject *obj, QEvent *event)
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


void StationAddWindow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
}

void StationAddWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void StationAddWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void StationAddWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

// Определяем слот для закрытия текущего окна
void StationAddWindow::on_pushButton_2_clicked()
{
    /*
    // Создаем экземпляр окна StationAdminWindow
    StationAdminWIndow *stationAdminWindow = new StationAdminWIndow();
    // Показываем окно StationAdminWindow
    stationAdminWindow->show();
    // Закрываем текущее окно (StationAddWindow)
    this->close();
    */

    StationAdminWIndow *stationAdminWindow = StationAdminWIndow::getInstance();
    stationAdminWindow->raise();
    stationAdminWindow->activateWindow();
    stationAdminWindow->show();
    this->close();
    instance = nullptr;
}

void StationAddWindow::on_pushButton_9_clicked()
{
    QString stationName = ui->lineEdit->text();
    QString cityStation = ui->lineEdit_2->text();
    QString addressType = ui->lineEdit_3->text();
    QString countPlatforms = ui->lineEdit_4->text();

    // Проверяем, что все поля заполнены
    if (stationName.isEmpty() || cityStation.isEmpty() || addressType.isEmpty() || countPlatforms.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены!");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT add_station(:p_station_name, :p_city, :p_station_address, :p_platforms_count)");
    query.bindValue(":p_station_name", stationName);
    query.bindValue(":p_city", cityStation);
    query.bindValue(":p_station_address", addressType);
    query.bindValue(":p_platforms_count", countPlatforms);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
    } else if (query.next()) {
        QString result = query.value(0).toString();
        if (result == "Станция с таким именем и городом уже существует.") {
            QMessageBox::information(this, "Информация", result);
        } else {
            QMessageBox::information(this, "Успех", result);
            emit dataChanged();
            // Закрываем окно или очищаем поля для ввода
            // this->close(); // или
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
        }
    }
}

// Определяем слот для сворачивания текущего окна
void StationAddWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (StationAddWindow)
    this->showMinimized();
}


