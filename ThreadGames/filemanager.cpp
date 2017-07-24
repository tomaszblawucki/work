#include "filemanager.h"
#include <iostream>
#include <vector>

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

std::string FileManager::getLastLine()
{
    std::lock_guard<std::mutex> fileGuard(this->fileMutex);
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

void FileManager::setPath(const char* path)
{
    this->path = std::string(path);
}

void FileManager::setPath(std::string p)
{
    this->path = p;
}
