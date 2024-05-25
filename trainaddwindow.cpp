#include "trainaddwindow.h"
#include "trainadminwindow.h"
#include "ui_trainaddwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMouseEvent>

TrainAddWindow::TrainAddWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainAddWindow)
{
    ui->setupUi(this);

    // Устанавливаем флаг Qt::FramelessWindowHint
    setWindowFlags(Qt::FramelessWindowHint);

    ui->pushButton_2->installEventFilter(this);
    ui->pushButton_3->installEventFilter(this);
    ui->pushButton_9->installEventFilter(this);

    ui->lineEdit->setPlaceholderText("Введите номер поезда");
    ui->lineEdit_2->setPlaceholderText("Введите название поезда");
    ui->lineEdit_3->setPlaceholderText("Введите тип поезда");

    ui->lineEdit->setFocus(); // Установка фокуса на первый lineEdit
}

TrainAddWindow::~TrainAddWindow()
{
    delete ui;
}

bool TrainAddWindow::eventFilter(QObject *obj, QEvent *event)
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


void TrainAddWindow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
}

void TrainAddWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void TrainAddWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void TrainAddWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
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

// Определяем слот для сворачивания текущего окна
void TrainAddWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (TrainAddWindow)
    this->showMinimized();
}

