#include "encoder.h"

Encoder::Encoder()
{

}

Encoder::~Encoder()
{

}

QString Encoder::encoderInput(const QString &input, const QVariantMap& map) // fix the unhandeled letter bug
{

    // qDebug()  << QJsonDocument::fromVariant(map).toJson(QJsonDocument::Compact);
    QString value;
    for(auto i=0;i<input.length();i++) // proba range based for for(auto it : input)
    {
        for(auto it=map.begin();it!=map.end();it++)
        {
            if(input[i]==it.key())
            {
                value += it.value().toString();
            }
        }
    }
    // qDebug() << value;

    return value;

}

QString Encoder::reversEncoderInput(const QString &input, const QVariantMap &map) // fix the unhandeled letter bug check the description
{
    QString value;
    QString helper="";
    for(auto i=0;i<input.length();i++) // proba range based for for(auto it : input)
    {
        helper+=input[i];
        for(auto it=map.begin();it!=map.end();it++)
        {
            if(helper==it.key())
            {
                value += it.value().toString();
                helper="";
            }
        }
    }
    // qDebug() << value;

    return value;
}

//QString Encoder::toLower(const QString input)
//{
//    QString copy = input;
//    transform(copy.begin(), copy.end(), copy.begin(),
//                       [](unsigned char c){ return std::tolower(
//                       c); });

//    return copy;
//}
