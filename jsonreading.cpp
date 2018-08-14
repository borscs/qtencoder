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

void JsonReading::setMaps(const QVariantMap &value)
{
    mapNormal = value;
    reverMap();
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



QVariantMap JsonReading::getMapRevers() const
{
    return mapRevers;
}

void JsonReading::setMapRevers(const QVariantMap &value)
{
    mapRevers = value;
}

void JsonReading::reverMap(){

    QVariantMap *insertMap = new QVariantMap();

    foreach(const QString& key, getMapNormal().keys())
    {
        QVariant jsonValue = getMapNormal().value(key);
        insertMap->insert(jsonValue.toString(),key);
    }
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

