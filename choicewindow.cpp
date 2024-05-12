#include "choicewindow.h"
#include "ui_choicewindow.h"
#include "trainuserwindow.h"
#include "trainadminwindow.h"
#include <QMouseEvent>

ChoiceWindow::ChoiceWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChoiceWindow)
{
    ui->setupUi(this);

    // Устанавливаем флаг Qt::FramelessWindowHint
    setWindowFlags(Qt::FramelessWindowHint);
}

ChoiceWindow::~ChoiceWindow()
{
    delete ui;
}

// Определяем слот для закрытия текущего окна
void ChoiceWindow::on_pushButton_2_clicked()
{
    // Закрываем текущее окно (ChoiceWindow)
    this->close();
}

// Определяем слот для сворачивания текущего окна
void ChoiceWindow::on_pushButton_3_clicked()
{
    // Сворачиваем текущее окно (ChoiceWindow)
    this->showMinimized();
}

void ChoiceWindow::on_pushButton_5_clicked()
{
    // Создаем экземпляр окна TrainAdminWindow
    TrainAdminWindow *trainAdminWindow = new TrainAdminWindow();
    // Показываем окно TrainAdminWindow
    trainAdminWindow->show();
    // Закрываем текущее окно (ChoiceWindow)
    this->close();
}

void ChoiceWindow::on_pushButton_4_clicked()
{
    // Создаем экземпляр окна TrainUserWindow
    TrainUserWindow *trainUserWindow = new TrainUserWindow();
    // Показываем окно TrainUserWindow
    trainUserWindow->show();
    // Закрываем текущее окно (ChoiceWindow)
    this->close();
}

void ChoiceWindow::mousePressEvent(QMouseEvent *event)
{
    // Запоминаем текущие координаты курсора
    m_lastPoint = event->globalPos();
}

// Обработчик перемещения мыши
void ChoiceWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Вычисляем разницу между текущим положением курсора и предыдущим положением
    QPoint delta = event->globalPos() - m_lastPoint;

    // Перемещаем окно на это расстояние
    move(x() + delta.x(), y() + delta.y());

    // Обновляем предыдущее положение курсора
    m_lastPoint = event->globalPos();
}

// Обработчик отпускания кнопки мыши
void ChoiceWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Ничего не делаем
}
