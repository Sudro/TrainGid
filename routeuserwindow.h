#ifndef ROUTEUSERWINDOW_H
#define ROUTEUSERWINDOW_H

#include <QWidget>

namespace Ui {
class RouteWindow;
}

class RouteWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RouteWindow(QWidget *parent = nullptr);
    ~RouteWindow();

private:
    Ui::RouteWindow *ui;
};

#endif // ROUTEUSERWINDOW_H
