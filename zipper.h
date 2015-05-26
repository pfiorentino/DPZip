#ifndef ZIPPER_H
#define ZIPPER_H

#include <QThread>
#include <QString>

#include "zippedbuffer.h"
#include "datapool.h"

class Zipper : public QThread
{
public:
    Zipper(DataPool<QString> &filePool, DataPool<ZippedBuffer> &zippedPool, const QString &rootDir);
    virtual void run();
private:
    void processFile(const QString &fileName);
    DataPool<QString> &_filePool;
    DataPool<ZippedBuffer> &_zippedPool;
    const QString &_rootDir;
};

#endif // ZIPPER_H
