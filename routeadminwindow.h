#ifndef ROUTEADMINWINDOW_H
#define ROUTEADMINWINDOW_H

#include <QWidget>

namespace Ui {
class RouteAdminWindow;
}

class RouteAdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RouteAdminWindow(QWidget *parent = nullptr);
    ~RouteAdminWindow();

private:
    Ui::RouteAdminWindow *ui;
};

#endif // ROUTEADMINWINDOW_H
