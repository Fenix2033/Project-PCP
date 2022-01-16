#include "filemanager.h"

FileManager::FileManager(){}

std::vector<Building> FileManager::loadBuildings(){
   QFile file(":/saveBuildings.xml");
    std::vector<Building> buildings(25, Building());
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
                    buildings.at(index).setType(buildingCount);
                } else if (name == "building"){

                } else {
                    qCritical() << "Not element field" << name <<"\n";
                    ErrorLogger::writeError("Class: FileManager. Method: loadPlayer. Not element field");
                }
            }

            xmlReader.readNext();
        }
    } else {
        qCritical() << "File is not open\n";
        ErrorLogger::writeError("Class: FileManager. Method: loadPlayer. File is not open");
    }

    file.close();
    return buildings;
}

Player FileManager::loadPlayer(){

    QFile file(":/savePlayer.xml");
    Player player;

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
                player.loadResources(index, resourceCount);
                index++;
            } else if (name == "Player"){

            } else {
                qCritical() << "Not element field" << name <<"\n";
                ErrorLogger::writeError("Class: FileManager. Method: loadPlayer. Not element field");
            }
        }

        xmlReader.readNext();
    }

    xmlReader.readNext() - 1;

    if (xmlReader.isStartElement()){
        QString name = xmlReader.name().toString();
        if (name == "resource"){
            int turnCount = xmlReader.readElementText().toInt();
            player.loadTurn(turnCount);
        } else if (name == "Player"){

        } else {
            qCritical() << "Not element field" << name <<"\n";
            ErrorLogger::writeError("Class: FileManager. Method: loadPlayer. Not element field");
        }
    }

    xmlReader.readNext();

    index = 0;

    while(!xmlReader.isEndDocument() and index < 3){

        if (xmlReader.isStartElement()){
            QString name = xmlReader.name().toString();
            if (name == "resource"){
                int resourceProfitCount = xmlReader.readElementText().toInt();
                player.loadResourcesProfit(index, resourceProfitCount);
                index++;
            } else if (name == "Player"){

            } else {
                qCritical() << "Not element field" << name <<"\n";
                ErrorLogger::writeError("Class: FileManager. Method: loadPlayer. Not element field");
            }
        }

        xmlReader.readNext();
    }

    xmlReader.readNext() - 1;

    if (xmlReader.isStartElement()){
        QString name = xmlReader.name().toString();
        if (name == "resource"){
            int scoreCount = xmlReader.readElementText().toInt();
            player.loadScore(scoreCount);
        } else if (name == "Player"){

        } else {
            qCritical() << "Not element field" << name <<"\n";
            ErrorLogger::writeError("Class: FileManager. Method: loadPlayer. Not element field");
        }
    }




} else {
    qCritical() << "File is not open\n";
    ErrorLogger::writeError("Class: FileManager. Method: loadPlayer. File is not open");
}

     file.close();
     return player;
}

void FileManager::writeBuildings(std::vector<Building> buildings){
    QFile file("saveBuildings.xml");

     if(file.open(QIODevice::WriteOnly)){

        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("building");
        for (unsigned int i = 0; i < buildings.size(); i++){
            xmlWriter.writeStartElement("field");
            xmlWriter.writeAttribute("index", QString::number(i));
            xmlWriter.writeCharacters(QString::number(buildings.at(i).getType()));
            xmlWriter.writeEndElement();
        }
        xmlWriter.writeEndElement();
    } else {
          qCritical() << "File is not open\n";
          ErrorLogger::writeError("Class: FileManager. Method: writeBuilding. File is not open");
     }

     file.close();
}

void FileManager::writePlayer(Player player){
    QFile file("savePlayer.xml");

     if(file.open(QIODevice::WriteOnly | QIODevice::Text)){

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

        xmlWriter.writeStartElement("resource");
        xmlWriter.writeAttribute("index", "score");
        xmlWriter.writeCharacters(QString::number(player.getScore()));
        xmlWriter.writeEndElement();

        xmlWriter.writeEndElement();

    } else {
          qCritical() << "File is not open\n";
          ErrorLogger::writeError("Class: FileManager. Method: writePlayer. File is not open");
     }

     file.close();
}

void FileManager::newGame(){
    QFile fileNewField(":/newGameField.xml");
    std::vector<Building> buildings(25, Building());

     if (fileNewField.open(QIODevice::ReadOnly)){

         QXmlStreamReader xmlReader;
         xmlReader.setDevice(&fileNewField);
         xmlReader.readNext();

         while(!xmlReader.isEndDocument()){

             if (xmlReader.isStartElement()){
                 QString name = xmlReader.name().toString();
                 if (name == "field"){

                     int index = xmlReader.attributes().value("index").toInt();
                     int buildingCount = xmlReader.readElementText().toInt();
                     buildings.at(index).setType(buildingCount);
                 } else if (name == "building"){

                 } else {
                     qCritical() << "Not element field" << name <<"\n";
                     ErrorLogger::writeError("Class: FileManager. Method: newGame. Not element field");
                 }
             }

             xmlReader.readNext();
         }
     } else {
         qCritical() << "File is not open\n";
         ErrorLogger::writeError("Class: FileManager. Method: newGame. File is not open");
     }



     fileNewField.close();

     QFile fileBuildings("saveBuildings.xml");

      if(fileBuildings.open(QIODevice::WriteOnly)){

         QXmlStreamWriter xmlWriter(&fileBuildings);
         xmlWriter.setAutoFormatting(true);
         xmlWriter.writeStartDocument();
         xmlWriter.writeStartElement("building");
         for (unsigned int i = 0; i < buildings.size(); i++){
             xmlWriter.writeStartElement("field");
             xmlWriter.writeAttribute("index", QString::number(i));
             xmlWriter.writeCharacters(QString::number(buildings.at(i).getType()));
             xmlWriter.writeEndElement();
         }
         xmlWriter.writeEndElement();
     } else {
           qCritical() << "File is not open\n";
           ErrorLogger::writeError("Class: FileManager. Method: newGame. File is not open");
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

          xmlWriter.writeStartElement("resource");
          xmlWriter.writeAttribute("index", "score");
          xmlWriter.writeCharacters(QString::number(0));
          xmlWriter.writeEndElement();

          xmlWriter.writeEndElement();

     } else {
           qCritical() << "File is not open\n";
           ErrorLogger::writeError("Class: FileManager. Method: newGame. File is not open");
      }

      filePlayer.close();
}
