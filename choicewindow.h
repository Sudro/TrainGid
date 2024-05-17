#ifndef CHOICEWINDOW_H
#define CHOICEWINDOW_H

#include <QWidget>
#include <QEvent>
#include <QPushButton>
#include <QIcon>

namespace Ui {
class ChoiceWindow;
}

class ChoiceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChoiceWindow(QWidget *parent = nullptr);
    ~ChoiceWindow();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;


private:
    Ui::ChoiceWindow *ui;

    QPoint m_lastPoint; // Добавляем переменную для хранения последней позиции курсора

    void updateButtonIcon(QPushButton *button, const QString &iconPath);
};

#endif // CHOICEWINDOW_H
