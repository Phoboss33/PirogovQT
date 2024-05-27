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

    connect(ui->goUserButton, &QPushButton::clicked, this, &MainWindow::on_goUserButton_clicked);
    connect(ui->buyButton, &QPushButton::clicked, this, &MainWindow::on_buyButton_clicked);
    connect(ui->addDisk, &QPushButton::clicked, this, &MainWindow::on_addDisk_clicked);
    connect(ui->addGenre, &QPushButton::clicked, this, &MainWindow::on_addGenre_clicked);
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

    QSqlQuery query(QSqlDatabase::database("unique_connection_name"));
    query.prepare("SELECT * FROM disks;");

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось выполнить запрос: " + query.lastError().text());
        return;
    }

    QSqlTableModel *model = new QSqlTableModel(this, QSqlDatabase::database("unique_connection_name"));
    model->setTable("disks");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(model->fieldIndex("disk_id")); // Скрываем колонку disk_id
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // Запрещаем редактирование таблицы
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
    model->select();



    ui->tableViewDisks->setModel(model);
    ui->tableViewDisks->hideColumn(model->fieldIndex("disk_id")); // Скрываем колонку disk_id
    ui->tableViewDisks->setEditTriggers(QAbstractItemView::NoEditTriggers); // Запрещаем редактирование таблицы
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
    ui->tableViewGenre->hideColumn(modelGenre->fieldIndex("genre_id")); // Скрываем колонку disk_id
    ui->tableViewGenre->setEditTriggers(QAbstractItemView::NoEditTriggers); // Запрещаем редактирование таблицы
    ui->tableViewGenre->resizeColumnsToContents();
}


void MainWindow::on_goAdminButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->admin);
}



// User Page

void MainWindow::on_buyButton_clicked()
{
    // Получаем текущий выбранный элемент
    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите диск для покупки.");
        return;
    }

    // Получаем идентификатор выбранного элемента
    int row = currentIndex.row();
    QSqlTableModel *model = qobject_cast<QSqlTableModel*>(ui->tableView->model());
    if (!model) {
        QMessageBox::critical(this, "Ошибка", "Не удалось получить модель данных.");
        return;
    }

    int diskId = model->data(model->index(row, model->fieldIndex("disk_id"))).toInt();

    // Выполняем SQL-запрос для удаления элемента из базы данных
    QSqlQuery query(QSqlDatabase::database("unique_connection_name"));
    query.prepare("DELETE FROM disks WHERE disk_id = :disk_id");
    query.bindValue(":disk_id", diskId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось купить диск: " + query.lastError().text());
        return;
    }

    // Обновляем модель таблицы, чтобы отобразить изменения
    model->select();
    QMessageBox::information(this, "Успешно", "Диск успешно куплен!.");
}

// Worker Page



void MainWindow::on_addDisk_clicked()
{
    QString title = ui->titleEdit->text();
    int releaseYear = ui->releaseEdit->text().toInt();
    int genreId = ui->genreIdEdit->text().toInt();
    double price = ui->priceEdit->text().toDouble();
    int stock = ui->stockEdit->text().toInt();

    if (title.isEmpty() || ui->releaseEdit->text().isEmpty() || ui->genreIdEdit->text().isEmpty() || ui->priceEdit->text().isEmpty() || ui->stockEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Все поля должны быть заполнены.");
        return;
    }

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

    // Очищаем поля после добавления
    ui->titleEdit->clear();
    ui->releaseEdit->clear();
    ui->genreIdEdit->clear();
    ui->priceEdit->clear();
    ui->stockEdit->clear();

    // Обновляем tableViewDisks
    QSqlTableModel *model = qobject_cast<QSqlTableModel*>(ui->tableViewDisks->model());
    if(model) {
        model->select();
    }

    QMessageBox::information(this, "Успешно", "Диск успешно добавлен.");
}


void MainWindow::on_addGenre_clicked()
{
    QString genreName = ui->genreEdit->text().trimmed();

    // Проверяем, не пусто ли поле ввода для названия жанра
    if (genreName.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Поле названия жанра не может быть пустым.");
        return;
    }

    QSqlQuery query(QSqlDatabase::database("unique_connection_name"));
    // Подготавливаем запрос для вставки нового жанра
    query.prepare("INSERT INTO genres (name) VALUES (:name)");
    query.bindValue(":name", genreName);

    // Пытаемся выполнить запрос на добавление жанра
    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось добавить жанр: " + query.lastError().text());
        return;
    }

    // Очищаем поле ввода для названия жанра после добавления
    ui->genreEdit->clear();

    // Обновляем модель данных таблицы жанров
    QSqlTableModel *modelGenre = qobject_cast<QSqlTableModel*>(ui->tableViewGenre->model());
    if (modelGenre) {
        modelGenre->select();
    }

    QMessageBox::information(this, "Успешно", "Жанр успешно добавлен.");
}
