#ifndef STATIONADDWINDOW_H
#define STATIONADDWINDOW_H

#include <QWidget>
#include <QEvent>
#include <QPushButton>
#include <QIcon>

namespace Ui {
class StationAddWindow;
}

class StationAddWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StationAddWindow(QWidget *parent = nullptr);
    ~StationAddWindow();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_pushButton_9_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::StationAddWindow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора

    void updateButtonIcon(QPushButton *button, const QString &iconPath);
};

#endif // STATIONADDWINDOW_H
