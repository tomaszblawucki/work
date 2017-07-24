#include "gamemaster.h"
#include <random>
#include <iostream>

GameMaster::GameMaster(char* path):ThreadPlayer(path)
{

}


void GameMaster::operator ()()
{
    std::cout<<"Master thread is runing"<<std::endl;
    this->seq = fman->getFirstLine();
    fman->appendLine(getCommand());
}

std::string GameMaster::getCommand()
{
    return this->commands[randomNumber(0,2)];
}
