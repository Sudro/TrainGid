#include "tariffchangewindow.h"
#include "tariffadminwindow.h"
#include "ui_tariffchangewindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMouseEvent>
#include <QWidget>
#include "DatabaseManager.h" // Включаем заголовочный файл для DatabaseManager
#include <QRegularExpressionValidator>

TariffChangeWindow* TariffChangeWindow::instance = nullptr; //

TariffChangeWindow* TariffChangeWindow::getInstance(QWidget *parent) { //
    if (!instance)
        instance = new TariffChangeWindow(parent);
    return instance;
}

TariffChangeWindow::TariffChangeWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffChangeWindow)
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

void TariffChangeWindow::setTariffData(int tariffId, const QString &tariffName, const QString &route, const QString &station, const QString &details, const QString &price) {
    this->tariffId = tariffId;

    //ui->lineEdit->setText(tariffName);
    ui->lineEdit->setText("Тариф: " + tariffName);
    ui->lineEdit->setReadOnly(true);

    //ui->lineEdit_2->setText(route);
    ui->lineEdit_2->setText("Маршрут: " + route);
    ui->lineEdit_2->setReadOnly(true);

    //ui->lineEdit_3->setText(station);
    ui->lineEdit_3->setText("Станция: " + station);
    ui->lineEdit_3->setReadOnly(true);

    //ui->lineEdit_4->setText(details); // ???????????????????????????????????????????????????????????????????????????????????
    ui->lineEdit_4->setPlaceholderText("Введите новое описание тарифа");

    //ui->lineEdit_5->setText(price); // ???????????????????????????????????????????????????????????????????????????????????
    ui->lineEdit_5->setPlaceholderText("Введите новую цену тарифа");

    // Подключаем сигнал изменения текста к слоту проверки ввода
    connect(ui->lineEdit_4, &QLineEdit::textChanged, this, &TariffChangeWindow::validateInput);
    connect(ui->lineEdit_5, &QLineEdit::textChanged, this, &TariffChangeWindow::validateInput);
}

TariffChangeWindow::~TariffChangeWindow()
{
    delete ui;

    instance = nullptr; //
}

// Вставьте эту функцию в начало файла // ?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
TariffAdminWindow* findExistingStationAdminWindow2() { // ?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
    foreach (QWidget *widget, QApplication::topLevelWidgets()) {
        TariffAdminWindow *adminWindow = qobject_cast<TariffAdminWindow*>(widget);
        if (adminWindow) {
            return adminWindow;
        }
    }
    return nullptr;
} // ?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????

bool TariffChangeWindow::eventFilter(QObject *obj, QEvent *event)
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

void TariffChangeWindow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
}

void TariffChangeWindow::on_pushButton_10_clicked() {
    QString newDetails = ui->lineEdit_4->text();
    QString newPrice = ui->lineEdit_5->text();

    QString cleanedDetails = newDetails; // .remove(" "); // Удаляем все пробелы для проверки
    cleanedDetails.remove(" ");

    if (newDetails.isEmpty() || newPrice.isEmpty() || cleanedDetails.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены!");
        return;
    }

    // Проверяем, что поля прошли валидацию
    bool valid = true;
    QString errorMessage;

    /*
    if (!newDetails.contains(QRegularExpression("^[A-Za-zА-Яа-я0-9 ]+$"))) { // "^[A-Za-zА-Яа-я0-9]+$"
        valid = false;
        errorMessage += "Описание тарифа может содержать только буквы и цифры!\n";
        ui->lineEdit_4->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_4->setStyleSheet("border: 3px solid #F0B78E; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }*/

    // !ui->lineEdit_3->text().contains(QRegularExpression("^[A-Za-zА-Яа-я0-9 ,]+$")) && !ui->lineEdit_3->text().isEmpty()
    if (!newDetails.contains(QRegularExpression("^[A-Za-zА-Яа-я0-9 ,]+$")) ) {//&& ui->lineEdit_3->hasFocus()) { // || cleanedAddress.replace(" ", "").isEmpty() && ui->lineEdit_3->hasFocus()) {
        valid = false;
        errorMessage += "Описание тарифа может содержать только буквы и цифры!\n";
        ui->lineEdit_4->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else if (newDetails.isEmpty() && ui->lineEdit_4->hasFocus()) {
        ui->lineEdit_4->setStyleSheet("border: 3px solid #F0B78E; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } /*else if  (ui->lineEdit_3->hasFocus()) {
        ui->lineEdit_3->setStyleSheet("border: 3px solid #F0B78E; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }*/

    /*
    if (!newPrice.contains(QRegularExpression("^\\d+$"))) {
        valid = false;
        errorMessage += "Цена тарифа может содержать только цифры!\n";
        ui->lineEdit_5->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_5->setStyleSheet("border: 3px solid #F0B78E; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }*/

    // Проверка на ввод "0" в цене тарифа
    if (newPrice == "0") {
        newPrice = "Бесплатно";
        ui->lineEdit_5->setStyleSheet("border: 3px solid #F0B78E; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else if (newPrice.contains(QRegularExpression("^\\d+$"))) {
        newPrice += " рублей";
        ui->lineEdit_5->setStyleSheet("border: 3px solid #F0B78E; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        valid = false;
        errorMessage += "Цена тарифа может содержать только цифры!\n";
        ui->lineEdit_5->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }

    if (!valid) {
        QMessageBox::warning(this, "Ошибка", errorMessage.trimmed());
        return;
    }

    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT update_tariff(:p_tariff_id, :p_tariff_details, :p_price)");
    query.bindValue(":p_tariff_id", tariffId);
    query.bindValue(":p_tariff_details", newDetails);
    query.bindValue(":p_price", newPrice);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
    } else if (query.next()) {
        QString result = query.value(0).toString();
        if (result == "Тариф с такими параметрами уже существует.") {
            QMessageBox::information(this, "Информация", result);
        } else {
            QMessageBox::information(this, "Успех", result);

            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
            emit dataChanged();
            this->close();

            qDebug() << "Changing TariffAdminWindow as" << DatabaseManager::instance().currentUserName();
        }
    }
}

void TariffChangeWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void TariffChangeWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void TariffChangeWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

void TariffChangeWindow::on_pushButton_2_clicked()
{
    TariffAdminWindow *existingWindow = TariffAdminWindow::getInstance();
    if (existingWindow) {
        existingWindow->show();
        existingWindow->raise();
        existingWindow->activateWindow();
    }
    this->close();
}

void TariffChangeWindow::validateInput()
{
    QString newDetails = ui->lineEdit_4->text();
    QString newPrice = ui->lineEdit_5->text();

    if (!newDetails.contains(QRegularExpression("^[A-Za-zА-Яа-я0-9 ,]+$")) && ui->lineEdit_4->hasFocus() ) { //&& ui->lineEdit_3->hasFocus()) {// || cleanedAddress.replace(" ", "").isEmpty() && ui->lineEdit_3->hasFocus()) {
        ui->lineEdit_4->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else if (newDetails.isEmpty() && ui->lineEdit_4->hasFocus()) {
        ui->lineEdit_4->setStyleSheet("border: 3px solid #F0B78E; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else if  (ui->lineEdit_4->hasFocus()) {
        ui->lineEdit_4->setStyleSheet("border: 3px solid #F0B78E; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_4->setStyleSheet("border: 3px solid #F0B78E; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }

    /*
    // Проверка ввода и установка соответствующего стиля
    if (!newDetails.contains(QRegularExpression("^[A-Za-zА-Яа-я0-9 ]+$")) && !ui->lineEdit_4->text().isEmpty()) {
        ui->lineEdit_4->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_4->setStyleSheet("border: 3px solid #F0B78E; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }*/

    if (!newPrice.contains(QRegularExpression("^\\d+$")) && !ui->lineEdit_5->text().isEmpty()) {
        ui->lineEdit_5->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_5->setStyleSheet("border: 3px solid #F0B78E; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }
}

// Определяем слот для сворачивания текущего окна
void TariffChangeWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (TariffChangeWindow)
    this->showMinimized();
}

void TariffChangeWindow::closeEvent(QCloseEvent *event) {
    emit closing();
    QWidget::closeEvent(event);
}
