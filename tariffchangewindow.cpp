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

    if (newDetails.isEmpty() || newPrice.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены!");
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
