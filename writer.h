#ifndef WRITER_H
#define WRITER_H

#include <QThread>
#include <QString>

#include "databuffer.h"
#include "datapool.h"

class Writer : public QThread
{
public:
    Writer(DataPool<DataBuffer> &zippedFilesPool, const QString ecfFileName);
    virtual void run();
private:
    DataPool<DataBuffer> &_zippedFilesPool;
    QString _ecfFileName;
};

#endif // WRITER_H
