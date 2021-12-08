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

    // Conectando a classe database à MainWindow, passando os dados
    db = new database();
    connect(db, &database::sent, this, &MainWindow::setValue);
    db->get();

    // Temporizador, atualizando de 10 em 10 segundos
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::aux);
    timer->start(10000);
}

MainWindow::~MainWindow()
{
    delete timer;
    delete db;
    delete ui;
}

void MainWindow::setValue()
{
    // Exibindo dados no webview e no line edit
    ui->lineEdit->setText(db->str);
    ui->webView->load(QUrl(db->str));
}


void MainWindow::aux() // Slot auxiliar, para conectar o timer e a exibição atualizada
{
    db->get();
}
