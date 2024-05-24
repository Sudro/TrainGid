#ifndef TRAINSTATIONDELETEWINDOW_H
#define TRAINSTATIONDELETEWINDOW_H

#include <QWidget>

namespace Ui {
class TrainStationDeleteWindow;
}

class TrainStationDeleteWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TrainStationDeleteWindow(QWidget *parent = nullptr);
    ~TrainStationDeleteWindow();

private:
    Ui::TrainStationDeleteWindow *ui;
};

#endif // TRAINSTATIONDELETEWINDOW_H
