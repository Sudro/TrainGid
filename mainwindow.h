#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "choicewindow.h" // Включаем заголовочный файл ChoiceWindow
#include "tariffuserwindow.h" // Включаем заголовочный файл для TariffUserWindow
#include "stationuserwindow.h" // Включаем заголовочный файл для StationUserwindow
#include "routeuserwindow.h" // Включаем заголовочный файл для RouteUserwindow
#include "trainuserwindow.h" // Включаем заголовочный файл для TrainUserwindow

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    ChoiceWindow *choiceWindow; // Добавьте указатель на ChoiceWindow
    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора
};
#endif // MAINWINDOW_H
