#ifndef FINDER_H
#define FINDER_H
#include "threadplayer.h"
#include <mutex>
#include <condition_variable>

extern std::condition_variable masterCondition;
extern std::condition_variable slaveCondition;
extern bool masterToken;
extern bool finderToken ;
extern bool changerToken ;
extern bool sorterToken ;
extern bool gameOn;
extern std::mutex _mutex;

class Finder: public ThreadPlayer
{
public:
    Finder(char* path);
    void operator()();
};

#endif // FINDER_H
