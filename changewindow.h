#ifndef CHANGEWINDOW_H
#define CHANGEWINDOW_H

#include <QWidget>

namespace Ui {
class ChangeWindow;
}

class ChangeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeWindow(QWidget *parent = nullptr);
    ~ChangeWindow();

private:
    Ui::ChangeWindow *ui;
};

#endif // CHANGEWINDOW_H
