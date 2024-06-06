#ifndef TARIFFCHANGEWINDOW_H
#define TARIFFCHANGEWINDOW_H

#include <QWidget>
#include <QEvent>
#include <QPushButton>
#include <QIcon>

namespace Ui {
class TariffChangeWindow;
}

class TariffChangeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TariffChangeWindow(QWidget *parent = nullptr);
    ~TariffChangeWindow();
    void setTariffData(int tariffId, const QString &tariffName, const QString &route, const QString &station, const QString &details, const QString &price);

    static TariffChangeWindow* getInstance(QWidget *parent = nullptr); //

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
    Ui::TariffChangeWindow *ui;

    int tariffId; // Хранение ID для использования при обновлении

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора

    void updateButtonIcon(QPushButton *button, const QString &iconPath);

    static TariffChangeWindow* instance; // Статическая переменная для хранения экземпляра

signals:
    void dataChanged();  // Определение сигнала

    void closing();
};

#endif // TARIFFCHANGEWINDOW_H
