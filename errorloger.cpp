#include "errorloger.h"

ErrorLoger::ErrorLoger(){}

void ErrorLoger::writeError(std::string textError){
    std::ofstream file("/home/xkudla/Documents/Mendel/PCP/Project/ErrorLoger.txt", std::ios::app);
        if (file.is_open()){
            file << "\n";
            file << textError;
        } else {
            std::cout << "File Error loger is not open" << std::endl;
        }

    file.close();
}
