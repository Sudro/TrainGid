#ifndef TRAINCHANGEWINDOW_H
#define TRAINCHANGEWINDOW_H

#include <QWidget>

namespace Ui {
class TrainChangeWindow;
}

class TrainChangeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TrainChangeWindow(QWidget *parent = nullptr);
    ~TrainChangeWindow();

private:
    Ui::TrainChangeWindow *ui;
};

#endif // TRAINCHANGEWINDOW_H
