#ifndef TARIFFADDWINDOW_H
#define TARIFFADDWINDOW_H

#include <QWidget>

namespace Ui {
class TariffAddWindow;
}

class TariffAddWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TariffAddWindow(QWidget *parent = nullptr);
    ~TariffAddWindow();

private:
    Ui::TariffAddWindow *ui;
};

#endif // TARIFFADDWINDOW_H
