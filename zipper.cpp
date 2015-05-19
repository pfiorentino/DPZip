#include "zipper.h"

#include <QDebug>
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

    if (file.open(QFile::ReadOnly) == true){
        ZippedBuffer zb = ZippedBuffer();
        zb.setFileName(fileName);
        zb.setCFileContent(qCompress(file.readAll()));
        //sleep(1);
        _zippedPool.put(zb);
    }
}
