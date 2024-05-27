#ifndef SECONDMAINWINDOW_H
#define SECONDMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SecondMainWindow; }
QT_END_NAMESPACE

class SecondMainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit SecondMainWindow(QWidget *parent = nullptr);
    ~SecondMainWindow();

private:
    Ui::SecondMainWindow *ui;
};

#endif // SECONDMAINWINDOW_H
