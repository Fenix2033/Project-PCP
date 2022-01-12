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

class FileManager
{
public:
    FileManager();

    static std::vector<int> loadXml();
    static void writeXml(int index, int buildingN);
    static std::vector<Building> getBuildings();
    static void newGame();
};

#endif // FILEMANAGER_H
