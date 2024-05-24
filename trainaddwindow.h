#ifndef TRAINADDWINDOW_H
#define TRAINADDWINDOW_H

#include <QWidget>

namespace Ui {
class TrainAddWindow;
}

class TrainAddWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TrainAddWindow(QWidget *parent = nullptr);
    ~TrainAddWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::TrainAddWindow *ui;
};

#endif // TRAINADDWINDOW_H
