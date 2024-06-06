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

    static StationAddWindow* getInstance(QWidget *parent = nullptr);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:
    void dataChanged();  // Сигнал для обновления данных в StationAdminWIndow

private slots:
    void on_pushButton_9_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void validateInput(); // Слот для проверки ввода

    //void validateLineEdit3(); // Слот для проверки lineEdit_3

private:
    Ui::StationAddWindow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора

    void updateButtonIcon(QPushButton *button, const QString &iconPath);

    static StationAddWindow* instance; // Статическая переменная для хранения экземпляра
};

#endif // STATIONADDWINDOW_H
