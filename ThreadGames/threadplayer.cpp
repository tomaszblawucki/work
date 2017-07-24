#include "threadplayer.h"
#include "filemanager.h"

ThreadPlayer::ThreadPlayer(const char *path)
{
    fman = new FileManager(std::string(path));
}

std::string ThreadPlayer::fetchInstruction()
{

}

int ThreadPlayer::randomNumber(int min, int max)
{
    srand(time(NULL));
    //std::cout << rand()%(max-min)+min;
    return rand()%(max+1-min)+min;
}
