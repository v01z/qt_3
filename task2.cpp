#include "task2.h"
#include "ui_task2.h"
#include "webinfo.h"

Task2::Task2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task2)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Choose host");
    ui->comboBox->addItem(hostConvArr[0].hostName);
    ui->comboBox->addItem(hostConvArr[1].hostName);

    ui->textEdit->setText("Here will be info when you " \
        "click on combobox");

}

Task2::~Task2()
{
    delete ui;
}

// https://trk.mail.ru/c/qtcyh9

// https://pogoda.mail.ru/


//https://news.mail.ru/currency/src/MOEX/charcode/USD/

void Task2::on_btnClose_clicked()
{
   close();
}


void Task2::on_comboBox_activated(const QString &arg1)
{
   WebInfo *webInfo = new WebInfo(ui->comboBox->currentText());
   ui->textEdit->setText(webInfo->getWeather());
   delete webInfo;

}

