#ifndef TRAINSTATIONCONNECTWINDOW_H
#define TRAINSTATIONCONNECTWINDOW_H

#include <QWidget>
#include <QEvent>
#include <QPushButton>
#include <QIcon>

namespace Ui {
class TrainStationConnectWindow;
}

class TrainStationConnectWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TrainStationConnectWindow(QWidget *parent = nullptr);
    ~TrainStationConnectWindow();

    static TrainStationConnectWindow* getInstance(QWidget *parent = nullptr);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:
    void dataChanged();  // Сигнал для обновления данных в TariffAdminWindow

private slots:
    void on_pushButton_9_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void on_comboBox_activated(int index);

private:
    Ui::TrainStationConnectWindow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора

    void updateButtonIcon(QPushButton *button, const QString &iconPath);

    void loadComboBoxData(); // Функция для загрузки данных в comboBox

    void loadComboBoxStationsData(); // Функция для загрузки данных в comboBox_2

    static TrainStationConnectWindow* instance; // Статическая переменная для хранения экземпляра
};

#endif // TRAINSTATIONCONNECTWINDOW_H
