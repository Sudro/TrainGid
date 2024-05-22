#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QWidget>

namespace Ui {
class DeleteWindow;
}

class DeleteWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteWindow(QWidget *parent = nullptr);
    ~DeleteWindow();

private:
    Ui::DeleteWindow *ui;
};

#endif // DELETEWINDOW_H
