#include "zipper.h"

#include <QDebug>
#include <QFile>
#include <QPair>

Zipper::Zipper(DataPool<QString> &filePool, DataPool<ZippedBuffer> &zippedPool, const QString &rootDir):
    _filePool(filePool), _zippedPool(zippedPool), _rootDir(rootDir)
{
}

void Zipper::run(){
    QPair<bool, QString> fileName;
    fileName = _filePool.tryGet();

    while (fileName.first) {
        processFile(fileName.second);
        fileName = _filePool.tryGet();
    }
}

void Zipper::processFile(const QString &fileName) {
    QFile file(fileName);

    if (file.open(QFile::ReadOnly) == true){
        ZippedBuffer zb = ZippedBuffer();
        QString relativeName = fileName;
        relativeName.replace(_rootDir, "");
        zb.setFileName(relativeName);
        zb.setCFileContent(qCompress(file.readAll()));
        //zb.setCFileContent(file.readAll());
        //sleep(1);
        _zippedPool.put(zb);
    }
}

