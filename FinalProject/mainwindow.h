#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    database *db;
    QTimer *timer;

private:
    Ui::MainWindow *ui;
    QString verify;

private slots:
    void writeWindow();
    void readWindow();
    void closeEvent(QCloseEvent *event);

public slots:
    void setValue();
    void aux();

};
#endif // MAINWINDOW_H
