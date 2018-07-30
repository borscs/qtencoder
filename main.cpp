#include <QCoreApplication>
#include <stdlib.h>
#include <iostream>
#include <istream>
#include <ostream>
#include <QtDebug>
#include "jsonreading.h"
#include "encoder.h"
using namespace std;

int main()
{
   QTextStream qtin(stdin);
   JsonReading *jsonreading = new JsonReading();
   jsonreading->setMapNormal(jsonreading->loadJson(jsonreading->jsonRead()));
  //qDebug()  << QJsonDocument::fromVariant(jsonreading->getMapNormal()).toJson(QJsonDocument::Compact);
   Encoder *encoder = new Encoder();
   QString input;
   qtin >> input;
  //qDebug() << encoder->encoderIt(input);
  jsonreading->backMesseg(input);
  // jsonreading->reversToMap();
   //qDebug()  << QJsonDocument::fromVariant(jsonreading->getMapRevers()).toJson(QJsonDocument::Compact);
   encoder->encoderIt(input, jsonreading->getMapNormal());
   delete  jsonreading;
   return 0;
}
