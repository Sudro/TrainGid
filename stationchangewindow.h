#ifndef STATIONCHANGEWINDOW_H
#define STATIONCHANGEWINDOW_H

#include <QWidget>

namespace Ui {
class StationChangeWindow;
}

class StationChangeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StationChangeWindow(QWidget *parent = nullptr);
    ~StationChangeWindow();

private:
    Ui::StationChangeWindow *ui;
};

#endif // STATIONCHANGEWINDOW_H
