#ifndef STATIONADDWINDOW_H
#define STATIONADDWINDOW_H

#include <QWidget>

namespace Ui {
class StationAddWindow;
}

class StationAddWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StationAddWindow(QWidget *parent = nullptr);
    ~StationAddWindow();

private:
    Ui::StationAddWindow *ui;
};

#endif // STATIONADDWINDOW_H
