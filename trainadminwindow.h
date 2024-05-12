#ifndef TRAINADMINWINDOW_H
#define TRAINADMINWINDOW_H

#include <QWidget>

namespace Ui {
class TrainAdminWindow;
}

class TrainAdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TrainAdminWindow(QWidget *parent = nullptr);
    ~TrainAdminWindow();

private:
    Ui::TrainAdminWindow *ui;
};

#endif // TRAINADMINWINDOW_H
