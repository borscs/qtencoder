#pragma once

#include "jsonreading.h"

#include <QVariantMap>

class Encoder
{
public:
    Encoder();
    ~Encoder();

   QString encoderInput(const QString &input,const QVariantMap &map);
   QString reversEncoderInput(const QString &input,const  QVariantMap &map);
//   QString toLower(const QString input);
};

