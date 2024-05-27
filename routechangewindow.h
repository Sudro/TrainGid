#ifndef ROUTECHANGEWINDOW_H
#define ROUTECHANGEWINDOW_H

#include <QWidget>
#include <QEvent>
#include <QPushButton>
#include <QIcon>

namespace Ui {
class RouteChangeWindow;
}

class RouteChangeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RouteChangeWindow(QWidget *parent = nullptr);
    ~RouteChangeWindow();

    //void setRouteData(int routeId, const QString &routeName);

    void setRouteData(int routeId, const QString &routeDescription, const QString &departurePoint, const QString &destination, const QString &tripDuration);

    static RouteChangeWindow* getInstance(QWidget *parent = nullptr); //

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

    void closeEvent(QCloseEvent *event) override; // Добавьте это объявление

private slots:
    void on_pushButton_10_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::RouteChangeWindow *ui;

    int routeId; // Хранение ID для использования при обновлении

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора

    void updateButtonIcon(QPushButton *button, const QString &iconPath);

    static RouteChangeWindow* instance; // Статическая переменная для хранения экземпляра

signals:
    void dataChanged();  // Определение сигнала

    void closing();
};

#endif // ROUTECHANGEWINDOW_H
