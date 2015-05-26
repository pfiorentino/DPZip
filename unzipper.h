#ifndef UNZIPPER_H
#define UNZIPPER_H

#include <QThread>
#include <QString>

#include "databuffer.h"
#include "datapool.h"

class Unzipper : public QThread
{
public:
    Unzipper(DataPool<DataBuffer> &zippedFilesPool, DataPool<DataBuffer> &unzippedFilesPool);
    virtual void run();
private:
    DataPool<DataBuffer> &_zippedFilesPool;
    DataPool<DataBuffer> &_unzippedFilesPool;
};

#endif // UNZIPPER_H
