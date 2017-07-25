#include "gamemaster.h"
#include <random>
#include <iostream>
#include <mutex>
#include <unistd.h>

GameMaster::GameMaster(char* path):
    ThreadPlayer(path){}


void GameMaster::operator ()()
{

    std::cout<<"Master thread is runing"<<std::endl;
    while(true){
        if(masterToken == true){
            this->seq = fman->getLastLine();
            std::cout<<"MASTER Last line: "<<seq<<"Master Token:"<<masterToken <<std::endl;

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
            finderToken = true;
            changerToken = true;
            sorterToken = true;
            masterToken = false;
        }
    }
}
std::string GameMaster::getCommand()
{
    srand(time(NULL));
    return this->commands[randomNumber(0,2)];
}
