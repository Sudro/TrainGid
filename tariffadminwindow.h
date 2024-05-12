#ifndef TARIFFADMINWINDOW_H
#define TARIFFADMINWINDOW_H

#include <QWidget>

namespace Ui {
class TariffAdminWindow;
}

class TariffAdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TariffAdminWindow(QWidget *parent = nullptr);
    ~TariffAdminWindow();

private:
    Ui::TariffAdminWindow *ui;
};

#endif // TARIFFADMINWINDOW_H
