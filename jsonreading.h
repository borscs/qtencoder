#pragma once

#include <QString>
#include <QVariantMap>

using namespace std;

class JsonReading
{
public:
    JsonReading();
    ~JsonReading();

    QVariantMap getMapNormal() const;
    QVariantMap getMapRevers() const;
    QVariantMap loadJson(const QString &path);
    void setMaps(const QVariantMap &value);
private:
      void reverMap();
      void setMapRevers(const QVariantMap &value);
protected:
    QVariantMap mapNormal;
    QVariantMap mapRevers;

};
