/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *main;
    QPushButton *goUserButton;
    QPushButton *goWorkerButton;
    QWidget *user;
    QPushButton *returnToMain;
    QTableView *tableView;
    QPushButton *buyButton;
    QWidget *worker;
    QPushButton *returnToMain_2;
    QTableView *tableViewDisks;
    QLabel *label;
    QTableView *tableViewGenre;
    QLabel *label_2;
    QLineEdit *titleEdit;
    QLineEdit *releaseEdit;
    QLineEdit *genreIdEdit;
    QLineEdit *priceEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *stockEdit;
    QLabel *label_7;
    QPushButton *addDisk;
    QPushButton *addGenre;
    QLineEdit *genreEdit;
    QLabel *label_8;
    QWidget *admin;
    QPushButton *returnToMain_3;
    QMenuBar *menubar;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 781, 471));
        stackedWidget->setMaximumSize(QSize(781, 471));
        main = new QWidget();
        main->setObjectName("main");
        goUserButton = new QPushButton(main);
        goUserButton->setObjectName("goUserButton");
        goUserButton->setGeometry(QRect(210, 200, 141, 26));
        goUserButton->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 209, 122);"));
        goWorkerButton = new QPushButton(main);
        goWorkerButton->setObjectName("goWorkerButton");
        goWorkerButton->setGeometry(QRect(410, 200, 141, 26));
        goWorkerButton->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 209, 122);"));
        stackedWidget->addWidget(main);
        user = new QWidget();
        user->setObjectName("user");
        returnToMain = new QPushButton(user);
        returnToMain->setObjectName("returnToMain");
        returnToMain->setGeometry(QRect(570, 430, 191, 26));
        tableView = new QTableView(user);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 10, 531, 371));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    border: 1px solid #dcdcdc;\n"
"    gridline-color: #dcdcdc;\n"
"    background-color: #f9f9f9;\n"
"    alternate-background-color: #f1f1f1;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #f0f0f0;\n"
"    color: #333;\n"
"    padding: 4px;\n"
"    border: 1px solid #dcdcdc;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 4px;\n"
"    border: none;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #a8d8ea;\n"
"    color: #333;\n"
"}"));
        buyButton = new QPushButton(user);
        buyButton->setObjectName("buyButton");
        buyButton->setGeometry(QRect(230, 390, 87, 26));
        stackedWidget->addWidget(user);
        worker = new QWidget();
        worker->setObjectName("worker");
        returnToMain_2 = new QPushButton(worker);
        returnToMain_2->setObjectName("returnToMain_2");
        returnToMain_2->setGeometry(QRect(570, 430, 191, 26));
        tableViewDisks = new QTableView(worker);
        tableViewDisks->setObjectName("tableViewDisks");
        tableViewDisks->setGeometry(QRect(10, 50, 361, 221));
        tableViewDisks->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    border: 1px solid #dcdcdc;\n"
"    gridline-color: #dcdcdc;\n"
"    background-color: #f9f9f9;\n"
"    alternate-background-color: #f1f1f1;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #f0f0f0;\n"
"    color: #333;\n"
"    padding: 4px;\n"
"    border: 1px solid #dcdcdc;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 4px;\n"
"    border: none;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #a8d8ea;\n"
"    color: #333;\n"
"}"));
        label = new QLabel(worker);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 181, 18));
        tableViewGenre = new QTableView(worker);
        tableViewGenre->setObjectName("tableViewGenre");
        tableViewGenre->setGeometry(QRect(390, 50, 371, 221));
        tableViewGenre->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    border: 1px solid #dcdcdc;\n"
"    gridline-color: #dcdcdc;\n"
"    background-color: #f9f9f9;\n"
"    alternate-background-color: #f1f1f1;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #f0f0f0;\n"
"    color: #333;\n"
"    padding: 4px;\n"
"    border: 1px solid #dcdcdc;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 4px;\n"
"    border: none;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #a8d8ea;\n"
"    color: #333;\n"
"}"));
        label_2 = new QLabel(worker);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(390, 20, 181, 18));
        titleEdit = new QLineEdit(worker);
        titleEdit->setObjectName("titleEdit");
        titleEdit->setGeometry(QRect(10, 300, 61, 26));
        releaseEdit = new QLineEdit(worker);
        releaseEdit->setObjectName("releaseEdit");
        releaseEdit->setGeometry(QRect(80, 300, 61, 26));
        genreIdEdit = new QLineEdit(worker);
        genreIdEdit->setObjectName("genreIdEdit");
        genreIdEdit->setGeometry(QRect(150, 300, 61, 26));
        priceEdit = new QLineEdit(worker);
        priceEdit->setObjectName("priceEdit");
        priceEdit->setGeometry(QRect(220, 300, 61, 26));
        label_3 = new QLabel(worker);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 280, 66, 18));
        label_4 = new QLabel(worker);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 280, 66, 18));
        label_5 = new QLabel(worker);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(150, 280, 66, 18));
        label_6 = new QLabel(worker);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(220, 280, 66, 18));
        stockEdit = new QLineEdit(worker);
        stockEdit->setObjectName("stockEdit");
        stockEdit->setGeometry(QRect(290, 300, 61, 26));
        label_7 = new QLabel(worker);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(290, 280, 66, 18));
        addDisk = new QPushButton(worker);
        addDisk->setObjectName("addDisk");
        addDisk->setGeometry(QRect(70, 400, 151, 26));
        addGenre = new QPushButton(worker);
        addGenre->setObjectName("addGenre");
        addGenre->setGeometry(QRect(390, 350, 151, 26));
        genreEdit = new QLineEdit(worker);
        genreEdit->setObjectName("genreEdit");
        genreEdit->setGeometry(QRect(390, 310, 151, 26));
        label_8 = new QLabel(worker);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(390, 280, 141, 18));
        stackedWidget->addWidget(worker);
        admin = new QWidget();
        admin->setObjectName("admin");
        returnToMain_3 = new QPushButton(admin);
        returnToMain_3->setObjectName("returnToMain_3");
        returnToMain_3->setGeometry(QRect(570, 430, 191, 26));
        stackedWidget->addWidget(admin);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_2->menuAction());

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        goUserButton->setText(QCoreApplication::translate("MainWindow", "\320\257 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214", nullptr));
        goWorkerButton->setText(QCoreApplication::translate("MainWindow", "\320\257 \321\200\320\260\320\261\320\276\321\202\320\275\320\270\320\272", nullptr));
        returnToMain->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260 \320\263\320\273\320\260\320\262\320\275\321\203\321\216", nullptr));
        buyButton->setText(QCoreApplication::translate("MainWindow", "\320\232\321\203\320\277\320\270\321\202\321\214", nullptr));
        returnToMain_2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260 \320\263\320\273\320\260\320\262\320\275\321\203\321\216", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\224\320\270\321\201\320\272\320\270 \320\262 \320\277\321\200\320\276\320\264\320\260\320\266\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\320\265 \320\266\320\260\320\275\321\200\321\213", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "title", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "release", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "genre_id", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "price", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "stock", nullptr));
        addDisk->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\264\320\270\321\201\320\272", nullptr));
        addGenre->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\226\320\260\320\275\321\200", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\266\320\260\320\275\321\200\320\260", nullptr));
        returnToMain_3->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260 \320\263\320\273\320\260\320\262\320\275\321\203\321\216", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\265\320\276\320\277\321\200\320\276\320\272\320\260\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
