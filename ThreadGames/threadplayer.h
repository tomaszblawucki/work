#ifndef THREADPLAYER_H
#define THREADPLAYER_H
#include "filemanager.h"

class ThreadPlayer
{
protected:
    FileManager *fman;

public:
    ThreadPlayer(const char* path);
    std::string fetchInstruction();
    int randomNumber(int min, int max);

};

#endif // THREADPLAYER_H
