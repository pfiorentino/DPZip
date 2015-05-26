#ifndef WRITER_H
#define WRITER_H

#include <QThread>
#include <QString>

#include "zippedbuffer.h"
#include "datapool.h"

class Writer : public QThread
{
public:
    Writer(DataPool<ZippedBuffer> &zippedPool, const QString ecfFileName);
    virtual void run();
private:
    DataPool<ZippedBuffer> &_zippedPool;
    QString _ecfFileName;
};

#endif // WRITER_H
