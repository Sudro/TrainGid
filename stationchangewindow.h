#ifndef STATIONCHANGEWINDOW_H
#define STATIONCHANGEWINDOW_H

#include <QWidget>
#include <QEvent>
#include <QPushButton>
#include <QIcon>

namespace Ui {
class StationChangeWindow;
}

class StationChangeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StationChangeWindow(QWidget *parent = nullptr);
    ~StationChangeWindow();
    void setStationData(int stationId, const QString &stationName);

    static StationChangeWindow* getInstance(QWidget *parent = nullptr); //

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

    void validateInput(); // Слот для проверки ввода

private:
    Ui::StationChangeWindow *ui;

    int stationId; // Хранение ID для использования при обновлении

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора

    void updateButtonIcon(QPushButton *button, const QString &iconPath);

    static StationChangeWindow* instance; // Статическая переменная для хранения экземпляра

signals:
    void dataChanged();  // Определение сигнала

    void closing();
};

#endif // STATIONCHANGEWINDOW_H
