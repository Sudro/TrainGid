#include "trainaddwindow.h"
#include "trainadminwindow.h"
#include "ui_trainaddwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

TrainAddWindow::TrainAddWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainAddWindow)
{
    ui->setupUi(this);

    ui->lineEdit->setPlaceholderText("Введите номер поезда");
    ui->lineEdit_2->setPlaceholderText("Введите название поезда");
    ui->lineEdit_3->setPlaceholderText("Введите тип поезда");
}

TrainAddWindow::~TrainAddWindow()
{
    delete ui;
}

// Определяем слот для закрытия текущего окна
void TrainAddWindow::on_pushButton_2_clicked()
{
    // Создаем экземпляр окна TrainAdminWindow
    TrainAdminWindow *trainAdminWindow = new TrainAdminWindow();
    // Показываем окно TrainAdminWindow
    trainAdminWindow->show();
    // Закрываем текущее окно (TrainAddWindow)
    this->close();
}

void TrainAddWindow::on_pushButton_9_clicked()
{
    QString trainNumber = ui->lineEdit->text();
    QString trainName = ui->lineEdit_2->text();
    QString trainType = ui->lineEdit_3->text();

    // Проверяем, что все поля заполнены
    if (trainNumber.isEmpty() || trainName.isEmpty() || trainType.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены!");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT add_train(:p_train_number, :p_train_name, :p_train_type)");
    query.bindValue(":p_train_number", trainNumber);
    query.bindValue(":p_train_name", trainName);
    query.bindValue(":p_train_type", trainType);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
    } else if (query.next()) {
        QString result = query.value(0).toString();
        if (result == "Поезд с таким номером уже существует.") {
            QMessageBox::information(this, "Информация", result);
        } else {
            QMessageBox::information(this, "Успех", result);
            // Закрываем окно или очищаем поля для ввода
            // this->close(); // или
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
        }
    }
}
