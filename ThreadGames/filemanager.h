#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <fstream>
#include <mutex>
#include <vector>

class FileManager
{
private:
    std::fstream file;
    std::string path = "";
    std::mutex fileMutex;
public:
    FileManager();
    FileManager(std::string);
    std::vector<std::string> readAll();
    std::vector<int>numbersTokenizer();
    std::string getFirstLine();
    std::string getLastLine();
    std::string getLastNumbers();
    bool appendLine(std::string);
    bool appendLine(std::vector<int>);
    void setPath(const char*);
    void setPath(std::string);
};

#endif // FILEMANAGER_H
