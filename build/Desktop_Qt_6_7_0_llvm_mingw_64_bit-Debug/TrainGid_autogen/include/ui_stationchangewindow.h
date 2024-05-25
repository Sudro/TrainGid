/********************************************************************************
** Form generated from reading UI file 'stationchangewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATIONCHANGEWINDOW_H
#define UI_STATIONCHANGEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StationChangeWindow
{
public:
    QLabel *label;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_10;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_4;

    void setupUi(QWidget *StationChangeWindow)
    {
        if (StationChangeWindow->objectName().isEmpty())
            StationChangeWindow->setObjectName("StationChangeWindow");
        StationChangeWindow->resize(982, 628);
        label = new QLabel(StationChangeWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 982, 628));
        label->setPixmap(QPixmap(QString::fromUtf8(":/changeWindow.png")));
        lineEdit_2 = new QLineEdit(StationChangeWindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(43, 198, 895, 66));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid #F0B78E;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: white;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}\n"
""));
        pushButton_10 = new QPushButton(StationChangeWindow);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(371, 476, 240, 82));
        pushButton_10->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/changeAdminButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon);
        pushButton_10->setIconSize(QSize(240, 82));
        lineEdit = new QLineEdit(StationChangeWindow);
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
"}\n"
"\n"
""));
        lineEdit_3 = new QLineEdit(StationChangeWindow);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(43, 281, 895, 66));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid #F0B78E;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: white;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}\n"
""));
        pushButton_3 = new QPushButton(StationChangeWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(934, 14, 17, 17));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/swapIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(17, 17));
        pushButton_2 = new QPushButton(StationChangeWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(958, 14, 17, 17));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/closeIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(17, 17));
        lineEdit_4 = new QLineEdit(StationChangeWindow);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(43, 364, 895, 66));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid #F0B78E;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: white;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}\n"
"\n"
""));

        retranslateUi(StationChangeWindow);

        QMetaObject::connectSlotsByName(StationChangeWindow);
    } // setupUi

    void retranslateUi(QWidget *StationChangeWindow)
    {
        StationChangeWindow->setWindowTitle(QCoreApplication::translate("StationChangeWindow", "Form", nullptr));
        label->setText(QString());
        pushButton_10->setText(QString());
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StationChangeWindow: public Ui_StationChangeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIONCHANGEWINDOW_H
