#ifndef STATIONUSERWINDOW_H
#define STATIONUSERWINDOW_H

#include <QWidget>

namespace Ui {
class StationUserWindow;
}

class StationUserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StationUserWindow(QWidget *parent = nullptr);
    ~StationUserWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::StationUserWindow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора
};

#endif // STATIONUSERWINDOW_H
