#include "datapool.h"

#include "databuffer.h"

template<typename T>
DataPool<T>::DataPool()
{
}

template<typename T>
void DataPool<T>::put(T &element) {
    QMutexLocker locker(&_mutex);
    _elements.append(element);
    _waitCondition.wakeAll();
}

template<typename T>
QPair<bool, T> DataPool<T>::tryGet() {
    QPair<bool, T> result(false, T());

    QMutexLocker locker(&_mutex);

    if (_elements.isEmpty() && _done == false){
        _waitCondition.wait(&_mutex);
    }
    if (_elements.isEmpty() == false) {
        T element = _elements.front();
        _elements.pop_front();

        result.first = true;
        result.second = element;
    }

    return result;
}

template<typename T>
int DataPool<T>::count() {
    QMutexLocker locker(&_mutex);
    return _elements.size();
}

template<typename T>
void DataPool<T>::done() {
    QMutexLocker locker(&_mutex);
    _done = true;
    _waitCondition.wakeAll();
}

template class DataPool<QString>;
template class DataPool<DataBuffer>;
