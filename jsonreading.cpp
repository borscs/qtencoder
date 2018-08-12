#include "jsonreading.h"

#include <QJsonDocument>
#include <QException>
#include <QDebug>
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>


JsonReading::JsonReading()
{
}

JsonReading::~JsonReading()
{

}

QVariantMap JsonReading::getMapNormal() const
{
    return mapNormal;
}

void JsonReading::setMapNormal(const QVariantMap &value)   ///setmapss elnevezés
{
    mapNormal = value;
    swichMap();
}

QVariantMap JsonReading::loadJson(const QString &path)
{
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw QStringLiteral("Could not open file");
    }
    QByteArray input = file.readAll();
    file.close();

    QJsonParseError error = {};
    QJsonDocument document = QJsonDocument::fromJson(input, &error);

    if (error.error != QJsonParseError::NoError) {
        throw error.errorString();
    }

    return  document.toVariant().toMap();
}

QString JsonReading::jsonRead() // This should be in the menu handler class
{
    qDebug()<<"pleas json file: "<<endl;
    QTextStream qtin(stdin);
    QString path = qtin.readLine();
    return path;
}


QVariantMap JsonReading::getMapRevers() const
{
    return mapRevers;
}

void JsonReading::setMapRevers(const QVariantMap &value)
{
    mapRevers = value;
}

void JsonReading::swichMap()   //osztály változo használat, műs név swich to revers ...., for()
{

    QVariantMap *insertMap = new QVariantMap();

    foreach(const QString& key, getMapNormal().keys())
    {
        QVariant jsonValue = getMapNormal().value(key);
        insertMap->insert(jsonValue.toString(),key);
    }
    //qDebug() << "swapped";
    try
    {
        setMapRevers(*insertMap);
    }
    catch (QException &exception)
    {
        qDebug() << exception.what();
    }

    delete insertMap;

}

