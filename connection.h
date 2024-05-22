#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>

inline bool createConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setPort(8080);
    db.setDatabaseName("postgres");
    db.setUserName("phob");
    db.setPassword("postgres");

    if (!db.open()) {
        QMessageBox::warning(0, "Ошибка БД", db.lastError().text());
        return false;
    }
    else {
        QMessageBox::information(0, "Успешно", "Соединение с БД установлено!");
        return true;
    }
}

inline bool createTables() {
    QSqlQuery query;
    query.exec("CREATE TABLE passwords ("
               "id INTEGER PRIMARY KEY, "
               "login VARCHAR(10) NOT NULL, "
               "passwd VARCHER(10) NOT NULL, "
               "datepass DATE NOT NULL)");
    return(1);
}

#endif // CONNECTION_H
