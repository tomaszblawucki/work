#include "sorter.h"
#include <sstream>
#include <iostream>
Sorter::Sorter(char* path):ThreadPlayer(path)
{

}

void Sorter::operator()()
{
    numbers.clear();
    std::string line = fman->getLastLine();
    std::cout<<"Sorter read: "<<line<<std::endl;
    std::stringstream ss(line);
}
