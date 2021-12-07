#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include <QString>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = new database();
    timer = new QTimer(this);
    database *aux = new database(this);

    connect(db, &database::sent, this, &MainWindow::setValue);
    connect(timer, &QTimer::timeout, aux, &database::call);
    timer->start(10000);
    db->get();

}

MainWindow::~MainWindow()
{
    delete db;
    delete ui;
    delete timer;
}

void MainWindow::setValue(QString str)
{
    qDebug() << "+10 segundos";
    ui->lineEdit->setText(str);
    ui->webView->load(QUrl(str));
}
