/********************************************************************************
** Form generated from reading UI file 'trainaddwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINADDWINDOW_H
#define UI_TRAINADDWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainAddWindow
{
public:
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_9;

    void setupUi(QWidget *TrainAddWindow)
    {
        if (TrainAddWindow->objectName().isEmpty())
            TrainAddWindow->setObjectName("TrainAddWindow");
        TrainAddWindow->resize(982, 628);
        label = new QLabel(TrainAddWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 982, 628));
        label->setPixmap(QPixmap(QString::fromUtf8(":/addWindow.png")));
        pushButton_3 = new QPushButton(TrainAddWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(934, 14, 17, 17));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/swapIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(17, 17));
        pushButton_2 = new QPushButton(TrainAddWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(958, 14, 17, 17));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/closeIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(17, 17));
        lineEdit = new QLineEdit(TrainAddWindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(43, 115, 895, 66));
        QFont font;
        font.setFamilies({QString::fromUtf8("Karla")});
        font.setPointSize(16);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid #4DB8FF;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: white;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}\n"
""));
        lineEdit_2 = new QLineEdit(TrainAddWindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(43, 206, 895, 66));
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
        lineEdit_3 = new QLineEdit(TrainAddWindow);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(43, 297, 895, 66));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
""));
        pushButton_9 = new QPushButton(TrainAddWindow);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(371, 476, 240, 82));
        pushButton_9->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/appendAdminButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon2);
        pushButton_9->setIconSize(QSize(240, 82));

        retranslateUi(TrainAddWindow);

        QMetaObject::connectSlotsByName(TrainAddWindow);
    } // setupUi

    void retranslateUi(QWidget *TrainAddWindow)
    {
        TrainAddWindow->setWindowTitle(QCoreApplication::translate("TrainAddWindow", "Form", nullptr));
        label->setText(QString());
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
        pushButton_9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TrainAddWindow: public Ui_TrainAddWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINADDWINDOW_H
