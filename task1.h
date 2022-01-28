#ifndef TASK1_H
#define TASK1_H

#include <QMainWindow>

namespace Ui {
class Task1;
}

class Task1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Task1(QWidget *parent = nullptr);
    ~Task1();

private:
    Ui::Task1 *ui;
};

#endif // TASK1_H
