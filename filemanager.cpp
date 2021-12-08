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
                    // skip
                } else {
                    qCritical() << "Not element field" << name <<"\n";
                }
            }

            xmlReader.readNext();
        }
    } else {
        qCritical() << "File is not opne\n";
    }

    file.close();
    return building;
}

std::vector<int> FileManager::writeXml(){
    QFile file(":/save.xml");

     if(file.open(QIODevice::WriteOnly)){

        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartElement("building");
        for (auto i : building){
            int field = building.at(i);
            xmlWriter.writeStartElement("field");
 //           xmlWriter.writeAttribute("index", building.at(i).field);
            xmlWriter.writeEndElement();
        }
    }
}

