#include "threadrunner.h"

ThreadRunner::ThreadRunner(QObject *parent) : QObject(parent)
{

}

bool ThreadRunner::filter2(const int &val){
    if(val==2){return true;}
    return true;
}
void ThreadRunner::reduce2(int &result, const int &iteration)
{
    result+=(iteration);
}
int ThreadRunner::add(const int &val){
    return sum+=val;
}

void ThreadRunner::runProcess()
{
    resource = {0,1,2,3,4,5,6,7};
    QFuture<int> test1 = QtConcurrent::filtered(resource, [=](const int &val){return val>5;});
    qDebug() << "abc" << test1.results();
    QFuture<int> test2 = QtConcurrent::filteredReduced(resource,[=](const int &val){return val>5;},&ThreadRunner::reduce2);
    qDebug() << "abc" << test2.results();
}
