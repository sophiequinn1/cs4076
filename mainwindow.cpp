#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap logo("C:/Users/sophi/Downloads/LM121/2ND YEAR/2ND SEMESTER/CS4076/project/logo.png");
    ui->logo_label->setPixmap(logo);
    ui->logo_label_2->setPixmap(logo);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_start_button_clicked()
{

}


void MainWindow::on_yes_checkbox_stateChanged(int arg1)
{

}

