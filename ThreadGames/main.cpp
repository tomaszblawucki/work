#include <QCoreApplication>
#include <thread>
#include <iostream>
#include <mutex>

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



//    thread t1(function1);
//    thread t2(function1);


//    t1.join();
//    t2.join();


//    cout<<"Greets from MAIN THREAD "<< this_thread::get_id() << endl;
//    cout<<"MAX THREAD COUNT: "<< thread::hardware_concurrency() << endl;



    return a.exec();
}
