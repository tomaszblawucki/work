#include "person.h"

Person::Person(std::string nm, std::string snm, int ag, QObject *parent): QObject(parent), name(nm), surname(snm), age(ag)
{

}
