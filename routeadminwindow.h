#ifndef ROUTEADMINWINDOW_H
#define ROUTEADMINWINDOW_H

#include <QWidget>
#include <QEvent>
#include <QPushButton>
#include <QIcon>

namespace Ui {
class RouteAdminWindow;
}

class RouteAdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RouteAdminWindow(QWidget *parent = nullptr);
    ~RouteAdminWindow();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::RouteAdminWindow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора

    void updateButtonIcon(QPushButton *button, const QString &iconPath);
};

#endif // ROUTEADMINWINDOW_H
