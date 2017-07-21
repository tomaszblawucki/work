#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <fstream>
#include <mutex>
#include <vector>
class FileManager
{
private:
    std::fstream file;
    std::string path;
    std::mutex fileMutex;
public:
    FileManager(std::string);
    std::vector<std::string> readAll();
    std::string getFirstLine();
    std::string getLastLine();
    std::string appendLine(std::string);
};

#endif // FILEMANAGER_H
