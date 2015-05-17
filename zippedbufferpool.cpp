#include "zippedbufferpool.h"

#include <QMutexLocker>

ZippedBufferPool::ZippedBufferPool()
{

}

void ZippedBufferPool::put(ZippedBuffer &zb) {
    _cfiles.append(zb);
}

QPair<bool, ZippedBuffer> ZippedBufferPool::tryGet() {
    QPair<bool, ZippedBuffer> result = QPair(false, nullptr);
    ZippedBuffer cfile;
    QMutexLocker locker(&mutex_);

    if(cfiles_.isEmpty() == false) {
        cfile = cfiles_.front();
        cfiles_.pop_front();

        result.first = true;
        result.second = cfile;
    }

    return result;
}

void ZippedBufferPool::done() {

}
