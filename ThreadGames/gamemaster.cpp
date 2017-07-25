#include "gamemaster.h"
#include <random>
#include <iostream>
#include <unistd.h>

GameMaster::GameMaster(char* path):
    ThreadPlayer(path){}


void GameMaster::operator ()()
{

    std::cout<<"Master thread is runing"<<std::endl;
    while(true){
        this->seq = fman->getLastLine();
        std::cout<<"MASTER Last line: "<<seq<<std::endl;

        if( (seq.length()==1) && ('1'<=seq[0]) && ('9' >= seq[0]))
        {
            std::cout<<"MASTER SPECIAL STRING"<<std::endl;
            std::string output = std::string("change ") + seq[0];
            fman->appendLine(output);
        }
        else if(fman->getLastLine() == fman->getLastNumbers() || fman->getLastLine() == "0")
        {
            std::cout<<"going crazy";
            fman->appendLine(getCommand());
        }
        usleep(10000);
    }
}
std::string GameMaster::getCommand()
{
    srand(time(NULL));
    return this->commands[randomNumber(0,2)];
}
