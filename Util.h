#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>
#include <iostream>

class Util
{

public:
    static int randomInt(int min, int max);
    static void log(std::string msg);

};

#endif // UTIL_H
