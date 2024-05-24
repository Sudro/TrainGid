/********************************************************************************
** Form generated from reading UI file 'stationuserwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATIONUSERWINDOW_H
#define UI_STATIONUSERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StationUserWindow
{
public:
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_8;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QTableView *tableView;

    void setupUi(QWidget *StationUserWindow)
    {
        if (StationUserWindow->objectName().isEmpty())
            StationUserWindow->setObjectName("StationUserWindow");
        StationUserWindow->resize(982, 628);
        label = new QLabel(StationUserWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 982, 628));
        label->setPixmap(QPixmap(QString::fromUtf8(":/stationFrame.png")));
        pushButton_2 = new QPushButton(StationUserWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(958, 14, 17, 17));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/closeIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(17, 17));
        pushButton_8 = new QPushButton(StationUserWindow);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(356, 22, 126, 37));
        pushButton_8->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/tariffsButton2New.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon1);
        pushButton_8->setIconSize(QSize(126, 37));
        pushButton_4 = new QPushButton(StationUserWindow);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(790, 22, 126, 37));
        pushButton_4->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/homeButton2_New.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon2);
        pushButton_4->setIconSize(QSize(126, 37));
        pushButton_5 = new QPushButton(StationUserWindow);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(648, 22, 126, 37));
        pushButton_5->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/trainButton2New.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon3);
        pushButton_5->setIconSize(QSize(126, 37));
        pushButton_3 = new QPushButton(StationUserWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(934, 14, 17, 17));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/swapIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon4);
        pushButton_3->setIconSize(QSize(17, 17));
        pushButton_6 = new QPushButton(StationUserWindow);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(498, 22, 134, 37));
        pushButton_6->setStyleSheet(QString::fromUtf8("border-radius: 20px; "));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/routeButton2New.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon5);
        pushButton_6->setIconSize(QSize(134, 37));
        tableView = new QTableView(StationUserWindow);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(48, 115, 890, 449));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    border: 3px solid  #6E93FC; /* #6D55FF */\n"
"    border-radius: 5px;\n"
"    gridline-color:  #6E93FC; /* #6D55FF */\n"
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
"    background-color:  #6E93FC; /* #6D55FF */\n"
"    color: white;\n"
"}\n"
"\n"
"QTableView::item:focus {\n"
"    background-color:  #6E93FC; /* #6D55FF */\n"
"    color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color:  #6E93FC; /* #6D55FF */\n"
"    color: white;\n"
"    font-family: Karla;\n"
"    font-size: 14pt;\n"
"}\n"
""
                        "QHeaderView::section:horizontal {\n"
"    border: none; /* \321\203\320\261\320\270\321\200\320\260\320\265\320\274 \320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\321\213\320\265 \320\273\320\270\320\275\320\270\320\270 \321\200\320\260\320\267\320\264\320\265\320\273\320\270\321\202\320\265\320\273\321\217 */\n"
"}\n"
"\n"
"QHeaderView::section:vertical {\n"
"    border: none; /* \321\203\320\261\320\270\321\200\320\260\320\265\320\274 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\321\213\320\265 \320\273\320\270\320\275\320\270\320\270 \321\200\320\260\320\267\320\264\320\265\320\273\320\270\321\202\320\265\320\273\321\217 */\n"
"}"));
        tableView->setShowGrid(true);

        retranslateUi(StationUserWindow);

        QMetaObject::connectSlotsByName(StationUserWindow);
    } // setupUi

    void retranslateUi(QWidget *StationUserWindow)
    {
        StationUserWindow->setWindowTitle(QCoreApplication::translate("StationUserWindow", "Form", nullptr));
        label->setText(QString());
        pushButton_2->setText(QString());
        pushButton_8->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_3->setText(QString());
        pushButton_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StationUserWindow: public Ui_StationUserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIONUSERWINDOW_H
