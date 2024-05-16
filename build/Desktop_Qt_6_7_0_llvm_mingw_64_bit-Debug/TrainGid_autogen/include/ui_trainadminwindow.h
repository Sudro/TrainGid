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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainAdminWindow
{
public:
    QLabel *label;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QTableView *tableView;

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
        pushButton_8->setGeometry(QRect(356, 22, 126, 37));
        pushButton_8->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/tariffsButton2New.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon);
        pushButton_8->setIconSize(QSize(126, 37));
        pushButton_7 = new QPushButton(TrainAdminWindow);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(498, 22, 126, 37));
        pushButton_7->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/stationsButton2New.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon1);
        pushButton_7->setIconSize(QSize(126, 37));
        pushButton_2 = new QPushButton(TrainAdminWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(958, 14, 17, 17));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/closeIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(17, 17));
        pushButton_4 = new QPushButton(TrainAdminWindow);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(790, 22, 126, 37));
        pushButton_4->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/homeButton2_New.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setIconSize(QSize(126, 37));
        pushButton_6 = new QPushButton(TrainAdminWindow);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(640, 22, 134, 37));
        pushButton_6->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/routeButton2New.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon4);
        pushButton_6->setIconSize(QSize(134, 37));
        pushButton_3 = new QPushButton(TrainAdminWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(934, 14, 17, 17));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/swapIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon5);
        pushButton_3->setIconSize(QSize(17, 17));
        pushButton_9 = new QPushButton(TrainAdminWindow);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(119, 419, 240, 82));
        pushButton_9->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/appendAdminButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon6);
        pushButton_9->setIconSize(QSize(240, 82));
        pushButton_10 = new QPushButton(TrainAdminWindow);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(381, 419, 240, 82));
        pushButton_10->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/changeAdminButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon7);
        pushButton_10->setIconSize(QSize(240, 82));
        pushButton_11 = new QPushButton(TrainAdminWindow);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(643, 419, 221, 82));
        pushButton_11->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/removeAdminButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon8);
        pushButton_11->setIconSize(QSize(221, 82));
        tableView = new QTableView(TrainAdminWindow);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(48, 115, 890, 280));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    border: 3px solid #6E93FC;\n"
"    border-radius: 5px;\n"
"    gridline-color: #6D55FF;\n"
"    background-color: white;	\n"
"}\n"
"\n"
"QTableView::item {\n"
"    background-color: white;\n"
"    font-family: Karla; /* \320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"    font-size: 15pt; /* \320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \321\200\320\260\320\267\320\274\320\265\321\200\320\260 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"    color: black;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #6D55FF;\n"
"    color: white;\n"
"}\n"
"\n"
"QTableView::item:focus {\n"
"    background-color: #6D55FF;\n"
"    color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #6D55FF;\n"
"    color: white;\n"
"    font-family: Karla;\n"
"    font-size: 14pt;\n"
"}\n"
"QHeaderView::section:horizontal {\n"
"    border: none; /* \321\203\320\261"
                        "\320\270\321\200\320\260\320\265\320\274 \320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\321\213\320\265 \320\273\320\270\320\275\320\270\320\270 \321\200\320\260\320\267\320\264\320\265\320\273\320\270\321\202\320\265\320\273\321\217 */\n"
"}\n"
"\n"
"QHeaderView::section:vertical {\n"
"    border: none; /* \321\203\320\261\320\270\321\200\320\260\320\265\320\274 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\321\213\320\265 \320\273\320\270\320\275\320\270\320\270 \321\200\320\260\320\267\320\264\320\265\320\273\320\270\321\202\320\265\320\273\321\217 */\n"
"}"));
        tableView->setShowGrid(true);

        retranslateUi(TrainAdminWindow);

        QMetaObject::connectSlotsByName(TrainAdminWindow);
    } // setupUi

    void retranslateUi(QWidget *TrainAdminWindow)
    {
        TrainAdminWindow->setWindowTitle(QCoreApplication::translate("TrainAdminWindow", "Form", nullptr));
        label->setText(QString());
        pushButton_8->setText(QString());
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
