#include "trainaddwindow.h"
#include "trainadminwindow.h"
#include "ui_trainaddwindow.h"
#include "databasemanager.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMouseEvent>
#include <QRegularExpressionValidator>

TrainAddWindow* TrainAddWindow::instance = nullptr; //

TrainAddWindow* TrainAddWindow::getInstance(QWidget *parent) { //
    if (!instance)
        instance = new TrainAddWindow(parent);
    return instance;
}

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



    /*
    // Создаем валидаторы
    numberValidator = new QRegularExpressionValidator(QRegularExpression("\\d+"), this); // Только текст (цифры и буквы)
    textValidator = new QRegularExpressionValidator(QRegularExpression("\\w+"), this); // Только цифры
    letterValidator = new QRegularExpressionValidator(QRegularExpression("[A-Za-zА-Яа-я]+"), this); // Только буквы

    // Присоединяем валидаторы к полям ввода
    ui->lineEdit->setValidator(numberValidator);
    ui->lineEdit_2->setValidator(textValidator);
    ui->lineEdit_3->setValidator(letterValidator);
    */

    // Подключаем сигнал изменения текста к слоту проверки ввода
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &TrainAddWindow::validateInput);
    connect(ui->lineEdit_2, &QLineEdit::textChanged, this, &TrainAddWindow::validateInput);
    connect(ui->lineEdit_3, &QLineEdit::textChanged, this, &TrainAddWindow::validateInput);
}

TrainAddWindow::~TrainAddWindow()
{
    delete ui;

    instance = nullptr;
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
    /*
    // Создаем экземпляр окна TrainAdminWindow
    TrainAdminWindow *trainAdminWindow = new TrainAdminWindow();
    // Показываем окно TrainAdminWindow
    trainAdminWindow->show();
    // Закрываем текущее окно (TrainAddWindow)
    this->close();
    */

    TrainAdminWindow *trainAdminWindow = TrainAdminWindow::getInstance();
    trainAdminWindow->raise();
    trainAdminWindow->activateWindow();
    trainAdminWindow->show();
    this->close();
    instance = nullptr;
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

    /*
    // Проверяем, что поля прошли валидацию
    if (!ui->lineEdit->hasAcceptableInput()) {
        QMessageBox::warning(this, "Ошибка", "Номер поезда может состоять только из цифр!");
        return;
    }
    if (!ui->lineEdit_2->hasAcceptableInput()) {
        QMessageBox::warning(this, "Ошибка", "Название поезда может содержать только буквы и цифры!");
        return;
    }
    if (!ui->lineEdit_3->hasAcceptableInput()) {
        QMessageBox::warning(this, "Ошибка", "Тип поезда может содержать только буквы!");
        return;
    }
    */

    // Проверяем, что поля прошли валидацию
    bool valid = true;
    QString errorMessage;

    if (!trainNumber.contains(QRegularExpression("^\\d+$"))) {
        valid = false;
        errorMessage += "Номер поезда может состоять только из цифр!\n";
        ui->lineEdit->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }

    if (!trainName.contains(QRegularExpression("^[A-Za-zА-Яа-я0-9]+$"))) {
        valid = false;
        errorMessage += "Название поезда может содержать только буквы и цифры!\n";
        ui->lineEdit_2->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_2->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }

    if (!trainType.contains(QRegularExpression("^[A-Za-zА-Яа-я]+$"))) {
        valid = false;
        errorMessage += "Тип поезда может содержать только буквы!\n";
        ui->lineEdit_3->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_3->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }

    if (!valid) {
        QMessageBox::warning(this, "Ошибка", errorMessage.trimmed());
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

            emit dataChanged();
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            qDebug() << "Adding TrainAdminWindow as" << DatabaseManager::instance().currentUserName();
        }
    }
}
/*
void TrainAddWindow::validateInput()
{
    // Дополнительно изменяем стиль полей ввода при неправильных данных (красим границы)
    if (!ui->lineEdit->hasAcceptableInput() && !ui->lineEdit->text().isEmpty()) {
        ui->lineEdit->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }

    if (!ui->lineEdit_2->hasAcceptableInput() && !ui->lineEdit_2->text().isEmpty()) {
        ui->lineEdit_2->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_2->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }

    if (!ui->lineEdit_3->hasAcceptableInput() && !ui->lineEdit_3->text().isEmpty()) {
        ui->lineEdit_3->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_3->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }
}*/

void TrainAddWindow::validateInput()
{
    // Проверка ввода и установка соответствующего стиля
    if (!ui->lineEdit->text().contains(QRegularExpression("^\\d+$")) && !ui->lineEdit->text().isEmpty()) {
        ui->lineEdit->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }

    if (!ui->lineEdit_2->text().contains(QRegularExpression("^[A-Za-zА-Яа-я0-9]+$")) && !ui->lineEdit_2->text().isEmpty()) {
        ui->lineEdit_2->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_2->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }

    if (!ui->lineEdit_3->text().contains(QRegularExpression("^[A-Za-zА-Яа-я]+$")) && !ui->lineEdit_3->text().isEmpty()) {
        ui->lineEdit_3->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_3->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }
}

// Определяем слот для сворачивания текущего окна
void TrainAddWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (TrainAddWindow)
    this->showMinimized();
}

/*
void TrainAddWindow::closeEvent(QCloseEvent *event)
{
    emit closing();
    QWidget::closeEvent(event);
}*/

