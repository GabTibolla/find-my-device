#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = new database();
    connect(db, &database::sent, this, &MainWindow::setValue);
    db->get();

}

MainWindow::~MainWindow()
{
    delete db;
    delete ui;
}

void MainWindow::setValue(QString str)
{
   ui->lineEdit->setText(str);
   ui->webView->load(QUrl(str));
}
