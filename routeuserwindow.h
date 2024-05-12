#ifndef ROUTEUSERWINDOW_H
#define ROUTEUSERWINDOW_H

#include <QWidget>

namespace Ui {
class RouteWindow;
}

class RouteWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RouteWindow(QWidget *parent = nullptr);
    ~RouteWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::RouteWindow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора
};

#endif // ROUTEUSERWINDOW_H
