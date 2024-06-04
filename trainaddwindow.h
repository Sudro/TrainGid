#ifndef TRAINADDWINDOW_H
#define TRAINADDWINDOW_H

#include <QWidget>
#include <QEvent>
#include <QPushButton>
#include <QIcon>
//#include <QValidator>

namespace Ui {
class TrainAddWindow;
}

class TrainAddWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TrainAddWindow(QWidget *parent = nullptr);
    ~TrainAddWindow();

    static TrainAddWindow* getInstance(QWidget *parent = nullptr);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

    //void closeEvent(QCloseEvent *event) override; //

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void on_pushButton_3_clicked();

    void validateInput(); // Слот для проверки ввода

private:
    Ui::TrainAddWindow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора

    void updateButtonIcon(QPushButton *button, const QString &iconPath);

    static TrainAddWindow* instance; // Статическая переменная для хранения экземпляра

    //QValidator *numberValidator; // для проверки ввода на то, что есть только цифры
    //QValidator *textValidator; // для проверки ввода на то, что есть только текст с цифрами
    //QValidator *letterValidator; // для проверки ввода на то, что есть только текст

signals:
    void dataChanged();

    //void closing(); //

};

#endif // TRAINADDWINDOW_H
