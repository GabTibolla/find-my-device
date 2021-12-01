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
    void constructor();

private:
    QNetworkAccessManager *m_manager;
    QNetworkReply *loc;
    QString conversion(double &var);
    QString conversion1(double &var);
    double latitude, longitude;

public slots:
    void readready();

signals:
    void send(QString tr);
};

#endif // DATABASE_H



