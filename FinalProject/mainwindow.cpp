#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include <QString>
#include <QObject>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiver(QString stra)
{
    frase = stra;
}
