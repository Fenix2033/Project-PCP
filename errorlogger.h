#ifndef ERRORLOGGER_H
#define ERRORLOGGER_H
#include <iostream>
#include <vector>
#include <fstream>

class ErrorLogger{
    static ErrorLogger* s_ErrorLogger;
    std::vector<std::string> m_errors;
public:
    static ErrorLogger* getLogger();
    static void writeError(std::string textError);
    void addError(std::string textError);
    void storeErrors();
private:
    ErrorLogger();
    void loadErrorrs();
};



#endif // ERRORLOGGER_H
