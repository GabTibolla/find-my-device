#include "mainwindow.h"
#include <QApplication>
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("find-my-device");
    a.setOrganizationName("UPF");

    MainWindow w;
    w.show();
    return a.exec();
}
