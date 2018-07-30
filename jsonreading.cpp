#include "jsonreading.h"
#include <QJsonDocument>
#include <QMap>
#include <QException>

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
    QVariantMap helperMap = getMapNormal();
    QVariantMap *insertMap = new QVariantMap();

    foreach(const QString& key, helperMap.keys())
    {
        QVariant jsonValue = helperMap.value(key);
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

JsonReading::JsonReading()
{
    
}

JsonReading::~JsonReading()
{
    
}

void JsonReading::backMesseg(const QString &keys)
{
    QVariantMap map=getMapNormal();
    QString value;
    for(qint32 i=0;i<keys.length();i++)
    {
        for(auto it=map.begin();it!=map.end();it++)
         {
            if(keys[i]==it.key())
            {
                value += it.value().toString();
            }
        }
    }
    qDebug() << value;

}
