#ifndef UCFILEWRITER_H
#define UCFILEWRITER_H

#include <QThread>
#include <QString>

#include "datapool.h"
#include "zippedbuffer.h"

class UCFileWriter : public QThread
{
public:
    UCFileWriter(DataPool<ZippedBuffer> &ucFilesPool, const QString &rootFolder);
    virtual void run();
private:
    DataPool<ZippedBuffer> &_ucFilesPool;
    QString _rootFolder;
};

#endif // UCFILEWRITER_H
