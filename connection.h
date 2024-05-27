#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>

inline bool createConnection() {
    // Используем имя соединения, которое будет использоваться во всем приложении
    QString connectionName = "unique_connection_name";

    // Проверяем, существует ли соединение
    if (!QSqlDatabase::contains(connectionName)) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", connectionName);
        db.setHostName("localhost");
        db.setPort(8080);
        db.setDatabaseName("postgres");
        db.setUserName("phob");
        db.setPassword("postgres");

        if (!db.open()) {
            QMessageBox::warning(0, "Ошибка БД", db.lastError().text());
            return false;
        }
    }

    QMessageBox::information(0, "Успешно", "Крч, работает БД твоя!");
    return true;
}

#endif // CONNECTION_H
