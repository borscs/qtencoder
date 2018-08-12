#pragma once


#include <QString>
#include <QVariantMap>

using namespace std;

class JsonReading
{  // please set private those functions which are only called from the class
public:
    JsonReading();
    ~JsonReading();
    QVariantMap getMapNormal() const;
    void setMapNormal(const QVariantMap &value);
    QVariantMap getMapRevers() const;
    void setMapRevers(const QVariantMap &value);

    QString jsonRead();
    void backMesseg(const QString &keys);
    QVariantMap loadJson(const QString &path);

protected:
    void swichMap();

private:
    QVariantMap mapNormal;
    QVariantMap mapRevers;
 
};
