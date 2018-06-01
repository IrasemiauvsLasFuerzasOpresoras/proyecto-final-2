#ifndef PROYECTO_1_H
#define PROYECTO_1_H

#include <QMainWindow>

namespace Ui {
class proyecto_1;
}

class proyecto_1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit proyecto_1(QWidget *parent = 0);
    ~proyecto_1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::proyecto_1 *ui;
};

#endif // PROYECTO_1_H
