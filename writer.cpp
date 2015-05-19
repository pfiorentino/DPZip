#include "writer.h"

#include <QDebug>
#include <QFile>
#include <QDataStream>


Writer::Writer(ZippedBufferPool &zippedPool, QString ecfFileName):
    _zippedPool(zippedPool), _ecfFileName(ecfFileName)
{
}

void Writer::run(){
    QFile file(_ecfFileName);
    int count = 0;

    if(file.open(QFile::WriteOnly) == true) {
        QDataStream stream(&file);
        QPair<bool, ZippedBuffer> pair = _zippedPool.tryGet();

        while (pair.first) {
            pair.second.write(stream);
            ++count;
            pair = _zippedPool.tryGet();
        }
    }

    file.close();
    qDebug() << count << "file(s) written";
}
