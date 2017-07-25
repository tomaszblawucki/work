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

mutex consoleMutex;
bool masterToken = true;
std::condition_variable condition;


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
    thread sorter(s);
    thread finder(f);
    thread changer(c);
    usleep(100);

    master.join();
    sorter.join();
    finder.join();
    changer.join();

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
