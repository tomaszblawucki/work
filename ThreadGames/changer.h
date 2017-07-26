#ifndef CHANGER_H
#define CHANGER_H
#include "threadplayer.h"
#include <condition_variable>
#include <mutex>

extern std::condition_variable masterCondition;
extern std::condition_variable slaveCondition;
extern bool masterToken;
extern bool gameOn;
extern bool finderToken ;
extern bool changerToken ;
extern bool sorterToken ;
extern std::mutex _mutex;

class Changer: public ThreadPlayer
{
private:
    const std::string task[2] = {"add","remove"};
    const std::string algorithm[3] = {"random_shuffle", "reverse", "rotate"};
public:
    Changer(char* path);
    void operator()();
};

#endif // CHANGER_H
