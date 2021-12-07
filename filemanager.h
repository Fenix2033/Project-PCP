#ifndef FILEMANAGER_H
#define FILEMANAGER_H


#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <vector>

class FileManager
{
public:
    FileManager();

    static std::vector<int> loadXml();
    static std::vector<int> writeXml();
};

#endif // FILEMANAGER_H
