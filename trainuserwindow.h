#ifndef TRAINUSERWINDOW_H
#define TRAINUSERWINDOW_H

#include <QWidget>

namespace Ui {
class TrainUserWindow;
}

class TrainUserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TrainUserWindow(QWidget *parent = nullptr);
    ~TrainUserWindow();

private:
    Ui::TrainUserWindow *ui;
};

#endif // TRAINUSERWINDOW_H
