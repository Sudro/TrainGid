#ifndef ROUTEADDWINDOW_H
#define ROUTEADDWINDOW_H

#include <QWidget>
#include <QEvent>
#include <QPushButton>
#include <QIcon>

namespace Ui {
class RouteAddWindow;
}

class RouteAddWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RouteAddWindow(QWidget *parent = nullptr);
    ~RouteAddWindow();

    static RouteAddWindow* getInstance(QWidget *parent = nullptr);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:
    void dataChanged();  // Сигнал для обновления данных в RouteAdminWindow

private slots:
    void on_pushButton_9_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::RouteAddWindow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора

    void updateButtonIcon(QPushButton *button, const QString &iconPath);

    static RouteAddWindow* instance; // Статическая переменная для хранения экземпляра

    void loadComboBoxData(); // Функция для загрузки данных в comboBox
};

#endif // ROUTEADDWINDOW_H
