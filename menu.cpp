#include <QTextStream>
#include <QDebug>
#include <QFile>

#include "menu.h"

Menu::Menu()
{

}



void Menu::start() {
    JsonReading maps;
    maps.setMaps(maps.loadJson(jsonRead()));
    mainMenu(maps);

}

QString Menu::jsonRead()
{
    QTextStream qtin(stdin);
    qDebug()<<"pleas json file: "<<endl;
    QString path = qtin.readLine();
    return path;
}

void Menu::mainMenu(const JsonReading &maps)
{
    QString option;
    Encoder encoder;

    do{
        QString inputFromUser =  userInput();
        int offset;

        if (inputFromUser.startsWith("encode:")) {
            offset = (QString("encode: ")).size();
            qDebug() << encoder.encoderInput(inputFromUser.mid(offset), maps.getMapNormal());
        } else if (inputFromUser.startsWith("decode: ")) {
            offset = QString("decode: ").size();
            QString output = encoder.decoderInput(inputFromUser.mid(offset), maps.getMapRevers());
            output.isEmpty() ? qDebug() << "INVALID character" : qDebug() << output;
        } else if (inputFromUser.startsWith("encode_file")) {
            offset = QString("encode_file: ").size();
            encoder.fileEncode(inputFromUser.mid(offset),maps.getMapNormal());
        } else if (inputFromUser.startsWith("decode_file:")) {
            offset = QString("decode_file: ").size();
            encoder.fileDecode(inputFromUser.mid(offset), maps.getMapRevers());
        } else if (inputFromUser.startsWith("help")) {
            help();
        } else if (inputFromUser.startsWith("exit")) {
            qDebug() << "KTHXBYE";
            return;
        } else {
            qDebug() << "Please add a proper command";
        }
    } while(option != QStringLiteral("EXIT"));
}



QString Menu::userInput()
{
    QTextStream stream(stdin);
    QString output;
    stream.readLineInto(&output);

    return output.toLower();
}

void Menu::help()
{
    qDebug() << "------THIS IS THE HELP------";
    qDebug() << "Command: 'ENCODE:<Text you would like to encode>'";
    qDebug() << "Command: 'DECODE:<Text you would like to decode>'";
    qDebug() << "Command: 'ENCODE_FILE:<absolute path to the INPUT you would like to encode> <absolute path to the encoded OUTPUT>'";
    qDebug() << "Command: 'DECODE_FILE:<absolute path to the INPUT you would like to decode> <absolute path to the decoded OUTPUT>'";
    qDebug() << "Command: 'EXIT' to exit from the programme";
}
