#ifndef READER_H
#define READER_H

#include <QThread>
#include <QString>

#include "zippedbuffer.h"
#include "datapool.h"

class Reader : public QThread
{
public:
    Reader(const QString ecfFileName, DataPool<ZippedBuffer> &zippedPool);
    virtual void run();
private:
    QString _ecfFileName;
    DataPool<ZippedBuffer> &_zippedPool;
};

#endif // READER_H
