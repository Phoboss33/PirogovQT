/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secondWindow
{
public:
    QWidget *centralwidget;
    QRadioButton *radioButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *secondWindow)
    {
        if (secondWindow->objectName().isEmpty())
            secondWindow->setObjectName("secondWindow");
        secondWindow->resize(800, 600);
        centralwidget = new QWidget(secondWindow);
        centralwidget->setObjectName("centralwidget");
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(190, 140, 109, 24));
        secondWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(secondWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        secondWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(secondWindow);
        statusbar->setObjectName("statusbar");
        secondWindow->setStatusBar(statusbar);

        retranslateUi(secondWindow);

        QMetaObject::connectSlotsByName(secondWindow);
    } // setupUi

    void retranslateUi(QMainWindow *secondWindow)
    {
        secondWindow->setWindowTitle(QCoreApplication::translate("secondWindow", "MainWindow", nullptr));
        radioButton->setText(QCoreApplication::translate("secondWindow", "RadioButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secondWindow: public Ui_secondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
