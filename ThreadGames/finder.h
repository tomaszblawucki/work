#ifndef FINDER_H
#define FINDER_H
#include "threadplayer.h"

class Finder: public ThreadPlayer
{
public:
    Finder(char* path);
    void operator()();
};

#endif // FINDER_H
