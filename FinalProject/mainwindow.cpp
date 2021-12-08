#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include <QString>
#include <QTimer>
#include <QSettings>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readWindow();
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

    if (verify != db->str){  // Verifica se a string mudou, caso sim, exibe no webview
        verify = db->str;
        ui->lineEdit->setText(db->str);
        ui->webView->load(QUrl(db->str));
    }
}


void MainWindow::aux() // Slot auxiliar, para conectar o timer e a exibição atualizada
{
    db->get();
}


void MainWindow::readWindow(){  // Lê o tamanho e a posição da janela na última execução
    QSettings set;

    this->move(set.value("position", QPoint(0, 0)).toPoint());
    this->resize(set.value("size", QSize(600, 400)).toSize());

    if (set.value("maximized", false).toBool())
        this->showMaximized();
}

void MainWindow::writeWindow(){  // Grava o tamanho e a posição da janela
    QSettings set;

    set.setValue("position", this->pos());
    if (this->isMaximized()){
        set.setValue("maximized", true);
        set.remove("size");
        set.remove("position");
    }
    else {
        set.setValue("size", this->size());
        set.remove("maximized");
    }
}

void MainWindow::closeEvent(QCloseEvent *event){ // Aguarda para gravar as informações
    writeWindow();
}
