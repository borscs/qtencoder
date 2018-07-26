#ifndef JSON_H
#define JSON_H
#include <QVariant>
#include <QString>
#include <stdlib.h>
#include <iostream>
#include <QFile>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <ostream>
#include <QtDebug>
#include <QMap>

using namespace std;

class JsonReading
{
    QVariantMap mapNormal;
    QVariantMap mapRevers;
public:
    JsonReading();
    ~JsonReading();
    QVariantMap getMapNormal() const;
    void setMapNormal(const QVariantMap &value);
    QVariantMap getMapRevers() const;
    void setMapRevers(const QVariantMap &value);
    
    void reversToMap();
    QString jsonRead();
    QString backMesseg(const QString &keys);
    QVariantMap loadJson(const QString &path);

 
};

#endif // JSON_H
