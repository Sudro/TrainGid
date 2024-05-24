/********************************************************************************
** Form generated from reading UI file 'tariffdeletewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TARIFFDELETEWINDOW_H
#define UI_TARIFFDELETEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TariffDeleteWindow
{
public:
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_11;

    void setupUi(QWidget *TariffDeleteWindow)
    {
        if (TariffDeleteWindow->objectName().isEmpty())
            TariffDeleteWindow->setObjectName("TariffDeleteWindow");
        TariffDeleteWindow->resize(982, 628);
        label = new QLabel(TariffDeleteWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 982, 628));
        label->setPixmap(QPixmap(QString::fromUtf8(":/deleteWindow.png")));
        pushButton_2 = new QPushButton(TariffDeleteWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(958, 14, 17, 17));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/closeIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(17, 17));
        pushButton_3 = new QPushButton(TariffDeleteWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(934, 14, 17, 17));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/swapIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(17, 17));
        lineEdit_2 = new QLineEdit(TariffDeleteWindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(43, 249, 895, 66));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 3px solid #FF5E5E;\n"
"    border-radius: 8px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: white;	\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #6D55FF;\n"
"    color: white;\n"
"    font-family: Karla;\n"
"    font-size: 14pt;\n"
"}\n"
"QHeaderView::section:horizontal {\n"
"    border: none; /* \321\203\320\261\320\270\321\200\320\260\320\265\320\274 \320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\321\213\320\265 \320\273\320\270\320\275\320\270\320\270 \321\200\320\260\320\267\320\264\320\265\320\273\320\270\321\202\320\265\320\273\321\217 */\n"
"}\n"
"\n"
"QHeaderView::section:vertical {\n"
"    border: none; /* \321\203\320\261\320\270\321\200\320\260\320\265\320\274 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\321\213\320\265 \320\273\320\270\320\275\320\270\320\270 \321\200\320\260\320\267\320\264\320\265\320\273\320\270\321\202\320\265\320\273\321\217 */\n"
""
                        "}"));
        pushButton_11 = new QPushButton(TariffDeleteWindow);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(371, 476, 240, 82));
        pushButton_11->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/removeAdminNewButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon2);
        pushButton_11->setIconSize(QSize(240, 82));

        retranslateUi(TariffDeleteWindow);

        QMetaObject::connectSlotsByName(TariffDeleteWindow);
    } // setupUi

    void retranslateUi(QWidget *TariffDeleteWindow)
    {
        TariffDeleteWindow->setWindowTitle(QCoreApplication::translate("TariffDeleteWindow", "Form", nullptr));
        label->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_11->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TariffDeleteWindow: public Ui_TariffDeleteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TARIFFDELETEWINDOW_H
