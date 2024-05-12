#ifndef CHOICEWINDOW_H
#define CHOICEWINDOW_H

#include <QWidget>

namespace Ui {
class ChoiceWindow;
}

class ChoiceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChoiceWindow(QWidget *parent = nullptr);
    ~ChoiceWindow();

private:
    Ui::ChoiceWindow *ui;
};

#endif // CHOICEWINDOW_H
