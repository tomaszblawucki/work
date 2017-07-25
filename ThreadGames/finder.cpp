#include "finder.h"
#include <iostream>
#include <algorithm>
#include <unistd.h>
Finder::Finder(char* path):ThreadPlayer(path){}

void Finder::operator()()
{
    srand(time(NULL));


    while(true){
        if(finderToken){
            std::cout<<"FINDER"<<std::endl;
            std::string command = fman->getLastLine();
            if(command == "find"){
                int num  = randomNumber(0, 5);
                std::vector<int> numbers = fman->numbersTokenizer();
                std::vector<int>::iterator it;
                it = std::find(numbers.begin(), numbers.end(), num);

                if(it != numbers.end())
                {
                    std::cout<<"number: "<<num << "FOUND" <<std::endl;
                    std::string output = std::to_string(0);
                    fman->appendLine(output);
                }
                else
                {
                    std::cout<<"Appending to file number: "<<num<<std::endl;
                    std::string output = std::to_string(num);
                    fman->appendLine(output);
                }
            }
            finderToken = false;
            masterToken = true;
        }
    }
}
