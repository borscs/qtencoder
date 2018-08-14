#pragma once

#include "jsonreading.h"

#include <QVariantMap>

class Encoder
{
    enum class Mode { ENCODER, DECODER };
public:
    Encoder();
    ~Encoder();

   QString encoderInput(const QString &input, const QVariantMap map);
   QString decoderInput(const QString &input, const QVariantMap map);
   void fileEncode (const QString &input, const QVariantMap map);
   void fileDecode (const QString &input, const QVariantMap map);

protected:
   bool codeAndDecodeFromFile(const QString &path, QString &content, Mode mode, const QVariantMap map);
   bool contentWriteOutIsOk(const QString &outputFilePath, const QString &content);
   QStringList inputAndOutputFilePathValidator(const QString &inputAndOutputPathString);

};

