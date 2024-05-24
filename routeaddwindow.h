#ifndef ROUTEADDWINDOW_H
#define ROUTEADDWINDOW_H

#include <QWidget>

namespace Ui {
class RouteAddWindow;
}

class RouteAddWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RouteAddWindow(QWidget *parent = nullptr);
    ~RouteAddWindow();

private:
    Ui::RouteAddWindow *ui;
};

#endif // ROUTEADDWINDOW_H
