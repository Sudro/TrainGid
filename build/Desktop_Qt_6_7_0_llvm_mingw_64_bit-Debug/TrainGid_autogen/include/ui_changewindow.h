/********************************************************************************
** Form generated from reading UI file 'changewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEWINDOW_H
#define UI_CHANGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeWindow
{
public:

    void setupUi(QWidget *ChangeWindow)
    {
        if (ChangeWindow->objectName().isEmpty())
            ChangeWindow->setObjectName("ChangeWindow");
        ChangeWindow->resize(982, 628);

        retranslateUi(ChangeWindow);

        QMetaObject::connectSlotsByName(ChangeWindow);
    } // setupUi

    void retranslateUi(QWidget *ChangeWindow)
    {
        ChangeWindow->setWindowTitle(QCoreApplication::translate("ChangeWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeWindow: public Ui_ChangeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEWINDOW_H
