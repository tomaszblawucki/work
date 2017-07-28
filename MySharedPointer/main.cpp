#include <QCoreApplication>
#include "mypointer.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    int var = 10;
    {
    MyPointer<int> ptr(var);
    MyPointer<int> ptr2(ptr);
    MyPointer<double>ptr3(new double(2.35));
    MyPointer<double> ptr4 = ptr3;
    ptr4.reset(new double(3.14));
    ptr3.reset(ptr4.getPtr());
    }
    return a.exec();
}
