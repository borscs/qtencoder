#include <QtDebug>

#include "menu.h"

Menu::Menu()
{

}

void Menu::help()
{
    qDebug()  << "Welcome! What would you like to make?";
    qDebug() << "ENCODE <text>: Encodes a given string based on a JSON Dictionary";
    qDebug() << "DECODE <text>: Decodes an encoded string using a JSON Dictionary";
    qDebug() << "ENCODEFILE <file-to-encode> <output-file>: Reads a text file and then encodes it into a second file";
    qDebug() << "DECODEFILE <encoded-file> <output-file>: Reads an encded text file then decodes it int a second file";
    qDebug() << "EXIT: Terminates the program";

}
