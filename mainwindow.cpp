#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QStyledItemDelegate>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->main);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_returnToMain_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main);
}


void MainWindow::on_returnToMain_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main);
}


void MainWindow::on_returnToMain_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main);
}


// Main Menu
void MainWindow::on_goUserButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->user);

    QSqlTableModel *model = new QSqlTableModel(this, QSqlDatabase::database("unique_connection_name"));
    model->setTable("disks");
    model->setFilter("is_hidden = FALSE");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(model->fieldIndex("disk_id"));
    ui->tableView->hideColumn(model->fieldIndex("is_hidden"));
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_goWorkerButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->worker);
    QSqlQuery query(QSqlDatabase::database("unique_connection_name"));
    query.prepare("SELECT * FROM disks;");

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось выполнить запрос: " + query.lastError().text());
        return;
    }

    QSqlTableModel *model = new QSqlTableModel(this, QSqlDatabase::database("unique_connection_name"));
    model->setTable("disks");
    model->setFilter("is_hidden = FALSE");
    model->select();



    ui->tableViewDisks->setModel(model);
    ui->tableViewDisks->hideColumn(model->fieldIndex("disk_id"));
    ui->tableViewDisks->hideColumn(model->fieldIndex("is_hidden"));
    ui->tableViewDisks->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewDisks->resizeColumnsToContents();


    // genre
    query.prepare("SELECT * FROM genres;");

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось выполнить запрос: " + query.lastError().text());
        return;
    }

    QSqlTableModel *modelGenre = new QSqlTableModel(this, QSqlDatabase::database("unique_connection_name"));
    modelGenre->setTable("genres");
    modelGenre->select();



    ui->tableViewGenre->setModel(modelGenre);
    ui->tableViewGenre->hideColumn(modelGenre->fieldIndex("genre_id"));
    ui->tableViewGenre->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewGenre->resizeColumnsToContents();
}


void MainWindow::on_goAdminButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->admin);
}



// User Page
void MainWindow::on_buyButton_clicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите диск для покупки.");
        return;
    }

    int row = currentIndex.row();
    QSqlTableModel *model = qobject_cast<QSqlTableModel*>(ui->tableView->model());
    if (!model) {
        QMessageBox::critical(this, "Ошибка", "Не удалось получить модель данных.");
        return;
    }

    int diskId = model->data(model->index(row, model->fieldIndex("disk_id"))).toInt();

    QSqlDatabase db = QSqlDatabase::database("unique_connection_name");
    QSqlQuery query(db);

    if (!db.transaction()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось начать транзакцию: " + db.lastError().text());
        return;
    }

    query.prepare("INSERT INTO orders (user_id, disk_id, status) VALUES (1, :disk_id, 'processing')");
    query.bindValue(":disk_id", diskId);

    if (!query.exec()) {
        db.rollback();
        QMessageBox::critical(this, "Ошибка", "Не удалось записать заказ: " + query.lastError().text());
        return;
    }

    query.prepare("UPDATE disks SET is_hidden = TRUE WHERE disk_id = :disk_id");
    query.bindValue(":disk_id", diskId);

    if (!query.exec()) {
        db.rollback();
        QMessageBox::critical(this, "Ошибка", "Не удалось скрыть диск: " + query.lastError().text());
        return;
    }

    if (!db.commit()) {
        db.rollback();
        QMessageBox::critical(this, "Ошибка", "Не удалось завершить транзакцию: " + db.lastError().text());
        return;
    }

    model->select();
    QMessageBox::information(this, "Успешно", "Диск успешно куплен и заказ записан.");
}


// Worker Page
void MainWindow::on_addDisk_clicked()
{
    QString title = ui->titleEdit->text();
    int releaseYear = ui->releaseEdit->text().toInt();
    double price = ui->priceEdit->text().toDouble();
    int stock = ui->stockEdit->text().toInt();

    if (title.isEmpty() || ui->releaseEdit->text().isEmpty() || ui->priceEdit->text().isEmpty() || ui->stockEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Все поля должны быть заполнены.");
        return;
    }

    QModelIndex currentIndex = ui->tableViewGenre->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "Внимание", "Пожалуйста, выберите жанр.");
        return;
    }

    QSqlTableModel *genreModel = qobject_cast<QSqlTableModel*>(ui->tableViewGenre->model());
    if (!genreModel) {
        QMessageBox::critical(this, "Ошибка", "Не удалось получить модель данных жанров.");
        return;
    }

    int genreId = genreModel->data(genreModel->index(currentIndex.row(), genreModel->fieldIndex("genre_id"))).toInt();

    QSqlQuery query(QSqlDatabase::database("unique_connection_name"));
    query.prepare("INSERT INTO disks (title, release_year, genre_id, price, stock) VALUES (:title, :release_year, :genre_id, :price, :stock)");

    query.bindValue(":title", title);
    query.bindValue(":release_year", releaseYear);
    query.bindValue(":genre_id", genreId);
    query.bindValue(":price", price);
    query.bindValue(":stock", stock);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось добавить диск: " + query.lastError().text());
        return;
    }

    ui->titleEdit->clear();
    ui->releaseEdit->clear();
    ui->priceEdit->clear();
    ui->stockEdit->clear();

    QSqlTableModel *model = qobject_cast<QSqlTableModel*>(ui->tableViewDisks->model());
    if(model) {
        model->select();
    }

    QMessageBox::information(this, "Успешно", "Диск успешно добавлен.");
}



void MainWindow::on_addGenre_clicked()
{
    QString genreName = ui->genreEdit->text().trimmed();

    if (genreName.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Поле названия жанра не может быть пустым.");
        return;
    }

    QSqlQuery query(QSqlDatabase::database("unique_connection_name"));

    query.prepare("INSERT INTO genres (name) VALUES (:name)");
    query.bindValue(":name", genreName);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось добавить жанр: " + query.lastError().text());
        return;
    }

    ui->genreEdit->clear();

    QSqlTableModel *modelGenre = qobject_cast<QSqlTableModel*>(ui->tableViewGenre->model());
    if (modelGenre) {
        modelGenre->select();
    }

    QMessageBox::information(this, "Успешно", "Жанр успешно добавлен.");
}

void MainWindow::on_ownerButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->admin);

    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery query(QSqlDatabase::database("unique_connection_name"));
    query.prepare(R"(
        SELECT orders.order_id, users.name AS user_name, disks.title AS disk_title, orders.order_date, orders.return_date, orders.status
        FROM orders
        JOIN users ON orders.user_id = users.user_id
        JOIN disks ON orders.disk_id = disks.disk_id
    )");

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось выполнить запрос: " + query.lastError().text());
        return;
    }

    model->setQuery(query);

    ui->tableOrders->setModel(model);
    ui->tableOrders->hideColumn(model->record().indexOf("order_id"));
    ui->tableOrders->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableOrders->resizeColumnsToContents();
}



