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

    // Устанавливаем фильтр событий для кнопок
    ui->pushButton_2->installEventFilter(this);
    ui->pushButton_3->installEventFilter(this);
    ui->pushButton_4->installEventFilter(this);
    ui->pushButton_5->installEventFilter(this);
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

bool ChoiceWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::Enter || event->type() == QEvent::Leave) {
        QPushButton *button = qobject_cast<QPushButton*>(obj);
        if (button) {
            if (event->type() == QEvent::Enter) {
                if (button == ui->pushButton_2) {
                    updateButtonIcon(button, ":/closeIcon2.png");
                } else if (button == ui->pushButton_3) {
                    updateButtonIcon(button, ":/swapIcon2.png");
                } else if (button == ui->pushButton_4) {
                    updateButtonIcon(button, ":/userButton2.png");
                } else if (button == ui->pushButton_5) {
                    updateButtonIcon(button, ":/adminButton2.png");
                }
            } else if (event->type() == QEvent::Leave) {
                // Здесь можно вернуть исходную иконку кнопки
                if (button == ui->pushButton_2) {
                    updateButtonIcon(button, ":/closeIcon.png");
                } else if (button == ui->pushButton_3) {
                    updateButtonIcon(button, ":/swapIcon.png");
                } else if (button == ui->pushButton_4) {
                    updateButtonIcon(button, ":/userButton.png");
                } else if (button == ui->pushButton_5) {
                    updateButtonIcon(button, ":/adminButton.png");
                }
            }
        }
        return true;
    }
    return QWidget::eventFilter(obj, event);
}

void ChoiceWindow::updateButtonIcon(QPushButton *button, const QString &iconPath)
{
    button->setIcon(QIcon(iconPath));
}
