#ifndef GAMEMASTER_H
#define GAMEMASTER_H
#include <thread>
#include "threadplayer.h"
#include <condition_variable>
#include <mutex>

extern std::condition_variable masterCondition;
extern std::condition_variable slaveCondition;
extern bool masterToken;
extern bool finderToken ;
extern bool changerToken ;
extern bool sorterToken ;
extern std::mutex _mutex;

class GameMaster: public ThreadPlayer
{
private:
    std::string commands[3] = {"sort", "find", "change"};
    std::string seq = "";
    //bool masterToken;
    //std::condition_variable condition;
public:
    GameMaster(char*);
    void operator()();
    std::string getCommand();

};

#endif // GAMEMASTER_H
