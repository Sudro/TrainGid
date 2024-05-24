#ifndef STATIONDELETEWINDOW_H
#define STATIONDELETEWINDOW_H

#include <QWidget>

namespace Ui {
class StationDeleteWindow;
}

class StationDeleteWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StationDeleteWindow(QWidget *parent = nullptr);
    ~StationDeleteWindow();

private:
    Ui::StationDeleteWindow *ui;
};

#endif // STATIONDELETEWINDOW_H
