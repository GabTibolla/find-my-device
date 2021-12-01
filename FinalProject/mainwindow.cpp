#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    database *url = new database(this);
    db = url->constructor(); // erro
    connect(db, &database::sent, this, &MainWindow::setValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setValue()
{
    ui->webView->load(QUrl(db->str));
    ui->lineEdit->setText(db->str);
}
