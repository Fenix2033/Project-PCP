#include "errorlogger.h"


ErrorLogger* ErrorLogger::s_ErrorLogger = nullptr;

ErrorLogger* ErrorLogger::getLogger(){
    if (s_ErrorLogger == nullptr){
        s_ErrorLogger = new ErrorLogger();
    }
    return s_ErrorLogger;
}

void ErrorLogger::writeError(std::string textError){
    std::ofstream file("ErrorLoger.txt", std::ios::app);
        if (file.is_open()){
            file << textError << std::endl;
        } else {
            std::cout << "File Error loger is not open" << std::endl;
        }
    std::cout << textError << std::endl;
    file.close();
}

void ErrorLogger::addError(std::string textError){
    m_errors.push_back(textError);
}

ErrorLogger::ErrorLogger(){
    loadErrorrs();
}

void ErrorLogger::loadErrorrs(){
    std::string text = "";

    std::ifstream file("ErrorLoger.txt");
    if (file.is_open()){
        while (file >> text){
            m_errors.push_back(text);
        }
        file.close();
    }
}
