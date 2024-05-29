#include "trainchangewindow.h"
#include "trainadminwindow.h"
#include "ui_trainchangewindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMouseEvent>
#include <QWidget>
#include "DatabaseManager.h" // Включаем заголовочный файл для DatabaseManager

TrainChangeWindow* TrainChangeWindow::instance = nullptr; //

TrainChangeWindow* TrainChangeWindow::getInstance(QWidget *parent) { //
    if (!instance)
        instance = new TrainChangeWindow(parent);
    return instance;
}

TrainChangeWindow::TrainChangeWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainChangeWindow)
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

void TrainChangeWindow::setTrainData(int trainId, const QString &trainNumber) {

    //ui->lineEdit->setText(trainNumber); // Номер поезда уже установлен и только для чтения
    ui->lineEdit->setText("Номер поезда: " + trainNumber); // Номер поезда уже установлен и только для чтения
    ui->lineEdit->setReadOnly(true);
    this->trainId = trainId; // Сохраняем ID для использования в запросе на обновление

    ui->lineEdit_2->setPlaceholderText("Введите новое название поезда");
    ui->lineEdit_3->setPlaceholderText("Введите новый тип поезда");
}

TrainChangeWindow::~TrainChangeWindow()
{
    delete ui;

    instance = nullptr;
}

// Вставьте эту функцию в начало файла trainchangewindow.cpp
TrainAdminWindow* findExistingTrainAdminWindow() {
    foreach (QWidget *widget, QApplication::topLevelWidgets()) {
        TrainAdminWindow *adminWindow = qobject_cast<TrainAdminWindow*>(widget);
        if (adminWindow) {
            return adminWindow;
        }
    }
    return nullptr;
}

bool TrainChangeWindow::eventFilter(QObject *obj, QEvent *event)
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


void TrainChangeWindow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
}

void TrainChangeWindow::on_pushButton_10_clicked() {
    QString newName = ui->lineEdit_2->text();
    QString newType = ui->lineEdit_3->text();

    if (newName.isEmpty() || newType.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены!");
        return;
    }

    // Удаляем надпись "Номер поезда:" перед сохранением
    QString trainNumber = ui->lineEdit->text().remove("Номер поезда: ");

    /*
    // Удаляем надпись "Номер поезда:" перед сохранением
    QString trainNumber = ui->lineEdit->text();
    if (trainNumber.startsWith("Номер поезда: ")) {
        trainNumber = trainNumber.mid(QString("Номер поезда: ").length());
    }
    */

    /*
    // Удаляем надпись "Номер поезда:" перед сохранением //
    QString trainNumber = ui->lineEdit->text().remove("Номер поезда: "); //
    */

    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT update_train(:train_id, :train_number, :new_name, :new_type)");
    query.bindValue(":train_id", trainId);
    // query.bindValue(":train_number", ui->lineEdit->text());
    query.bindValue(":train_number", trainNumber); //
    query.bindValue(":new_name", newName);
    query.bindValue(":new_type", newType);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка базы данных", "Не удалось выполнить запрос: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Успех", "Данные поезда успешно обновлены.");

        //ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();

        emit dataChanged();  // Сигнал, который нужно определить в TrainChangeWindow
        this->close();
    }
}

void TrainChangeWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void TrainChangeWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void TrainChangeWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}

// Вставьте или замените этот код в trainchangewindow.cpp в слоте on_pushButton_2_clicked
void TrainChangeWindow::on_pushButton_2_clicked()
{
    TrainAdminWindow *existingWindow = TrainAdminWindow::getInstance();
    if (existingWindow) {
        existingWindow->show();
        existingWindow->raise();
        existingWindow->activateWindow();
    }
    this->close();

    /*
    TrainAdminWindow *existingWindow = findExistingTrainAdminWindow();
    if (existingWindow) {
        existingWindow->show();
        existingWindow->raise();  // Делает окно активным
        existingWindow->activateWindow();  // Перемещает фокус в это окно
    } else {
        TrainAdminWindow *newWindow = new TrainAdminWindow();
        newWindow->show();
    }
    this->close();  // Закрывает текущее окно изменения
    */
}

// Определяем слот для сворачивания текущего окна
void TrainChangeWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (TrainChangeWindow)
    this->showMinimized();
}

void TrainChangeWindow::closeEvent(QCloseEvent *event) {
    emit closing();
    QWidget::closeEvent(event);
}
