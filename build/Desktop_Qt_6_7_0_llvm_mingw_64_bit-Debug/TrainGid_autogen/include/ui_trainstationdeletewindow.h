/********************************************************************************
** Form generated from reading UI file 'trainstationdeletewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINSTATIONDELETEWINDOW_H
#define UI_TRAINSTATIONDELETEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainStationDeleteWindow
{
public:
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_3;
    QComboBox *comboBox_2;
    QComboBox *comboBox;

    void setupUi(QWidget *TrainStationDeleteWindow)
    {
        if (TrainStationDeleteWindow->objectName().isEmpty())
            TrainStationDeleteWindow->setObjectName("TrainStationDeleteWindow");
        TrainStationDeleteWindow->resize(982, 628);
        label = new QLabel(TrainStationDeleteWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 982, 628));
        label->setPixmap(QPixmap(QString::fromUtf8(":/DeleteConnectWindow.png")));
        pushButton_2 = new QPushButton(TrainStationDeleteWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(958, 14, 17, 17));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/closeIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(17, 17));
        pushButton_9 = new QPushButton(TrainStationDeleteWindow);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(371, 476, 240, 82));
        pushButton_9->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/removeAdminNewButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon1);
        pushButton_9->setIconSize(QSize(240, 82));
        pushButton_3 = new QPushButton(TrainStationDeleteWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(934, 14, 17, 17));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/swapIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(17, 17));
        comboBox_2 = new QComboBox(TrainStationDeleteWindow);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(43, 256, 895, 66));
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	border: 3px solid #FF5E5E;\n"
"    border-radius: 9px;\n"
"    padding: 5px 10px;\n"
"    min-width: 6em;\n"
"	background-color: white;	\n"
"}\n"
"QComboBox::drop-down {\n"
"	subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 40px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"	image: url(:/DownArrow2.png);\n"
"}\n"
"QComboBox::drop-down:hover {\n"
"	background-color: lightgray;\n"
"}"));
        comboBox = new QComboBox(TrainStationDeleteWindow);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(43, 164, 895, 66));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	border: 3px solid #FF5E5E;\n"
"    border-radius: 9px;\n"
"    padding: 5px 10px;\n"
"    min-width: 6em;\n"
"	background-color: white;	\n"
"}\n"
"QComboBox::drop-down {\n"
"	subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 40px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"	image: url(:/DownArrow2.png);\n"
"}\n"
"QComboBox::drop-down:hover {\n"
"	background-color: lightgray;\n"
"}"));

        retranslateUi(TrainStationDeleteWindow);

        QMetaObject::connectSlotsByName(TrainStationDeleteWindow);
    } // setupUi

    void retranslateUi(QWidget *TrainStationDeleteWindow)
    {
        TrainStationDeleteWindow->setWindowTitle(QCoreApplication::translate("TrainStationDeleteWindow", "Form", nullptr));
        label->setText(QString());
        pushButton_2->setText(QString());
        pushButton_9->setText(QString());
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TrainStationDeleteWindow: public Ui_TrainStationDeleteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINSTATIONDELETEWINDOW_H
