#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
public:
    std::string name, surname;
    int age;
    Person(std::string nm, std::string snm, int ag);
};

#endif // PERSON_H
