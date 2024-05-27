#include "mainwindow.h"
#include <QApplication>
#include "connection.h"
#include <QtSql/QSqlDatabase>
#include <QtCore/QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    if (!createConnection())
        return 1;

    w.show();
    qDebug() << QSqlDatabase::drivers();
    return a.exec();
}
