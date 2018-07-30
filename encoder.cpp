#include "encoder.h"

Encoder::Encoder()
{

}

void Encoder::encoderIt(const QString inpu, QVariantMap map)
{
    QString value;
    for(auto it=map.begin();it!=map.end();it++)
    {
        if(inpu==it.key())
        {
            value = it.value().toString();
        }
    }

    qDebug() << value;

}
