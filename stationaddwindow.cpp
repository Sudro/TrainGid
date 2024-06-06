#include "stationaddwindow.h"
#include "stationadminwindow.h"
#include "ui_stationaddwindow.h"
#include "databasemanager.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMouseEvent>
#include <QRegularExpressionValidator>

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

    // Подключаем сигнал изменения текста к слоту проверки ввода
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &StationAddWindow::validateInput);
    connect(ui->lineEdit_2, &QLineEdit::textChanged, this, &StationAddWindow::validateInput);
    connect(ui->lineEdit_3, &QLineEdit::textChanged, this, &StationAddWindow::validateInput);
    //connect(ui->lineEdit_3, &QLineEdit::textChanged, this, &StationAddWindow::validateLineEdit3);
    connect(ui->lineEdit_4, &QLineEdit::textChanged, this, &StationAddWindow::validateInput);
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
    QString addressType = ui->lineEdit_3->text().trimmed();
    QString countPlatforms = ui->lineEdit_4->text();

    QString cleanedAddress = addressType; // .remove(" "); // Удаляем все пробелы для проверки
    cleanedAddress.remove(" ");

    // Проверяем, что все поля заполнены
    if (stationName.isEmpty() || cityStation.isEmpty() || addressType.isEmpty() || countPlatforms.isEmpty() || cleanedAddress.isEmpty()) { // cleanedAddress.replace(" ", "").isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены!");
        return;
    }

    // Проверяем, что поля прошли валидацию
    bool valid = true;
    QString errorMessage;

    if (!stationName.contains(QRegularExpression("^[A-Za-zА-Яа-я0-9]+$"))) {
        valid = false;
        errorMessage += "Название станции может содержать только буквы и цифры!\n";
        ui->lineEdit->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }

    if (!cityStation.contains(QRegularExpression("^[A-Za-zА-Яа-я]+$"))) {
        valid = false;
        errorMessage += "Город станции может содержать только буквы!\n";
        ui->lineEdit_2->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_2->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }

    /*
    // !addressType.contains(QRegularExpression("^[A-Za-zА-Яа-я0-9 ,]+$")) && !addressType.isEmpty() && addressType.replace(" ", "").isEmpty()
    if (!addressType.contains(QRegularExpression("^[A-Za-zА-Яа-я0-9 ,]+$"))) {
        valid = false;
        errorMessage += "Адрес станции может содержать только буквы и цифры!\n";
        ui->lineEdit_3->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_3->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } */

    // !ui->lineEdit_3->text().contains(QRegularExpression("^[A-Za-zА-Яа-я0-9 ,]+$")) && !ui->lineEdit_3->text().isEmpty()
    if (!addressType.contains(QRegularExpression("^[A-Za-zА-Яа-я0-9 ,]+$")) ) {//&& ui->lineEdit_3->hasFocus()) { // || cleanedAddress.replace(" ", "").isEmpty() && ui->lineEdit_3->hasFocus()) {
        valid = false;
        errorMessage += "Адрес станции может содержать только буквы и цифры!\n";
        ui->lineEdit_3->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else if (addressType.isEmpty() && ui->lineEdit_3->hasFocus()) {
        ui->lineEdit_3->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } /*else if  (ui->lineEdit_3->hasFocus()) {
        ui->lineEdit_3->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }*/

    /*
    if (!countPlatforms.contains(QRegularExpression("^\\d+$"))) {
        valid = false;
        errorMessage += "Количество платформ может состоять только из цифр!\n";
        ui->lineEdit_4->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_4->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }*/

    // Проверка на ввод "0" в количестве платформ
    if (countPlatforms == "0") {
        countPlatforms = "Нет платформ";
        ui->lineEdit_4->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else if (countPlatforms.contains(QRegularExpression("^\\d+$"))) {
        ui->lineEdit_4->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        valid = false;
        errorMessage += "Количество платформ может состоять только из цифр!\n";
        ui->lineEdit_4->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }


    if (!valid) {
        QMessageBox::warning(this, "Ошибка", errorMessage.trimmed());
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
            qDebug() << "Adding StationAdminWIndow as" << DatabaseManager::instance().currentUserName();
        }
    }
}

void StationAddWindow::validateInput()
{
    QString stationName = ui->lineEdit->text();
    QString cityStation = ui->lineEdit_2->text();
    QString addressType = ui->lineEdit_3->text().trimmed();
    QString countPlatforms = ui->lineEdit_4->text();

    QString cleanedAddress = addressType; // удаление всех пробелов

    // Проверка ввода и установка соответствующего стиля
    if (!ui->lineEdit->text().contains(QRegularExpression("^[A-Za-zА-Яа-я0-9]+$")) && !ui->lineEdit->text().isEmpty()) {
        ui->lineEdit->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }

    if (!ui->lineEdit_2->text().contains(QRegularExpression("^[A-Za-zА-Яа-я]+$")) && !ui->lineEdit_2->text().isEmpty()) {
        ui->lineEdit_2->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_2->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }

    /*
    if (!ui->lineEdit_3->text().contains(QRegularExpression("^[A-Za-zА-Яа-я0-9 ,]+$")) && !ui->lineEdit_3->text().isEmpty() && ui->lineEdit_3->text().replace(" ", "").isEmpty()) {
        ui->lineEdit_3->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_3->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }*/

    if (!addressType.contains(QRegularExpression("^[A-Za-zА-Яа-я0-9 ,]+$")) && ui->lineEdit_3->hasFocus() ) { //&& ui->lineEdit_3->hasFocus()) {// || cleanedAddress.replace(" ", "").isEmpty() && ui->lineEdit_3->hasFocus()) {
        ui->lineEdit_3->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else if (addressType.isEmpty() && ui->lineEdit_3->hasFocus()) {
        ui->lineEdit_3->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else if  (ui->lineEdit_3->hasFocus()) {
        ui->lineEdit_3->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_3->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }

    /*
    if (!ui->lineEdit_3->text().contains(QRegularExpression("^[A-Za-zА-Яа-я0-9 ,]+$")) && !ui->lineEdit_3->text().isEmpty()) {
        ui->lineEdit_3->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else if (cleanedAddress.isEmpty() && !ui->lineEdit_3->text().isEmpty()) {
        ui->lineEdit_3->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_3->setStyleSheet("border: 3px солидный #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }*

    /*
    QString cleanedAddress = addressType.replace(" ", ""); // Удаляем все пробелы для проверки
    if (cleanedAddress.isEmpty()) {
        ui->lineEdit_3->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
        //QMessageBox::warning(this, "Ошибка", "Адрес не может состоять только из пробелов!");
        //return;
    } else {
        ui->lineEdit_3->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }*/

    if (!countPlatforms.contains(QRegularExpression("^\\d+$")) && !countPlatforms.isEmpty()) {
        ui->lineEdit_4->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_4->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }
}

/*
void StationAddWindow::validateLineEdit3() {
    if (ui->lineEdit_3->text().isEmpty() && ui->lineEdit_3->hasFocus()) {
        ui->lineEdit_3->setStyleSheet("border: 3px solid red; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    } else {
        ui->lineEdit_3->setStyleSheet("border: 3px solid #4DB8FF; border-radius: 8px; gridline-color: #6D55FF; background-color: white; color: black; font-size: 16pt; padding-left: 10px; font-family: Karla;");
    }
}*/

// Определяем слот для сворачивания текущего окна
void StationAddWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (StationAddWindow)
    this->showMinimized();
}


