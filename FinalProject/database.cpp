#include "database.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QDebug>
#include <QJsonObject>
#include "mainwindow.h"

database::database(QObject *parent) : QObject(parent)
{
    m_manager = new QNetworkAccessManager(this);

    loc = m_manager->get(QNetworkRequest(QUrl("https://projeto-final-cdfea-default-rtdb.firebaseio.com/localizacao.json")));
    connect(loc, &QNetworkReply::readyRead, this, &database::readready);
}

database::~database()
{
    delete m_manager;
}

QString database::readready()
{
    auto json = QJsonDocument::fromJson(loc->readAll());
    auto obj= json.object();
    latitude = obj["Latitude"].toDouble();
    longitude = obj["Longitude"].toDouble();
}

QString database::conversion(double &var)
{
    int a = var;
    float aux = ((var - a) * 60);
    int b = aux;

    float aux1 = 0.0;

    if (b <= 0){
        b = b+(-b+(-b));

        aux1 = aux + b;
    }
    else if (b > 0)
        aux1 = aux - b;

    float aux2 = aux1*60;

    if (aux2 <= 0)
        aux2 = aux2+(-aux2+(-aux2));

    QString w;

    if (a < 0){
        w = "S";
        a = a+(-a+(-a));
    }
    else
        w = "N";
    QString value (QString::number(a) + "º" + QString::number(b) + "'" + QString::number(aux2) + "''" + w + " ");
    return value;
}

QString database::conversion1(double &var)
{
    int a = var;
    float aux = ((var - a) * 60);
    int b = aux;

    float aux1 = 0.0;

    if (b <= 0){
        b = b+(-b+(-b));

        aux1 = aux + b;
    }
    else if (b > 0)
        aux1 = aux - b;

     float aux2 = aux1*60;

     if (aux2 <= 0)
         aux2 = aux2+(-aux2+(-aux2));

     QString w;
     if (a < 0){
         w = "W";
         a = a+(-a+(-a));
     }
     else
         w = "E";
     QString value = (QString::number(a) + "º" + QString::number(b) + "'" + QString::number(aux2) + "''" + w);
     return value;
}

