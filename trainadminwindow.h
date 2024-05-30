#ifndef TRAINADMINWINDOW_H
#define TRAINADMINWINDOW_H

#include <QWidget>
#include <QEvent>
#include <QPushButton>
#include <QIcon>
#include <QStandardItemModel>

namespace Ui {
class TrainAdminWindow;
}

class TrainAdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TrainAdminWindow(QWidget *parent = nullptr);
    ~TrainAdminWindow();

    static TrainAdminWindow* getInstance(QWidget *parent = nullptr); //

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void updateModel();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

signals:
    void dataAdded();

private:
    Ui::TrainAdminWindow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора

    void updateButtonIcon(QPushButton *button, const QString &iconPath);

    static TrainAdminWindow* instance; // Статическая переменная для хранения экземпляра //
};

#endif // TRAINADMINWINDOW_H
