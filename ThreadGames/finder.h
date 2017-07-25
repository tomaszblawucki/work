#ifndef FINDER_H
#define FINDER_H
#include "threadplayer.h"
#include <mutex>
#include <condition_variable>

extern bool masterToken;
extern bool finderToken;
extern std::mutex _mutex;
extern std::condition_variable slaveCondition;
extern std::condition_variable masterCondition;

class Finder: public ThreadPlayer
{
public:
    Finder(char* path);
    void operator()();
};

#endif // FINDER_H
