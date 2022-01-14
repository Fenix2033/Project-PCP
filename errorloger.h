#ifndef ERRORLOGER_H
#define ERRORLOGER_H
#include <iostream>
#include <fstream>

class ErrorLoger{

public:
    ErrorLoger();
    static void writeError(std::string textError);
};



#endif // ERRORLOGER_H
