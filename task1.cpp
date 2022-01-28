#include "task1.h"
#include "ui_task1.h"

Task1::Task1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Task1)
{
    ui->setupUi(this);
}

Task1::~Task1()
{
    delete ui;
}
