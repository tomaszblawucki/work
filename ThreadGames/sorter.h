#ifndef SORTER_H
#define SORTER_H
#include "threadplayer.h"
#include <vector>
#include <condition_variable>
#include <mutex>

extern std::condition_variable masterCondition;
extern std::condition_variable slaveCondition;
extern bool masterToken;
extern bool finderToken ;
extern bool changerToken ;
extern bool sorterToken ;
extern bool gameOn;
extern std::mutex _mutex;

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
