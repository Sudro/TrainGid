#ifndef STATIONADMINWINDOW_H
#define STATIONADMINWINDOW_H

#include <QWidget>
#include <QEvent>
#include <QPushButton>
#include <QIcon>

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
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void updateModel();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::StationAdminWIndow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора

    void updateButtonIcon(QPushButton *button, const QString &iconPath);
};

#endif // STATIONADMINWINDOW_H
