/********************************************************************************
** Form generated from reading UI file 'trainstationconnectwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINSTATIONCONNECTWINDOW_H
#define UI_TRAINSTATIONCONNECTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainStationConnectWindow
{
public:
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_3;
    QComboBox *comboBox;
    QComboBox *comboBox_2;

    void setupUi(QWidget *TrainStationConnectWindow)
    {
        if (TrainStationConnectWindow->objectName().isEmpty())
            TrainStationConnectWindow->setObjectName("TrainStationConnectWindow");
        TrainStationConnectWindow->resize(982, 628);
        label = new QLabel(TrainStationConnectWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 982, 628));
        label->setPixmap(QPixmap(QString::fromUtf8(":/addConnectWindow.png")));
        pushButton_2 = new QPushButton(TrainStationConnectWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(958, 14, 17, 17));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/closeIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(17, 17));
        pushButton_9 = new QPushButton(TrainStationConnectWindow);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(371, 476, 240, 82));
        pushButton_9->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/connectTrainStationButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon1);
        pushButton_9->setIconSize(QSize(240, 82));
        pushButton_3 = new QPushButton(TrainStationConnectWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(934, 14, 17, 17));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/swapIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(17, 17));
        comboBox = new QComboBox(TrainStationConnectWindow);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(43, 164, 895, 66));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 3px solid #F4C64D;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: white;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"	subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 40px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/DownArrow.png);\n"
"}\n"
"\n"
"QComboBox::drop-down:hover {\n"
"	background-color: lightgray;\n"
"}\n"
"\n"
""));
        comboBox_2 = new QComboBox(TrainStationConnectWindow);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(43, 256, 895, 66));
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 3px solid #F4C64D;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: white;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"	subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 40px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/DownArrow.png);\n"
"}\n"
"\n"
"QComboBox::drop-down:hover {\n"
"	background-color: lightgray;\n"
"}\n"
"\n"
""));

        retranslateUi(TrainStationConnectWindow);

        QMetaObject::connectSlotsByName(TrainStationConnectWindow);
    } // setupUi

    void retranslateUi(QWidget *TrainStationConnectWindow)
    {
        TrainStationConnectWindow->setWindowTitle(QCoreApplication::translate("TrainStationConnectWindow", "Form", nullptr));
        label->setText(QString());
        pushButton_2->setText(QString());
        pushButton_9->setText(QString());
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TrainStationConnectWindow: public Ui_TrainStationConnectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINSTATIONCONNECTWINDOW_H
