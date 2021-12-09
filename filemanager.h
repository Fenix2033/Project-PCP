#ifndef FILEMANAGER_H
#define FILEMANAGER_H


#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <QXmlStreamWriter>
#include <vector>
#include "game.h"

class FileManager
{
public:
    FileManager();

    static std::vector<int> loadXml();
    static void writeXml();
};

#endif // FILEMANAGER_H
