#include "changer.h"
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unistd.h>

Changer::Changer(char* path):ThreadPlayer(path){}

void Changer::operator()()
{
    srand(time(NULL));

    while(gameOn){
//        std::unique_lock<std::mutex> lck(_mutex);
//        while(!changerToken)
//        {
//            slaveCondition.wait(lck);
//        }

        if(changerToken){
            std::cout<<"CHANGER"<<std::endl;
            std::stringstream ss(fman->getLastLine());
            std::string command;
            std::string num;
            ss >> command;
            ss >> num;
            //std::cout<<"command:" << command<< " number: " << num <<std::endl;
            if(command == "change")
            {

                std::cout<<"changer in work"<<std::endl;
                std::vector<int> numbers = fman->numbersTokenizer();
                std::vector<int>::iterator it;
                if(num.length() == 0)
                {
                    int i = randomNumber(0, 2);
                    if(algorithm[i] == "random_shuffle")
                    {
                        std::cout<<"shuffle elements";
                        std::random_shuffle(numbers.begin(), numbers.end());
                    }
                    else if(algorithm[i] == "reverse")
                    {
                        std::cout<<"reverse elements";
                        std::reverse(numbers.begin(), numbers.end());
                    }
                    else//rotate
                    {
                        std::cout<<"rotate elements";
                        std::rotate(numbers.begin(), numbers.begin()+randomNumber(0, numbers.size()-1), numbers.end());
                    }
                }

                else
                {
                    if((task[randomNumber(0, 1)] == "add") && !((numbers.size()) > 10))
                    {
                        std::cout<<"adding"<< num<< "elements\n";
                        for(int i=0; i<std::stoi(num); i++)
                        {
                            if(numbers.size() >= 10)break;
                            int random = randomNumber(0, 20);
                            std::cout<<"random to push: "<<random<<std::endl;
                            numbers.push_back(random);          
                        }

                    }
                    else
                    {
                        std::cout<<"removing elements";
                        int index  = std::stoi(num);
                        std::cout<<"vector size: "<<numbers.size()<<std::endl;
                        for(int i=0; i<index; i++)
                        {
                            if(numbers.size()<=5)break;
                            it = numbers.begin();
                            std::advance(it, randomNumber(0, numbers.size()-1));
                            numbers.erase(it);

                            //numbers.erase(numbers.begin()/* + randomNumber(0, numbers.size()-1)*/);
                        }

                    }

                }
                //        std::cout<<"AFTER CHANGE \n";
                //        for(int i =0; i<numbers.size(); i++)
                //        {
                //            std::cout<<numbers[i]<<" ";
                //        }

                std::cout<<"CHANGER TRY APPEND";
                fman->appendLine(numbers);
                std::cout<<"CHANGER APPENDED!!"<<std::endl;
                masterToken = true;
            }
            changerToken = false;



            //usleep(100);

        }
    }
}
