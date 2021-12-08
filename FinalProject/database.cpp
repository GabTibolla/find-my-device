#include "database.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QDebug>
#include <QJsonObject>
#include "mainwindow.h"

database::database(QObject *parent) : QObject(parent)
{
    m_manager = new QNetworkAccessManager(this);
}

database::~database()
{
    delete m_manager;
}

void database::get(){ // função para realizar a requisição no firebase, puxando os dados salvos
    loc = m_manager->get(QNetworkRequest(QUrl("https://projeto-final-cdfea-default-rtdb.firebaseio.com/localizacao.json")));
    connect(loc, &QNetworkReply::readyRead, this, &database::readready);  // Conectando os dados puxados para realizar a conversão
}

void database::readready()
{
    auto json = QJsonDocument::fromJson(loc->readAll()); //Lendo todos os arquivos do firebase em formato .json
    auto obj= json.object(); // Transformando os dados .json em object
    latitude = obj["Latitude"].toDouble(); // Convertendo latitude para double
    longitude = obj["Longitude"].toDouble(); // Convertendo Longitude para double
    str = ("https://www.google.com/maps/place/" + conversionLatitude(latitude) + conversionLongitude(longitude)); // Criando a URL
    emit sent(); // Emitindo sinal para conexão na mainWindow
}

QString database::conversionLatitude(double &var) // Convertendo latitude em ângulos para exibir no maps
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

QString database::conversionLongitude(double &var) // Convertendo Longitude em ângulos para exibir no maps
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
