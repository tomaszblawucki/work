#ifndef SORTER_H
#define SORTER_H
#include "threadplayer.h"
#include <vector>
#include <condition_variable>

extern bool masterToken;
extern bool sorterToken;
extern std::condition_variable slaveCondition;

class Sorter: public ThreadPlayer
{
    std::string sortAlgorithm[2] = {"sort", "partial_sort"};
    std::vector<int> numbers;
    int n;
public:
    Sorter(char* path);
    void operator()();


};

#endif // SORTER_H
