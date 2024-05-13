#ifndef STATIONADMINWINDOW_H
#define STATIONADMINWINDOW_H

#include <QWidget>

namespace Ui {
class StationAdminWIndow;
}

class StationAdminWIndow : public QWidget
{
    Q_OBJECT

public:
    explicit StationAdminWIndow(QWidget *parent = nullptr);
    ~StationAdminWIndow();

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
    Ui::StationAdminWIndow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора
};

#endif // STATIONADMINWINDOW_H
