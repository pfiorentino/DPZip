#ifndef ZIPPEDBUFFERPOOL_H
#define ZIPPEDBUFFERPOOL_H

#include <QPair>
#include <QList>
#include <QMutex>

#include "zippedbuffer.h"

class ZippedBufferPool
{
public:
    ZippedBufferPool();
    void put(ZippedBuffer &zb);
    QPair<bool, ZippedBuffer> tryGet();
    void done();
private:
    QList<ZippedBuffer> _cfiles;
    QMutex _mutex;
};

#endif // ZIPPEDBUFFERPOOL_H
