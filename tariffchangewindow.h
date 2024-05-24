#ifndef TARIFFCHANGEWINDOW_H
#define TARIFFCHANGEWINDOW_H

#include <QWidget>

namespace Ui {
class TariffChangeWindow;
}

class TariffChangeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TariffChangeWindow(QWidget *parent = nullptr);
    ~TariffChangeWindow();

private:
    Ui::TariffChangeWindow *ui;
};

#endif // TARIFFCHANGEWINDOW_H
