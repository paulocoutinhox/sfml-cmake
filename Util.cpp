#include "Util.h"

int Util::randomInt(int min, int max)
{
    return min + (rand() % (int)(max - min + 1));
}

void Util::log(std::string msg)
{
    // show debug log
    std::cout << "DEBUG: " << msg << std::endl;
}
