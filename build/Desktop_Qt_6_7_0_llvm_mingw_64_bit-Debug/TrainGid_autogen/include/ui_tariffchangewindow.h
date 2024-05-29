/********************************************************************************
** Form generated from reading UI file 'tariffchangewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TARIFFCHANGEWINDOW_H
#define UI_TARIFFCHANGEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TariffChangeWindow
{
public:
    QLabel *label;
    QPushButton *pushButton_10;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;

    void setupUi(QWidget *TariffChangeWindow)
    {
        if (TariffChangeWindow->objectName().isEmpty())
            TariffChangeWindow->setObjectName("TariffChangeWindow");
        TariffChangeWindow->resize(982, 628);
        label = new QLabel(TariffChangeWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 982, 628));
        label->setPixmap(QPixmap(QString::fromUtf8(":/changeWindow.png")));
        pushButton_10 = new QPushButton(TariffChangeWindow);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(371, 516, 240, 82));
        pushButton_10->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/changeAdminButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon);
        pushButton_10->setIconSize(QSize(240, 82));
        lineEdit_2 = new QLineEdit(TariffChangeWindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(43, 204, 895, 48));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid #F0B78E;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: #D8D8D8;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}"));
        lineEdit_3 = new QLineEdit(TariffChangeWindow);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(43, 275, 895, 48));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid #F0B78E;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: #D8D8D8;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}"));
        lineEdit = new QLineEdit(TariffChangeWindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(43, 115, 895, 66));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid #F0B78E;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: #D8D8D8;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}"));
        pushButton_3 = new QPushButton(TariffChangeWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(934, 14, 17, 17));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/swapIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(17, 17));
        pushButton_2 = new QPushButton(TariffChangeWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(958, 14, 17, 17));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/closeIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(17, 17));
        lineEdit_4 = new QLineEdit(TariffChangeWindow);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(43, 346, 895, 48));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid #F0B78E;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: white;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}"));
        lineEdit_5 = new QLineEdit(TariffChangeWindow);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(43, 417, 895, 48));
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid #F0B78E;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: white;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}"));

        retranslateUi(TariffChangeWindow);

        QMetaObject::connectSlotsByName(TariffChangeWindow);
    } // setupUi

    void retranslateUi(QWidget *TariffChangeWindow)
    {
        TariffChangeWindow->setWindowTitle(QCoreApplication::translate("TariffChangeWindow", "Form", nullptr));
        label->setText(QString());
        pushButton_10->setText(QString());
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TariffChangeWindow: public Ui_TariffChangeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TARIFFCHANGEWINDOW_H
