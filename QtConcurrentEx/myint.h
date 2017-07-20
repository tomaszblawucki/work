#ifndef MYINT_H
#define MYINT_H


class MyInt
{
private:
    int val = 0;

public:
    void add(int a){val +=a;}
    int get(){return val;}
    MyInt();
};

#endif // MYINT_H
