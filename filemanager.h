#ifndef FILEMANAGER_H
#define FILEMANAGER_H


#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <vector>
#include "game.h"

class FileManager
{
public:
    FileManager();

    static std::vector<int> loadXml();
    static std::vector<int> writeXml();
};

#endif // FILEMANAGER_H
