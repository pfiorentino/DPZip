#ifndef WRITER_H
#define WRITER_H

#include <QThread>
#include <QString>

#include "zippedbufferpool.h"
#include "zippedbuffer.h"

class Writer : public QThread
{
public:
    Writer(ZippedBufferPool &zippedPool, const QString ecfFileName);
    virtual void run();
private:
    ZippedBufferPool &_zippedPool;
    QString _ecfFileName;
};

#endif // WRITER_H
