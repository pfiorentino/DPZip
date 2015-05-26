#include "writer.h"

#include <QDebug>
#include <QFile>
#include <QDataStream>


Writer::Writer(DataPool<DataBuffer> &zippedFilesPool, QString ecfFileName):
    _zippedFilesPool(zippedFilesPool), _ecfFileName(ecfFileName)
{
}

void Writer::run(){
    QFile file(_ecfFileName);
    int count = 0;

    if(file.open(QFile::WriteOnly) == true) {
        QDataStream stream(&file);
        QPair<bool, DataBuffer> pair = _zippedFilesPool.tryGet();

        while (pair.first) {
            pair.second.write(stream);
            ++count;
            pair = _zippedFilesPool.tryGet();
        }
    }

    file.close();
    qDebug() << count << "file(s) written";
}
