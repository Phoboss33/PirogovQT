#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_goUserButton_clicked();

    void on_goWorkerButton_clicked();

    void on_goAdminButton_clicked();

    void on_returnToMain_clicked();
    void on_returnToMain_2_clicked();
    void on_returnToMain_3_clicked();


    void on_buyButton_clicked();

    void on_addDisk_clicked();

    void on_addGenre_clicked();

    void on_ownerButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
};
#endif // MAINWINDOW_H
