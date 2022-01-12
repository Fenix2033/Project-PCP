#include "filemanager.h"

FileManager::FileManager()
{

}

std::vector<int> building(30, 0);
std::vector<Building> m_buildings(30, Building());
Player m_player;

std::vector<Building> FileManager::loadBuildings(){

   QFile file(":/saveBuildings.xml");

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
    return m_buildings;
}

Player FileManager::loadPlayer(){

    QFile file(":/savePlayer.xml");

 if (file.open(QIODevice::ReadOnly)){

    QXmlStreamReader xmlReader;
    xmlReader.setDevice(&file);
    xmlReader.readNext();
    int index = 0;

    while(!xmlReader.isEndDocument() and index < 3){

        if (xmlReader.isStartElement()){
            QString name = xmlReader.name().toString();
            if (name == "resource"){
                int resourceCount = xmlReader.readElementText().toInt();
                m_player.setResources(index, resourceCount);
                index++;
            } else if (name == "Player"){

            } else {
                qCritical() << "Not element field" << name <<"\n";
            }
        }

        xmlReader.readNext();
    }

    xmlReader.readNext() - 1;

    if (xmlReader.isStartElement()){
        QString name = xmlReader.name().toString();
        if (name == "resource"){
            int turnCount = xmlReader.readElementText().toInt();
            m_player.setTurn(turnCount);
        } else if (name == "Player"){

        } else {
            qCritical() << "Not element field" << name <<"\n";
        }
    }

    xmlReader.readNext();

    index = 0;

    while(!xmlReader.isEndDocument() and index < 3){

        if (xmlReader.isStartElement()){
            QString name = xmlReader.name().toString();
            if (name == "resource"){
                int resourceProfitCount = xmlReader.readElementText().toInt();
                m_player.setProfitResources(index, resourceProfitCount);
                index++;
            } else if (name == "Player"){

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
     return m_player;
}

void FileManager::writeBuildings(int index, int buildingN){
    m_buildings.at(index).setType(buildingN);
    QFile file("/home/xkudla/Documents/Mendel/PCP/Project/saveBuildings.xml");

     if(file.open(QIODevice::WriteOnly)){

        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("building");
        for (unsigned int i = 0; i < building.size(); i++){
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

void FileManager::writePlayer(Player player){
    QFile file("/home/xkudla/Documents/Mendel/PCP/Project/savePlayer.xml");

     if(file.open(QIODevice::WriteOnly)){

        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);

        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("Player");

        xmlWriter.writeStartElement("resource");
        xmlWriter.writeAttribute("index", "gold");
        xmlWriter.writeCharacters(QString::number(player.getResources(0)));
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("resource");
        xmlWriter.writeAttribute("index", "wood");
        xmlWriter.writeCharacters(QString::number(player.getResources(1)));
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("resource");
        xmlWriter.writeAttribute("index", "stone");
        xmlWriter.writeCharacters(QString::number(player.getResources(2)));
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("resource");
        xmlWriter.writeAttribute("index", "turn");
        xmlWriter.writeCharacters(QString::number(player.getTurn()));
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("resource");
        xmlWriter.writeAttribute("index", "profitGold");
        xmlWriter.writeCharacters(QString::number(player.getProfitResources(0)));
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("resource");
        xmlWriter.writeAttribute("index", "profitWood");
        xmlWriter.writeCharacters(QString::number(player.getProfitResources(1)));
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("resource");
        xmlWriter.writeAttribute("index", "profitStone");
        xmlWriter.writeCharacters(QString::number(player.getProfitResources(2)));
        xmlWriter.writeEndElement();

        xmlWriter.writeEndElement();

    } else {
          qCritical() << "File is not open\n";
     }

     file.close();
}

void FileManager::newGame(){
    QFile fileBuildings("/home/xkudla/Documents/Mendel/PCP/Project/saveBuildings.xml");

     if(fileBuildings.open(QIODevice::WriteOnly)){

        QXmlStreamWriter xmlWriter(&fileBuildings);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("building");
        for (unsigned int i = 0; i < building.size(); i++){
            xmlWriter.writeStartElement("field");
            xmlWriter.writeAttribute("index", QString::number(i));
            xmlWriter.writeCharacters(QString::number(0));
            xmlWriter.writeEndElement();
        }
        xmlWriter.writeEndElement();
    } else {
          qCritical() << "File is not open\n";
     }

     fileBuildings.close();

     QFile filePlayer("/home/xkudla/Documents/Mendel/PCP/Project/savePlayer.xml");

      if(filePlayer.open(QIODevice::WriteOnly)){

          QXmlStreamWriter xmlWriter(&filePlayer);
          xmlWriter.setAutoFormatting(true);

          xmlWriter.writeStartDocument();
          xmlWriter.writeStartElement("Player");

          xmlWriter.writeStartElement("resource");
          xmlWriter.writeAttribute("index", "gold");
          xmlWriter.writeCharacters(QString::number(2000));
          xmlWriter.writeEndElement();

          xmlWriter.writeStartElement("resource");
          xmlWriter.writeAttribute("index", "wood");
          xmlWriter.writeCharacters(QString::number(500));
          xmlWriter.writeEndElement();

          xmlWriter.writeStartElement("resource");
          xmlWriter.writeAttribute("index", "stone");
          xmlWriter.writeCharacters(QString::number(200));
          xmlWriter.writeEndElement();

          xmlWriter.writeStartElement("resource");
          xmlWriter.writeAttribute("index", "turn");
          xmlWriter.writeCharacters(QString::number(0));
          xmlWriter.writeEndElement();

          xmlWriter.writeStartElement("resource");
          xmlWriter.writeAttribute("index", "profitGold");
          xmlWriter.writeCharacters(QString::number(0));
          xmlWriter.writeEndElement();

          xmlWriter.writeStartElement("resource");
          xmlWriter.writeAttribute("index", "profitWood");
          xmlWriter.writeCharacters(QString::number(0));
          xmlWriter.writeEndElement();

          xmlWriter.writeStartElement("resource");
          xmlWriter.writeAttribute("index", "profitStone");
          xmlWriter.writeCharacters(QString::number(0));
          xmlWriter.writeEndElement();

          xmlWriter.writeEndElement();

     } else {
           qCritical() << "File is not open\n";
      }

      filePlayer.close();
}
