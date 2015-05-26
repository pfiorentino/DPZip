#include "reader.h"

#include <QDebug>
#include <QFile>
#include <QDataStream>

Reader::Reader(const QString ecfFileName, DataPool<DataBuffer> &zippedFilesPool):
    _ecfFileName(ecfFileName), _zippedFilesPool(zippedFilesPool)
{
}

void Reader::run(){
    QFile file(_ecfFileName);
    int count = 0;

    if(file.open(QFile::ReadOnly) == true) {
        QDataStream stream(&file);
        DataBuffer cFile;
        cFile.read(stream);

        while (cFile.getFileName() != "") {
            _zippedFilesPool.put(cFile);
            ++count;
            cFile.read(stream);
        }
    }

    file.close();
    _zippedFilesPool.done();

    qDebug() << count << "file(s) extracted";
}
