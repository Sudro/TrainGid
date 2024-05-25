/********************************************************************************
** Form generated from reading UI file 'stationaddwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATIONADDWINDOW_H
#define UI_STATIONADDWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StationAddWindow
{
public:
    QLabel *label;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_9;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_4;

    void setupUi(QWidget *StationAddWindow)
    {
        if (StationAddWindow->objectName().isEmpty())
            StationAddWindow->setObjectName("StationAddWindow");
        StationAddWindow->resize(982, 628);
        label = new QLabel(StationAddWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 982, 628));
        label->setPixmap(QPixmap(QString::fromUtf8(":/addWindow.png")));
        lineEdit_2 = new QLineEdit(StationAddWindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(43, 198, 895, 66));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid #4DB8FF;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: white;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}"));
        pushButton_9 = new QPushButton(StationAddWindow);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(371, 476, 240, 82));
        pushButton_9->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/appendAdminButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon);
        pushButton_9->setIconSize(QSize(240, 82));
        lineEdit_3 = new QLineEdit(StationAddWindow);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(43, 281, 895, 66));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid #4DB8FF;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: white;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}"));
        pushButton_2 = new QPushButton(StationAddWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(958, 14, 17, 17));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/closeIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(17, 17));
        pushButton_3 = new QPushButton(StationAddWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(934, 14, 17, 17));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/swapIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(17, 17));
        lineEdit = new QLineEdit(StationAddWindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(43, 115, 895, 66));
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
        lineEdit_4 = new QLineEdit(StationAddWindow);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(43, 364, 895, 66));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid #4DB8FF;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: white;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}"));
        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, pushButton_9);
        QWidget::setTabOrder(pushButton_9, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_2);

        retranslateUi(StationAddWindow);

        QMetaObject::connectSlotsByName(StationAddWindow);
    } // setupUi

    void retranslateUi(QWidget *StationAddWindow)
    {
        StationAddWindow->setWindowTitle(QCoreApplication::translate("StationAddWindow", "Form", nullptr));
        label->setText(QString());
        pushButton_9->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StationAddWindow: public Ui_StationAddWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIONADDWINDOW_H
