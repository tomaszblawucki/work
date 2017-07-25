#include "filemanager.h"
#include <iostream>
#include <vector>
#include <ctype.h>
#include <stdlib.h>
#include <locale>
#include <sstream>

FileManager::FileManager(std::string p)
{
    this->path = p;
}

std::vector<std::string> FileManager::readAll()
{
    std::lock_guard<std::mutex> fileGuard(this->fileMutex);
    std::vector<std::string> content;
    file.open(path, std::ios_base::in);
    if(file.is_open())
    {
        std::string s;
        while(getline(file, s))
            content.push_back(s);
        file.close();
        return content;
    }
    std::cout<<"SPECIFIED FILE NOT FOUND"<<std::endl;
    return content;
}

std::vector<int> FileManager::numbersTokenizer()
{
    std::vector<int> numbers;
    std::string num;
    std::stringstream ss(this->getLastNumbers());

    while(std::getline(ss, num, ','))
    {
        numbers.push_back(atoi(num.c_str()));
    }

//    for(int i= 0; i< numbers.size(); i++)
//    {
//        std::cout<<numbers[i]<<std::endl;
//    }
    return numbers;
}

std::string FileManager::getLastLine()
{

    file.open(path, std::ios_base::in);
    if(file.is_open())
    {
        file.seekg(-1, std::ios_base::end);
        bool isBeginLine = false;
        while(!isBeginLine)
        {
            char c;
            file.get(c);
            if((int)file.tellg() <= 1)
            {
                file.seekg(0);
                isBeginLine = true;
            }
            else if(c == '\n')
            {
                isBeginLine = true;
            }
            else
            {
                file.seekg(-2,std::ios_base::cur);
            }
        }
        std::string line;
        std::getline(file, line);
        //std::cout<<"Last line readen: "<<line<<std::endl;

        file.close();
        return line;
    }

    return 0;
}

std::string FileManager::getLastNumbers()
{
    file.open(path, std::ios_base::in);
    if(file.is_open())
    {
       //std::cout<<"file is open"<<std::endl;
       std::string numbers = "Not found";
       std::string line;
       std::locale loc;
       while(std::getline(file, line))
       {
           if(std::isdigit(line[0], loc) && line.size()>2)
           {
               numbers = line;
           }
       }
       file.close();
       //std::cout<<"line with numbers: "<<numbers<<std::endl;
       return numbers;
    }
    std::cout<<"file not exist"<<std::endl;
    return "";
}

std::string FileManager::getFirstLine()
{
    file.open(path, std::ios_base::in);
    if(file.is_open())
    {
       //std::cout<<"file is open"<<std::endl;
       std::string line;
       std::getline(file, line);
       file.close();
       return line;
    }
    std::cout<<"file not exist"<<std::endl;
    return "";
}

bool FileManager::appendLine(std::string line)
{

    file.open(path, std::ios_base::out|std::ios_base::app);
    if(file.is_open())
    {
       file << std::endl << line;
       file.flush();
       file.close();
       return true;
    }
    return false;
}

bool FileManager::appendLine(std::vector<int> numbers)
{

    file.open(path, std::ios_base::out|std::ios_base::app);
    if(file.is_open())
    {
       std::string output = "";
       for(int i =0; i<(numbers.size()-1); i++)
       {
           output += std::to_string(numbers[i]) + ", ";
       }
       output+=std::to_string(numbers[numbers.size()-1]);
       //std::cout<<"output: "<<output<<std::endl;
       file << std::endl <<output;
       file.flush();
       file.close();
       return true;
    }
    return false;
}

void FileManager::setPath(const char* path)
{
    this->path = std::string(path);
}

void FileManager::setPath(std::string p)
{
    this->path = p;
}
