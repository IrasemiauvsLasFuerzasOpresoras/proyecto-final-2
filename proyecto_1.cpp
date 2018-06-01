#include "proyecto_1.h"
#include "ui_proyecto_1.h"

proyecto_1::proyecto_1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::proyecto_1)
{
    ui->setupUi(this);
}

proyecto_1::~proyecto_1()
{
    delete ui;
}

void proyecto_1::on_pushButton_clicked()
{

}
