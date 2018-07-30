#ifndef ENCODER_H
#define ENCODER_H
#include "jsonreading.h"
#include <QString>
#include <string>
#include <QVariantMap>
class Encoder : JsonReading
{
public:
    Encoder();

    void encoderIt(const QString inpu, QVariantMap map);
};

#endif // ENCODER_H
