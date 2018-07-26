#include "jsonreading.h"
#include <QJsonDocument>
#include <QMap>

QVariantMap JsonReading::getMapNormal() const
{
    return mapNormal;
}

void JsonReading::setMapNormal(const QVariantMap &value)
{
    mapNormal = value;
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

    QVariant assist = document.toVariant();
    return assist.toMap();
}

QString JsonReading::jsonRead()
{
    cout<<"pleas json file: "<<endl;
    std::string str;
    std::getline(std::cin, str);
    QString path(str.c_str());

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

void JsonReading::reversToMap()
{
    QVariant assist;
    QString value;
    QVariant key;
    for(auto it=mapNormal.begin();it!=mapNormal.end();it++)
    {
        value=it.value().toString();
        key = it.key();
    }
}

JsonReading::JsonReading()
{
    
}

JsonReading::~JsonReading()
{
    
}

QString JsonReading::backMesseg(const QString &keys)
{
    QVariantMap map=getMapNormal();
    QString value;
    for(auto it=map.begin();it!=map.end();it++)
    {
        if(keys==it.key())
        {
            value = it.value().toString();
        }
    }
    return value;

}
