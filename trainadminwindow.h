#ifndef TRAINADMINWINDOW_H
#define TRAINADMINWINDOW_H

#include <QWidget>

namespace Ui {
class TrainAdminWindow;
}

class TrainAdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TrainAdminWindow(QWidget *parent = nullptr);
    ~TrainAdminWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::TrainAdminWindow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора
};

#endif // TRAINADMINWINDOW_H
