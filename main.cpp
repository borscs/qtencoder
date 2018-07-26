#include <QCoreApplication>
#include <stdlib.h>
#include <iostream>
#include <istream>
#include <ostream>
#include <QtDebug>
#include "jsonreading.h"

using namespace std;

int main()
{
   JsonReading *jsonreading = new JsonReading();
   jsonreading->setMapNormal(jsonreading->loadJson(jsonreading->jsonRead()));
   qDebug()  << QJsonDocument::fromVariant(jsonreading->getMapNormal()).toJson(QJsonDocument::Compact);
   jsonreading->backMesseg("a");

   delete  jsonreading;
   return 0;
}
