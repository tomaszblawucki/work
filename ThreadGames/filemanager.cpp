#include "filemanager.h"
#include <vector>

FileManager::FileManager(std::string p)
{
    this->path = p;
}

std::vector<std::string> FileManager::readAll()
{
    //std::lock_guard<std::mutex> fileGuard(this->fileMutex);
    std::vector<std::string> content;
    file.open(path,std::ios_base::in);
    if(file.is_open())
    {
        std::string s;
        while(getline(file, s))
            content.push_back(s);
        file.close();
        return content;
    }
    std::cout<<"SPECIFIED FILE NOT FOUND"<<endl;
    return 0;
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
        cout<<"Last line readen: "<<line<<endl;

        file.close();
        return line;
    }

    return 0;
}

std::string FileManager::getFirstLine()
{
    return 0;
}

std::string FileManager::appendLine(std::string line)
{
    return 0;
}
