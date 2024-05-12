#ifndef TRAINUSERWINDOW_H
#define TRAINUSERWINDOW_H

#include <QWidget>

namespace Ui {
class TrainUserWindow;
}

class TrainUserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TrainUserWindow(QWidget *parent = nullptr);
    ~TrainUserWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::TrainUserWindow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора
};

#endif // TRAINUSERWINDOW_H
