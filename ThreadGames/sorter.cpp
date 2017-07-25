#include "sorter.h"
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unistd.h>
Sorter::Sorter(char* path):ThreadPlayer(path){}

void Sorter::operator()()
{
    srand(time(NULL));

    while(true){
        if(sorterToken){
            std::cout<<"SORTER"<<std::endl;
            std::string command = fman->getLastLine();
            if(command=="sort"){
                numbers.clear();
                numbers = fman->numbersTokenizer();


                std::string operation = sortAlgorithm[randomNumber(0, 1)];

                if(operation == sortAlgorithm[0])//sort
                {
                    std::cout<<"Full sort"<<std::endl;
                    std::sort(numbers.begin(), numbers.end());
                }
                else//partial sort
                {
                    std::cout<<"Partial sort"<<std::endl;
                    int n = randomNumber(0, numbers.size()-1);
                    std::cout<<"N = "<<n<<std::endl;
                    std::partial_sort(numbers.begin(),numbers.begin() + n, numbers.end());
                }

                std::string output;
                for(unsigned int i =0; i<numbers.size()-1; i++)
                {
                    output += std::to_string(numbers[i]) + ", ";
                }
                output += std::to_string(numbers[numbers.size()-1]);

                fman->appendLine(output);

            }
            sorterToken = false;
            masterToken = true;
        }
    }
}
