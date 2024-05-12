#ifndef TARIFFUSERWINDOW_H
#define TARIFFUSERWINDOW_H

#include <QWidget>

namespace Ui {
class TariffUserWindow;
}

class TariffUserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TariffUserWindow(QWidget *parent = nullptr);
    ~TariffUserWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::TariffUserWindow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора

};

#endif // TARIFFUSERWINDOW_H
