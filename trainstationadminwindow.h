#ifndef TRAINSTATIONADMINWINDOW_H
#define TRAINSTATIONADMINWINDOW_H

#include <QWidget>

namespace Ui {
class TrainStationAdminWindow;
}

class TrainStationAdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TrainStationAdminWindow(QWidget *parent = nullptr);
    ~TrainStationAdminWindow();

private:
    Ui::TrainStationAdminWindow *ui;
};

#endif // TRAINSTATIONADMINWINDOW_H
