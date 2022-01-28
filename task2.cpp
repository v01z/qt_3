#include "task2.h"
#include "ui_task2.h"

Task2::Task2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task2)
{
    ui->setupUi(this);
}

Task2::~Task2()
{
    delete ui;
}
