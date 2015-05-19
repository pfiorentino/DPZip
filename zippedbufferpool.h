#ifndef ZIPPEDBUFFERPOOL_H
#define ZIPPEDBUFFERPOOL_H

#include <QPair>
#include <QList>
#include <QMutex>
#include <QWaitCondition>

#include "zippedbuffer.h"

class ZippedBufferPool
{
public:
    ZippedBufferPool();
    void put(ZippedBuffer &zb);
    QPair<bool, ZippedBuffer> tryGet();
    void done();
private:
    bool _isFilesRemaining = true;
    QList<ZippedBuffer> _cfiles;
    QMutex _mutex;
    QWaitCondition _fileAvailable;
};

#endif // ZIPPEDBUFFERPOOL_H
