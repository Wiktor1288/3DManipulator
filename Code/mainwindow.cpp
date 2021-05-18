#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myConnection =new Connection(this);
    myWykresy =new Wykresy(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionPo_czenie_triggered()
{

        myConnection->setModal(false);
        myConnection->show();
        myConnection->activateWindow();


}

void MainWindow::on_SendConf_clicked()
{
    int joint1,joint2,joint3;
    joint1=ui->Przeg11->cleanText().toInt();
    joint2=ui->Przeg22->cleanText().toInt();
    joint3=ui->Przeg33->cleanText().toInt();

    myConnection->SendConfiguration(joint1,joint2,joint3);
}

void MainWindow::on_actionWykresy_triggered()
{
    myWykresy->setModal(false);
    myWykresy->show();
    myConnection->activateWindow();
}
