#ifndef DATAPOOL_H
#define DATAPOOL_H

#include <QPair>
#include <QList>
#include <QMutex>
#include <QWaitCondition>

template<typename T>
class DataPool
{
public:
    DataPool();
    void put(T &element);
    QPair<bool, T> tryGet();
    void done();
private:
    bool _done = false;
    QList<T> _elements;
    QMutex _mutex;
    QWaitCondition _waitCondition;
};

#endif // DATAPOOL_H
