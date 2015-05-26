#ifndef UCFILEWRITER_H
#define UCFILEWRITER_H

#include <QThread>
#include <QString>

#include "datapool.h"
#include "databuffer.h"

class UCFileWriter : public QThread
{
public:
    UCFileWriter(DataPool<DataBuffer> &unzippedFilesPool, const QString &destFolder);
    virtual void run();
private:
    DataPool<DataBuffer> &_unzippedFilesPool;
    QString _destFolder;
};

#endif // UCFILEWRITER_H
