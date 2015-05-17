#include "zipper.h"

#include <QFile>

#include "filepool.h"
#include "zippedbufferpool.h"

Zipper::Zipper(FilePool &filePool, ZippedBufferPool &zippedPool):
    _filePool(filePool), _zippedPool(zippedPool)
{
}

void Zipper::run(){
    QString fileName;
    fileName = _filePool.tryGetFile();

    while (fileName != "") {
        processFile(fileName);
        fileName = _filePool.tryGetFile();
    }
}

void Zipper::processFile(const QString &fileName) {
    QFile file(fileName);
    QByteArray fileByteArray;

    if (file.open(QFile::ReadOnly) == true){
        _zippedPool.put(ZippedBuffer(fileName, qCompress(file.readAll())));
    }
}
