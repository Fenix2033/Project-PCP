#ifndef FILEMANAGER_H
#define FILEMANAGER_H


#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <QXmlStreamWriter>
#include <vector>
#include <array>
#include "game.h"
#include "building.h"
#include "player.h"

class FileManager
{
public:
    FileManager();

    static std::vector<Building> loadBuildings();
    static Player loadPlayer();
    static void writeBuildings(int index, int buildingN);
    static void writePlayer(int index, int price);

    static void newGame();

};


#endif // FILEMANAGER_H
