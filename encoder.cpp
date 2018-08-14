#include "encoder.h"

#include <QFile>
#include <QDebug>



Encoder::Encoder()
{
}

Encoder::~Encoder()
{

}

QString Encoder::encoderInput(const QString &input, const QVariantMap map)
{
    QString output;

    for (const auto &it : input.toLower()) {
        if (map.find(it) == map.end()) {
            output = QStringLiteral("INVALID INPUT");
            break;
        }
        output += map.value(it).toString();
    }

    return output;

}

QString Encoder::decoderInput(const QString &input, const QVariantMap map)
{
    QString output;
    bool matching = false;

    for (int i=0; i < input.length(); ++i) {
        matching = false;
        QString substring;

        while (!matching && i < input.length()) {
            substring += input[i];
            if (map.key(substring) != QString()) {
                matching = true;
                output += map.key(substring);
            }
            else ++i;
        }
    }
    if (matching) return output;
    return QString();

}
void Encoder::fileEncode(const QString &input, const QVariantMap map)
{
    QStringList filePathList = inputAndOutputFilePathValidator(input);
    if(filePathList.isEmpty()) {
        qDebug() << "ERROR input or output file path is not valid";
        return;
    }

    QString encodedContent;

    if (codeAndDecodeFromFile(filePathList.at(0), encodedContent, Mode::ENCODER, map) &&
        contentWriteOutIsOk(filePathList.at(1), encodedContent)) {
        qDebug() << "Successful file encode";
    }
}
void Encoder::fileDecode(const QString &input, const QVariantMap map)
{
    QStringList filePathList = inputAndOutputFilePathValidator(input);
    if(filePathList.isEmpty()) {
        qDebug() << "ERROR input or output file path is not valid";
        return;
    }

    QString decodedContent;

    if (codeAndDecodeFromFile(filePathList.at(0), decodedContent, Mode::DECODER, map) &&
        contentWriteOutIsOk(filePathList.at(1), decodedContent)) {
        qDebug() << "Successful file decode";
    }
}

bool Encoder::codeAndDecodeFromFile(const QString &path, QString &content, Mode mode, const QVariantMap map)
{
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QString line;
        if (mode == Mode::ENCODER) {
            while (stream.readLineInto(&line)) {
                content.append(encoderInput(line, map));
                content.append(QStringLiteral("\n"));
            }
        } else if (mode == Mode::DECODER){
            while (stream.readLineInto(&line)) {
                QString outputLine = decoderInput(line, map);
                if (!outputLine.isEmpty()) {
                    content.append(decoderInput(line, map));
                    content.append(QStringLiteral("\n"));
                } else {
                    qDebug() << "INVALID character";
                    break;
                }
            }
        }

        file.close();
        return true;
    } else {
        qDebug() << "INVALID INPUT FILE";
        return false;
    }
}

bool Encoder::contentWriteOutIsOk(const QString &outputFilePath, const QString &content)
{
    QFile outputFile(outputFilePath);
    if (outputFile.open(QFile::WriteOnly)) {
        QTextStream out(&outputFile);
        out << content;
        outputFile.close();
        return true;
    } else {
        qDebug() << "COULD NOT OPEN OUTPUT FILE";
        return false;
    }
}

QStringList Encoder::inputAndOutputFilePathValidator(const QString &inputAndOutputPathString)
{
    QStringList filePathList = inputAndOutputPathString.split(" ", QString::SkipEmptyParts);

    if (filePathList.size() == 2 &&
        QFile::exists(filePathList.at(0)) &&
        QFile::exists(filePathList.at(1)))
    {
        return filePathList;
    } else {
        return QStringList();
    }
}
