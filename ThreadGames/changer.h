#ifndef CHANGER_H
#define CHANGER_H
#include "threadplayer.h"
#include <condition_variable>

extern bool masterToken;
extern bool changerToken;
extern std::condition_variable slaveCondition;

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
