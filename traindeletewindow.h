#ifndef TRAINDELETEWINDOW_H
#define TRAINDELETEWINDOW_H

#include <QWidget>

namespace Ui {
class TrainDeleteWindow;
}

class TrainDeleteWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TrainDeleteWindow(QWidget *parent = nullptr);
    ~TrainDeleteWindow();

private:
    Ui::TrainDeleteWindow *ui;
};

#endif // TRAINDELETEWINDOW_H