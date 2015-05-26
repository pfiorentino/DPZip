#ifndef UNZIPPER_H
#define UNZIPPER_H

#include <QThread>
#include <QString>

#include "zippedbuffer.h"
#include "datapool.h"

class Unzipper : public QThread
{
public:
    Unzipper(DataPool<ZippedBuffer> &cFiles, DataPool<ZippedBuffer> &ucFiles);
    virtual void run();
private:
    DataPool<ZippedBuffer> &_cFiles;
    DataPool<ZippedBuffer> &_ucFiles;
};

#endif // UNZIPPER_H
