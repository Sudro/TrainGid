#ifndef TARIFFDELETEWINDOW_H
#define TARIFFDELETEWINDOW_H

#include <QWidget>

namespace Ui {
class TariffDeleteWindow;
}

class TariffDeleteWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TariffDeleteWindow(QWidget *parent = nullptr);
    ~TariffDeleteWindow();

private:
    Ui::TariffDeleteWindow *ui;
};

#endif // TARIFFDELETEWINDOW_H
