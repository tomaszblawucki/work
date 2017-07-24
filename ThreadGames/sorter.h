#ifndef SORTER_H
#define SORTER_H
#include "threadplayer.h"
#include <vector>

class Sorter: public ThreadPlayer
{
    std::string algorithm[2] = {"sort", "partial_sort"};
    std::vector<int> numbers;
    int n;
public:
    Sorter(char* path);
    void operator()();


};

#endif // SORTER_H
