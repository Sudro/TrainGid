#ifndef STATIONADMINWINDOW_H
#define STATIONADMINWINDOW_H

#include <QWidget>

namespace Ui {
class StationAdminWIndow;
}

class StationAdminWIndow : public QWidget
{
    Q_OBJECT

public:
    explicit StationAdminWIndow(QWidget *parent = nullptr);
    ~StationAdminWIndow();

private:
    Ui::StationAdminWIndow *ui;
};

#endif // STATIONADMINWINDOW_H
