#ifndef TRAINSTATIONADMINWINDOW_H
#define TRAINSTATIONADMINWINDOW_H

#include <QWidget>
#include <QEvent>
#include <QPushButton>
#include <QIcon>
#include <QStandardItemModel>

namespace Ui {
class TrainStationAdminWindow;
}

class TrainStationAdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TrainStationAdminWindow(QWidget *parent = nullptr);
    ~TrainStationAdminWindow();

    static TrainStationAdminWindow* getInstance(QWidget *parent = nullptr); //

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void updateModel();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

signals:
    void dataAdded();

private:
    Ui::TrainStationAdminWindow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора

    void updateButtonIcon(QPushButton *button, const QString &iconPath);

    static TrainStationAdminWindow* instance; // Статическая переменная для хранения экземпляра //
};

#endif // TRAINSTATIONADMINWINDOW_H
