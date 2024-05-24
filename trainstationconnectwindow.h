#ifndef TRAINSTATIONCONNECTWINDOW_H
#define TRAINSTATIONCONNECTWINDOW_H

#include <QWidget>

namespace Ui {
class TrainStationConnectWindow;
}

class TrainStationConnectWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TrainStationConnectWindow(QWidget *parent = nullptr);
    ~TrainStationConnectWindow();

private:
    Ui::TrainStationConnectWindow *ui;
};

#endif // TRAINSTATIONCONNECTWINDOW_H
