#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <vector>
#include "building.h"

class FileManager
{
public:
    FileManager();

    static std::vector<Building> loadXml();
};

#endif // FILEMANAGER_H
