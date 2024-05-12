/********************************************************************************
** Form generated from reading UI file 'trainadminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINADMINWINDOW_H
#define UI_TRAINADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainAdminWindow
{
public:
    QLabel *label;
    QPushButton *pushButton_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;

    void setupUi(QWidget *TrainAdminWindow)
    {
        if (TrainAdminWindow->objectName().isEmpty())
            TrainAdminWindow->setObjectName("TrainAdminWindow");
        TrainAdminWindow->resize(982, 628);
        label = new QLabel(TrainAdminWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 982, 628));
        label->setPixmap(QPixmap(QString::fromUtf8(":/trainFrame.png")));
        pushButton_8 = new QPushButton(TrainAdminWindow);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(322, 20, 106, 37));
        pushButton_8->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/tariffsButton2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon);
        pushButton_8->setIconSize(QSize(106, 37));
        pushButton_5 = new QPushButton(TrainAdminWindow);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(701, 20, 106, 37));
        pushButton_5->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/trainButton2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon1);
        pushButton_5->setIconSize(QSize(106, 37));
        pushButton_7 = new QPushButton(TrainAdminWindow);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(438, 20, 116, 37));
        pushButton_7->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/stationsButton2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon2);
        pushButton_7->setIconSize(QSize(116, 37));
        pushButton_2 = new QPushButton(TrainAdminWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(955, 14, 17, 17));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/closeIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon3);
        pushButton_2->setIconSize(QSize(17, 17));
        pushButton_4 = new QPushButton(TrainAdminWindow);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(816, 20, 101, 37));
        pushButton_4->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/homeButton2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon4);
        pushButton_4->setIconSize(QSize(101, 37));
        pushButton_6 = new QPushButton(TrainAdminWindow);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(561, 20, 132, 37));
        pushButton_6->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/routeButton2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon5);
        pushButton_6->setIconSize(QSize(132, 37));
        pushButton_3 = new QPushButton(TrainAdminWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(931, 14, 17, 17));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/swapIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon6);
        pushButton_3->setIconSize(QSize(17, 17));
        pushButton_9 = new QPushButton(TrainAdminWindow);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(119, 419, 240, 82));
        pushButton_9->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/appendAdminButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon7);
        pushButton_9->setIconSize(QSize(240, 82));
        pushButton_10 = new QPushButton(TrainAdminWindow);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(381, 419, 240, 82));
        pushButton_10->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/changeAdminButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon8);
        pushButton_10->setIconSize(QSize(240, 82));
        pushButton_11 = new QPushButton(TrainAdminWindow);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(643, 419, 221, 82));
        pushButton_11->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/removeAdminButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon9);
        pushButton_11->setIconSize(QSize(221, 82));

        retranslateUi(TrainAdminWindow);

        QMetaObject::connectSlotsByName(TrainAdminWindow);
    } // setupUi

    void retranslateUi(QWidget *TrainAdminWindow)
    {
        TrainAdminWindow->setWindowTitle(QCoreApplication::translate("TrainAdminWindow", "Form", nullptr));
        label->setText(QString());
        pushButton_8->setText(QString());
        pushButton_5->setText(QString());
        pushButton_7->setText(QString());
        pushButton_2->setText(QString());
        pushButton_4->setText(QString());
        pushButton_6->setText(QString());
        pushButton_3->setText(QString());
        pushButton_9->setText(QString());
        pushButton_10->setText(QString());
        pushButton_11->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TrainAdminWindow: public Ui_TrainAdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINADMINWINDOW_H
