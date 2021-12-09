#include "filemanager.h"

FileManager::FileManager()
{

}

std::vector<int> building(30, 0);

std::vector<int> FileManager::loadXml(){

   QFile file(":/save.xml");

    if (file.open(QIODevice::ReadOnly)){

        QXmlStreamReader xmlReader;
        xmlReader.setDevice(&file);
        xmlReader.readNext();

        while(!xmlReader.isEndDocument()){

            if (xmlReader.isStartElement()){
                QString name = xmlReader.name().toString();
                if (name == "field"){

                    int index = xmlReader.attributes().value("index").toInt();
                    int buildingCount = xmlReader.readElementText().toInt();
                    building.at(index) = buildingCount;
                } else if (name == "building"){

                } else {
                    qCritical() << "Not element field" << name <<"\n";
                }
            }

            xmlReader.readNext();
        }
    } else {
        qCritical() << "File is not open\n";
    }

    file.close();
    return building;
}

void FileManager::writeXml(){
    QFile file(":/save.xml");

     if(file.open(QIODevice::WriteOnly)){

        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartElement("building");
        for (auto i : building){
            int buildingType = building.at(i);
            xmlWriter.writeStartElement("field");
            xmlWriter.writeAttribute("index", "buildingType");
            xmlWriter.writeEndElement();
        }
    } else {
          qCritical() << "File is not open\n";
     }

     file.close();
}
