/********************************************************************************
** Form generated from reading UI file 'traindeletewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINDELETEWINDOW_H
#define UI_TRAINDELETEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainDeleteWindow
{
public:
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_11;
    QLineEdit *lineEdit_2;

    void setupUi(QWidget *TrainDeleteWindow)
    {
        if (TrainDeleteWindow->objectName().isEmpty())
            TrainDeleteWindow->setObjectName("TrainDeleteWindow");
        TrainDeleteWindow->resize(982, 628);
        label = new QLabel(TrainDeleteWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 982, 628));
        label->setPixmap(QPixmap(QString::fromUtf8(":/deleteWindow.png")));
        pushButton_3 = new QPushButton(TrainDeleteWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(934, 14, 17, 17));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/swapIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(17, 17));
        pushButton_2 = new QPushButton(TrainDeleteWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(958, 14, 17, 17));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/closeIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(17, 17));
        pushButton_11 = new QPushButton(TrainDeleteWindow);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(371, 476, 221, 82));
        pushButton_11->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/removeAdminButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon2);
        pushButton_11->setIconSize(QSize(221, 82));
        lineEdit_2 = new QLineEdit(TrainDeleteWindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(43, 249, 895, 66));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid #FF5E5E;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: white;	\n"
"	color: black;\n"
"	font-size: 16pt;\n"
"	padding-left: 10px;\n"
"	font-family: Karla;\n"
"}\n"
""));

        retranslateUi(TrainDeleteWindow);

        QMetaObject::connectSlotsByName(TrainDeleteWindow);
    } // setupUi

    void retranslateUi(QWidget *TrainDeleteWindow)
    {
        TrainDeleteWindow->setWindowTitle(QCoreApplication::translate("TrainDeleteWindow", "Form", nullptr));
        label->setText(QString());
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
        pushButton_11->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TrainDeleteWindow: public Ui_TrainDeleteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINDELETEWINDOW_H
