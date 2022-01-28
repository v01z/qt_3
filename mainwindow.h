#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "task1.h"

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
    void on_btnTask1_clicked();

    void on_btnTask2_clicked();

    void on_btnExit_clicked();

private:
    Ui::MainWindow *ui;
    Task1 secondWindow;
};
#endif // MAINWINDOW_H
