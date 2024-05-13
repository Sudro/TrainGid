#ifndef TARIFFADMINWINDOW_H
#define TARIFFADMINWINDOW_H

#include <QWidget>

namespace Ui {
class TariffAdminWindow;
}

class TariffAdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TariffAdminWindow(QWidget *parent = nullptr);
    ~TariffAdminWindow();

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

    void on_pushButton_7_clicked();

private:
    Ui::TariffAdminWindow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора
};

#endif // TARIFFADMINWINDOW_H
