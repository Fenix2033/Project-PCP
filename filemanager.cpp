#include "filemanager.h"

FileManager::FileManager()
{

}

std::vector<int> FileManager::loadXml(){
    std::vector<int> building(36, 0);

   QFile file(":/save.xml");

    if (file.open(QIODevice::ReadOnly)){

        QXmlStreamReader xmlReader;
        xmlReader.setDevice(&file);
        xmlReader.readNext();

        while(!xmlReader.isEndDocument()){

            if (xmlReader.isStartElement()){
                QString name = xmlReader.name().toString();
                if (name=="field"){

                    int index = xmlReader.attributes().value("index").toInt();
                    int mineCount = xmlReader.readElementText().toInt();
                    building.at(index) = mineCount;
                } else if (name == "mines"){
                    // skip
                } else {
                    qCritical() << "Narazil jsem na element jiny nez field" << name <<"\n";
                }
            }

            xmlReader.readNext();
        }
    } else {
        qCritical() << "Soubor se nepovedlo otevrit\n";
    }

    return building;
}

