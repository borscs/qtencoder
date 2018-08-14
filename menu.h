#pragma once

#include "menu.h"
#include "jsonreading.h"
#include "encoder.h"
#include "fileencode.h"

#include <QString>


class Menu
{
public:
    Menu();
    void start();
private:
    QString jsonRead();
    void mainMenu(const JsonReading &maps);
    QString userInput();
    void help();
};

