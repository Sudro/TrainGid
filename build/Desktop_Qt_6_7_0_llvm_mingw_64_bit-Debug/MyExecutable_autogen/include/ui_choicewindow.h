/********************************************************************************
** Form generated from reading UI file 'choicewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOICEWINDOW_H
#define UI_CHOICEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChoiceWindow
{
public:
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QWidget *ChoiceWindow)
    {
        if (ChoiceWindow->objectName().isEmpty())
            ChoiceWindow->setObjectName("ChoiceWindow");
        ChoiceWindow->resize(982, 628);
        label = new QLabel(ChoiceWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 982, 628));
        label->setPixmap(QPixmap(QString::fromUtf8(":/choiceFrame.png")));
        pushButton_2 = new QPushButton(ChoiceWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(958, 14, 17, 17));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/closeIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(17, 17));
        pushButton_3 = new QPushButton(ChoiceWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(934, 14, 17, 17));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/swapIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(17, 17));
        pushButton_4 = new QPushButton(ChoiceWindow);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(62, 207, 429, 89));
        pushButton_4->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/userButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon2);
        pushButton_4->setIconSize(QSize(429, 89));
        pushButton_5 = new QPushButton(ChoiceWindow);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(62, 352, 429, 89));
        pushButton_5->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/adminButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon3);
        pushButton_5->setIconSize(QSize(429, 89));

        retranslateUi(ChoiceWindow);

        QMetaObject::connectSlotsByName(ChoiceWindow);
    } // setupUi

    void retranslateUi(QWidget *ChoiceWindow)
    {
        ChoiceWindow->setWindowTitle(QCoreApplication::translate("ChoiceWindow", "Form", nullptr));
        label->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChoiceWindow: public Ui_ChoiceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOICEWINDOW_H
