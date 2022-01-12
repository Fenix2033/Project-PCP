#include "filemanager.h"

FileManager::FileManager()
{

}

std::vector<int> building(30, 0);
std::vector<Building> m_buildings(30, Building());

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
                    m_buildings.at(index).setType(buildingCount);
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

std::vector<Building> FileManager::getBuildings(){
    return m_buildings;
}

void FileManager::writeXml(int index, int buildingN){
    m_buildings.at(index).setType(buildingN);
    QFile file("/home/xkudla/Documents/Mendel/PCP/Project/save.xml");

     if(file.open(QIODevice::WriteOnly)){

        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("building");
        for (int i = 0; i < building.size(); i++){
            xmlWriter.writeStartElement("field");
            xmlWriter.writeAttribute("index", QString::number(i));
            xmlWriter.writeCharacters(QString::number(m_buildings.at(i).getType()));
            xmlWriter.writeEndElement();
        }
        xmlWriter.writeEndElement();
    } else {
          qCritical() << "File is not open\n";
     }

     file.close();
}

void FileManager::newGame(){
    QFile file("/home/xkudla/Documents/Mendel/PCP/Project/save.xml");

     if(file.open(QIODevice::WriteOnly)){

        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("building");
        for (int i = 0; i < building.size(); i++){
            xmlWriter.writeStartElement("field");
            xmlWriter.writeAttribute("index", QString::number(i));
            xmlWriter.writeCharacters(QString::number(0));
            xmlWriter.writeEndElement();
        }
        xmlWriter.writeEndElement();
    } else {
          qCritical() << "File is not open\n";
     }

     file.close();
}
