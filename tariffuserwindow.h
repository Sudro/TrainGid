#ifndef TARIFFUSERWINDOW_H
#define TARIFFUSERWINDOW_H

#include <QWidget>

namespace Ui {
class TariffUserWindow;
}

class TariffUserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TariffUserWindow(QWidget *parent = nullptr);
    ~TariffUserWindow();

private:
    Ui::TariffUserWindow *ui;
};

#endif // TARIFFUSERWINDOW_H
