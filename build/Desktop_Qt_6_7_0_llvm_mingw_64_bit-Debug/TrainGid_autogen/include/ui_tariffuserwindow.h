/********************************************************************************
** Form generated from reading UI file 'tariffuserwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TARIFFUSERWINDOW_H
#define UI_TARIFFUSERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TariffUserWindow
{
public:
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QTableView *tableView;

    void setupUi(QWidget *TariffUserWindow)
    {
        if (TariffUserWindow->objectName().isEmpty())
            TariffUserWindow->setObjectName("TariffUserWindow");
        TariffUserWindow->resize(982, 628);
        label = new QLabel(TariffUserWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 982, 628));
        label->setPixmap(QPixmap(QString::fromUtf8(":/tariffFrame.png")));
        pushButton_3 = new QPushButton(TariffUserWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(934, 14, 17, 17));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/swapIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(17, 17));
        pushButton_4 = new QPushButton(TariffUserWindow);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(816, 22, 101, 37));
        pushButton_4->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/homeButton2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);
        pushButton_4->setIconSize(QSize(101, 37));
        pushButton_8 = new QPushButton(TariffUserWindow);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(322, 22, 106, 37));
        pushButton_8->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/tariffsButton2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon2);
        pushButton_8->setIconSize(QSize(106, 37));
        pushButton_2 = new QPushButton(TariffUserWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(958, 14, 17, 17));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/closeIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon3);
        pushButton_2->setIconSize(QSize(17, 17));
        pushButton_6 = new QPushButton(TariffUserWindow);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(561, 22, 132, 37));
        pushButton_6->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/routeButton2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon4);
        pushButton_6->setIconSize(QSize(132, 37));
        pushButton_7 = new QPushButton(TariffUserWindow);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(438, 22, 116, 37));
        pushButton_7->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/stationsButton2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon5);
        pushButton_7->setIconSize(QSize(116, 37));
        pushButton_5 = new QPushButton(TariffUserWindow);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(701, 22, 106, 37));
        pushButton_5->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/trainButton2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon6);
        pushButton_5->setIconSize(QSize(106, 37));
        tableView = new QTableView(TariffUserWindow);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(48, 115, 890, 449));
        tableView->setStyleSheet(QString::fromUtf8("border: 3px solid #6E93FC; border-radius: 5px; background-color: white; "));
        tableView->setShowGrid(true);

        retranslateUi(TariffUserWindow);

        QMetaObject::connectSlotsByName(TariffUserWindow);
    } // setupUi

    void retranslateUi(QWidget *TariffUserWindow)
    {
        TariffUserWindow->setWindowTitle(QCoreApplication::translate("TariffUserWindow", "Form", nullptr));
        label->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_8->setText(QString());
        pushButton_2->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TariffUserWindow: public Ui_TariffUserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TARIFFUSERWINDOW_H
