#ifndef STATIONUSERWINDOW_H
#define STATIONUSERWINDOW_H

#include <QWidget>

namespace Ui {
class StationUserWindow;
}

class StationUserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StationUserWindow(QWidget *parent = nullptr);
    ~StationUserWindow();

private:
    Ui::StationUserWindow *ui;
};

#endif // STATIONUSERWINDOW_H
