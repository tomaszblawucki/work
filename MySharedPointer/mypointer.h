#ifndef MYPOINTER_H
#define MYPOINTER_H
#include <iostream>
#include <atomic>
using namespace std;

template <class P>
class MyPointer
{
private:
    P* ptr;
    int* count;
public:
    MyPointer(P &p): ptr(&p)
    {
        count = new int(1);
        std::cout<<"First instance of SP, Counter: "<<*count;
        std::cout<<" Value: "<<*ptr<<endl;
    }

    MyPointer(P *p): ptr(p)
    {
        count = new int(1);
        std::cout<<"First instance of SP, Counter: "<<*count;
        std::cout<<" Value: "<<*ptr<<endl;

    }

    MyPointer(const MyPointer &p):ptr(p.ptr)
    {
        count = p.count;
        *count += 1;
        std::cout << "Copying constructor\ninstance number: " << *count;
        std::cout<<" Value: "<<*ptr<<endl;
    }

    virtual ~MyPointer()
    {
        *count -= 1;
        std::cout<<"Deleting instance of SP, Counter: "<<*count<<endl;
        if(*count == 0)
        {
            delete ptr;
            delete count;
            std::cout<<"Deleting ptr and counter"<<endl;
        };

    }
    void reset(P *p)
    {
        *count -= 1;
        cout<<"Deleting instance of SP in RESET "<<*count<<endl;
        if(*count == 0)
        {
            delete ptr;
            delete count;
            std::cout<<"Deleting ptr and counter";
        };
        count = new int(1);
        ptr = p;
        cout<<endl<<"Reseting,  Value: "<<*ptr<<" Count:"<<*count<<endl;
    }

    P* getPtr(){return ptr;}
};

#endif // MYPOINTER_H
