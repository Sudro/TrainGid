#ifndef TRAINADDWINDOW_H
#define TRAINADDWINDOW_H

#include <QWidget>
#include <QEvent>
#include <QPushButton>
#include <QIcon>

namespace Ui {
class TrainAddWindow;
}

class TrainAddWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TrainAddWindow(QWidget *parent = nullptr);
    ~TrainAddWindow();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void on_pushButton_3_clicked();

private:
    Ui::TrainAddWindow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора

    void updateButtonIcon(QPushButton *button, const QString &iconPath);
};

#endif // TRAINADDWINDOW_H
