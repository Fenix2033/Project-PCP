#ifndef ERRORLOGER_H
#define ERRORLOGER_H
#include <vector>
#include "error.h"

class ErrorLoger
{
private:
    std::vector<Error*>m_errorLog;
public:
    ErrorLoger();
};

#endif // ERRORLOGER_H
