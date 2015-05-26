#include "reader.h"

#include <QDebug>
#include <QFile>
#include <QDataStream>

Reader::Reader(const QString ecfFileName, DataPool<ZippedBuffer> &zippedPool):
    _ecfFileName(ecfFileName), _zippedPool(zippedPool)
{
}

void Reader::run(){
    QFile file(_ecfFileName);
    int count = 0;

    if(file.open(QFile::ReadOnly) == true) {
        QDataStream stream(&file);
        ZippedBuffer cFile;
        cFile.read(stream);

        while (cFile.getFileName() != "") {
            qDebug() << cFile.getFileName();

            _zippedPool.put(cFile);
            ++count;
            cFile.read(stream);
        }
    }

    file.close();
    _zippedPool.done();

    qDebug() << count << "file(s) extracted";
}
