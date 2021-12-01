#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QString>
#include "mainwindow.h"

class database : public QObject
{
    Q_OBJECT
public:
    explicit database(QObject *parent = nullptr);
    ~database();
    double latitude = 0, longitude;
    QString conversion(double &var);
    QString conversion1(double &var);
    QString str;

private:
    QNetworkAccessManager *m_manager;
    QNetworkReply *loc;

public slots:
    QString readready();
};

#endif // DATABASE_H



