#include <QCoreApplication>
#include <thread>
#include <iostream>
#include <mutex>
#include "filemanager.h"
#include "gamemaster.h"
#include "sorter.h"
#include "finder.h"
#include "changer.h"
#include <unistd.h>
#include <condition_variable>

using namespace std;

extern mutex _mutex;
extern bool masterToken = true;
extern bool finderToken = false;
extern bool changerToken = false;
extern bool sorterToken = false;
extern std::condition_variable masterCondition;
extern std::condition_variable slaveCondition;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::srand(time(NULL));


    char* path = "C:/Users/int_tobl/Desktop/QtProjects/ThreadGames/start.txt";
    FileManager fm(path);
    Sorter s(path);
    Finder f(path);
    GameMaster gm(path);
    Changer c(path);

    thread master(gm);
    thread finder(f);
    thread sorter(s);
    thread changer(c);
    usleep(100);

    master.join();
    finder.join();
    changer.join();
    sorter.join();
    /*

    GameMaster gm("C:/Users/int_tobl/Desktop/QtProjects/ThreadGames/start.txt");
    std::cout<<gm.getCommand();

    Sorter srt("C:/Users/int_tobl/Desktop/QtProjects/ThreadGames/start.txt");

    thread t1(gm);
    thread t2(srt);


*/

    //t1.join();
    //    t2.join();


    //    cout<<"Greets from MAIN THREAD "<< this_thread::get_id() << endl;
    //    cout<<"MAX THREAD COUNT: "<< thread::hardware_concurrency() << endl;



    return a.exec();
}
