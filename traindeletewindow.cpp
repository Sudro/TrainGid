#include "traindeletewindow.h"
#include "ui_traindeletewindow.h"
#include "DatabaseManager.h"
#include <QMessageBox>
#include <QSqlQuery>

TrainDeleteWindow::TrainDeleteWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrainDeleteWindow)
{
    ui->setupUi(this);

    ui->lineEdit_2->setPlaceholderText("Введите номер поезда");

    connect(ui->pushButton_11, &QPushButton::clicked, this, &TrainDeleteWindow::on_pushButton_11_clicked);
}

TrainDeleteWindow::~TrainDeleteWindow()
{
    delete ui;
}

void TrainDeleteWindow::on_pushButton_11_clicked()
{
    QString trainNumber = ui->lineEdit_2->text();
    if (trainNumber.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите номер поезда.");
        return;
    }

    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT delete_train(:train_number)");
    query.bindValue(":train_number", trainNumber);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось выполнить запрос: " + query.lastError().text());
    } else {
        if (query.next() && query.value(0).toBool()) {
            QMessageBox::information(this, "Успех", "Поезд успешно удален.");
            ui->lineEdit_2->clear();
        } else {
            QMessageBox::warning(this, "Ошибка", "Поезд с таким номером не найден.");
        }
    }
}

