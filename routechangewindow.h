#ifndef ROUTECHANGEWINDOW_H
#define ROUTECHANGEWINDOW_H

#include <QWidget>

namespace Ui {
class RouteChangeWindow;
}

class RouteChangeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RouteChangeWindow(QWidget *parent = nullptr);
    ~RouteChangeWindow();

private:
    Ui::RouteChangeWindow *ui;
};

#endif // ROUTECHANGEWINDOW_H
