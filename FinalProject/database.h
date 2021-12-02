#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QString>
#include <QMainWindow>

class database : public QObject
{
    Q_OBJECT
public:
    explicit database(QObject *parent = nullptr);
    ~database();
    QString constructor();
    QString str;

private:
    QNetworkAccessManager *m_manager;
    QNetworkReply *loc;
    QString conversionLatitude(double &var);
    QString conversionLongitude(double &var);
    double latitude, longitude;
    void get();

public slots:
    void readready();

signals:
    void sent(QString value);
};

#endif // DATABASE_H



