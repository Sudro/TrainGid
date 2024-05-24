#ifndef TRAINCHANGEWINDOW_H
#define TRAINCHANGEWINDOW_H

#include <QWidget>
#include <QEvent>
#include <QPushButton>
#include <QIcon>

namespace Ui {
class TrainChangeWindow;
}

class TrainChangeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TrainChangeWindow(QWidget *parent = nullptr);
    ~TrainChangeWindow();

    void setTrainData(int trainId, const QString &trainNumber);
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
    Ui::TrainChangeWindow *ui;

    int trainId; // Хранение ID для использования при обновлении

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора

    void updateButtonIcon(QPushButton *button, const QString &iconPath);

signals:
    void dataChanged();  // Определение сигнала

    void closing();
};

#endif // TRAINCHANGEWINDOW_H
