#include <QCoreApplication>
#include <QtDebug>
#include <QJsonDocument>

#include "menu.h"
#include "jsonreading.h"
#include "encoder.h"
#include "fileencode.h"

using namespace std;

int main()
{
    QTextStream qtin(stdin);   //javaslat input
    JsonReading *jsonreading = new JsonReading();
    Encoder *encoder = new Encoder();
    FileEncode *fileencoder = new FileEncode();
    Menu *menu= new Menu();
    bool boool;

    do{
        try {
            jsonreading->setMapNormal(jsonreading->loadJson(jsonreading->jsonRead()));
            boool=false;
        } catch (QString erros) {
            qDebug() <<erros;
            boool=true;
        }
    }while(boool);
    ///setdict, setreversdict
    //    qDebug()  << QJsonDocument::fromVariant(jsonreading->getMapRevers()).toJson(QJsonDocument::Compact);

    QString input;

    boool = true;
    menu->help();
    do{
        qDebug() << "what would you like to make?";
        qtin >> input;
        input = input.toLower();
        if(input == "encode")
        {
            qDebug() << "In Ecoder: "<<endl;
            qDebug() << "pls the input: ";
            qtin >> input;
            //input = encoder->toLower(input);
            qDebug() << encoder->encoderInput(input, jsonreading->getMapNormal()); // rename this func to encode

        }else if (input == "decode") {
            qDebug() <<"In Decode: "<<endl;
            qDebug() << "pls the input: ";
            qtin>> input;
            input = input.toLower();
            qDebug() << encoder->reversEncoderInput(input, jsonreading->getMapRevers()); // rename this func to decode

        }else if(input == "encodefile"){
            qDebug()<<"In Encode File"<<endl;
            qDebug() << "pils the file name: ";
            qtin>> input;
            input = input.toLower();
            qDebug() << encoder->encoderInput(fileencoder->readFile(input), jsonreading->getMapNormal());

        }else if(input == "decodefile"){
            qDebug() << "In Decode File: "<<endl;
            qDebug() << "pils the file name: ";
            qtin>> input;
            //input = encoder->toLower(input);
            qDebug() << encoder->reversEncoderInput(fileencoder->readFile(input), jsonreading->getMapRevers());

        }else if(input == "exit"){

            boool=false;
        }else if(input == "help"){

            menu->help();
        }

    }while(boool);


    //    qDebug() << encoder->encoderInput(input, jsonreading->getMapNormal());   // remove it
    //    qDebug() << encoder->reversEncoderInput(input, jsonreading->getMapRevers());
    //    //qDebug()  << QJsonDocument::fromVariant(jsonreading->getMapRevers()).toJson(QJsonDocument::Compact);

    delete  menu;  // use std::unique_ptr instead of raw pointer https://en.cppreference.com/w/cpp/memory/unique_ptr
    delete  fileencoder;
    delete  encoder;
    delete  jsonreading;
    return 0;
}
