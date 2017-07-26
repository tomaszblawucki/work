#include "gamemaster.h"
#include <random>
#include <iostream>
#include <mutex>
#include <unistd.h>

GameMaster::GameMaster(char* path):
    ThreadPlayer(path){}


void GameMaster::operator ()()
{

    srand(time(NULL));

    std::cout<<"Master thread is runing"<<std::endl;
    while(gameOn){
//        std::unique_lock<std::mutex> lck(_mutex);
//        while(!masterToken)
//        {
//            masterCondition.wait(lck);
//        }

        if(masterToken == true){
            std::cout<<"MASTER PROCESSING"<<std::endl;
            this->seq = fman->getLastLine();
            std::cout<<"MASTER Last line got"<<std::endl;
            std::cout<<"MASTER Last line: "<<seq<<"Master Token:"<<masterToken <<std::endl;

            if( (seq.length()==1) && ('1'<=seq[0]) && ('9' >= seq[0]))
            {
                std::cout<<"MASTER SPECIAL STRING";
                std::string output = std::string("change ") + seq[0];
                std::cout<<"MASTER TRY APPEND";
                fman->appendLine(output);
            }
            else if(fman->getLastLine() == fman->getLastNumbers() || fman->getLastLine() == "0")
            {
                std::cout<<"MASTER TRY APPEND";
                fman->appendLine(getCommand());
                std::cout<<"MASTER APPENDED"<<std::endl;
            }
            finderToken =  true;
            changerToken = true;
            sorterToken =  true;
            masterToken = false;
        }
        if(fman->getFirstLine() == fman->getLastNumbers())
        {
            gameOn = false;
        }
        //usleep(100);
    }
}
std::string GameMaster::getCommand()
{
    int num = randomNumber(0, 2);
    std::cout<<"NUMBER OF COMMAND: "<<num<<std::endl;
    return this->commands[randomNumber(0,2)];
}
