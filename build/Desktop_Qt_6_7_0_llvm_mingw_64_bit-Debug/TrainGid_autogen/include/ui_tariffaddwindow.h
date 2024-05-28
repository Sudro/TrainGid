/********************************************************************************
** Form generated from reading UI file 'tariffaddwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TARIFFADDWINDOW_H
#define UI_TARIFFADDWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TariffAddWindow
{
public:
    QLabel *label;
    QPushButton *pushButton_9;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QComboBox *comboBox;
    QComboBox *comboBox_2;

    void setupUi(QWidget *TariffAddWindow)
    {
        if (TariffAddWindow->objectName().isEmpty())
            TariffAddWindow->setObjectName("TariffAddWindow");
        TariffAddWindow->resize(982, 628);
        label = new QLabel(TariffAddWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 982, 628));
        label->setPixmap(QPixmap(QString::fromUtf8(":/addWindow.png")));
        pushButton_9 = new QPushButton(TariffAddWindow);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(371, 516, 240, 82));
        pushButton_9->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/appendAdminButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon);
        pushButton_9->setIconSize(QSize(240, 82));
        pushButton_2 = new QPushButton(TariffAddWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(958, 14, 17, 17));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/closeIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(17, 17));
        pushButton_3 = new QPushButton(TariffAddWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(934, 14, 17, 17));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/swapIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(17, 17));
        lineEdit = new QLineEdit(TariffAddWindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(39, 96, 895, 48));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid #4DB8FF;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: white;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}"));
        lineEdit_5 = new QLineEdit(TariffAddWindow);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(39, 345, 895, 48));
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid #4DB8FF;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: white;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}"));
        lineEdit_6 = new QLineEdit(TariffAddWindow);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(39, 416, 895, 48));
        lineEdit_6->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid #4DB8FF;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: white;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}"));
        comboBox = new QComboBox(TariffAddWindow);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(39, 167, 895, 66));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 3px solid #4DB8FF;\n"
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
"QComboBox::down-arrow {\n"
"	image: url(:/DownArrow3.png);\n"
"}\n"
"QComboBox::drop-down:hover {\n"
"	background-color: lightgray;\n"
"}"));
        comboBox_2 = new QComboBox(TariffAddWindow);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(39, 256, 895, 66));
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 3px solid #4DB8FF;\n"
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
"QComboBox::down-arrow {\n"
"	image: url(:/DownArrow3.png);\n"
"}\n"
"QComboBox::drop-down:hover {\n"
"	background-color: lightgray;\n"
"}"));

        retranslateUi(TariffAddWindow);

        QMetaObject::connectSlotsByName(TariffAddWindow);
    } // setupUi

    void retranslateUi(QWidget *TariffAddWindow)
    {
        TariffAddWindow->setWindowTitle(QCoreApplication::translate("TariffAddWindow", "Form", nullptr));
        label->setText(QString());
        pushButton_9->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TariffAddWindow: public Ui_TariffAddWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TARIFFADDWINDOW_H
