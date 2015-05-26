#ifndef ZIPPER_H
#define ZIPPER_H

#include <QThread>
#include <QString>

#include "databuffer.h"
#include "datapool.h"

class Zipper : public QThread
{
public:
    Zipper(DataPool<QString> &filesPool, DataPool<DataBuffer> &zippedFilesPool, const QString &rootDir);
    virtual void run();
private:
    void processFile(const QString &fileName);
    DataPool<QString> &_filesPool;
    DataPool<DataBuffer> &_zippedFilesPool;
    const QString &_rootDir;
};

#endif // ZIPPER_H
