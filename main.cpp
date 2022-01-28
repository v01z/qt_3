#include "mainwindow.h"
#include <QResource>
#include <QApplication>
#include <QFile>
#include <QMessageBox>

//const QString resFilePath {

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile resFile { "./resources.rcc" };
    if (!resFile.exists())
    {
        QMessageBox::warning(nullptr, "File not found", "Can't open resourses file.");
//        QMessageBox::warning(nullptr, "File not found",

        return -1;
    }

    //QResource::registerResource("./resources.rcc");
    QResource::registerResource("../qt_3/resources.rcc");
    MainWindow w;
    w.show();

    return a.exec();
}
