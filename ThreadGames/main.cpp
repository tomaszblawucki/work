#include <QCoreApplication>
#include <thread>
#include <iostream>
#include <mutex>
#include "filemanager.h"
#include "gamemaster.h"
#include "sorter.h"

using namespace std;

mutex consoleMutex;

void function1()
{
   for(int i =0; i<100; i++){
       lock_guard<mutex> consoleGuard(consoleMutex);
       cout<<"thread: "<<this_thread::get_id() << " prints:" <<i<<endl;
   }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    std::string path = "C:/Users/int_tobl/Desktop/QtProjects/ThreadGames/start.txt";

    GameMaster gm("C:/Users/int_tobl/Desktop/QtProjects/ThreadGames/start.txt");
    std::cout<<gm.getCommand();

    Sorter srt("C:/Users/int_tobl/Desktop/QtProjects/ThreadGames/start.txt");

    thread t1(gm);
    thread t2(srt);




    t1.join();
//    t2.join();


//    cout<<"Greets from MAIN THREAD "<< this_thread::get_id() << endl;
//    cout<<"MAX THREAD COUNT: "<< thread::hardware_concurrency() << endl;



    return a.exec();
}
