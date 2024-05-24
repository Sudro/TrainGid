#ifndef ROUTEDELETEWINDOW_H
#define ROUTEDELETEWINDOW_H

#include <QWidget>

namespace Ui {
class RouteDeleteWindow;
}

class RouteDeleteWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RouteDeleteWindow(QWidget *parent = nullptr);
    ~RouteDeleteWindow();

private:
    Ui::RouteDeleteWindow *ui;
};

#endif // ROUTEDELETEWINDOW_H
