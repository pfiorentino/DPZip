#include "zippedbufferpool.h"

#include <QDebug>

ZippedBufferPool::ZippedBufferPool()
{
}

void ZippedBufferPool::put(ZippedBuffer &zb) {
    _mutex.lock();
    _cfiles.append(zb);
    _fileAvailable.wakeAll();
    _mutex.unlock();
}

QPair<bool, ZippedBuffer> ZippedBufferPool::tryGet() {
    QPair<bool, ZippedBuffer> result(false, ZippedBuffer());

    _mutex.lock();
    if (_cfiles.isEmpty() && _isFilesRemaining){
        _fileAvailable.wait(&_mutex);
    }
    if (_cfiles.isEmpty() == false) {
        ZippedBuffer cfile = _cfiles.front();
        _cfiles.pop_front();

        result.first = true;
        result.second = cfile;
    }
    _mutex.unlock();

    return result;
}

void ZippedBufferPool::done() {
    _isFilesRemaining = false;
    _fileAvailable.wakeAll();
}
