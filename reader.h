#ifndef READER_H
#define READER_H

#include <QThread>
#include <QString>

#include "databuffer.h"
#include "datapool.h"

class Reader : public QThread
{
public:
    Reader(const QString ecfFileName, DataPool<DataBuffer> &_zippedFilesPool);
    virtual void run();
private:
    QString _ecfFileName;
    DataPool<DataBuffer> &_zippedFilesPool;
};

#endif // READER_H
