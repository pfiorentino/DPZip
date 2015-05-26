#include "zipper.h"

#include <QDebug>
#include <QFile>
#include <QPair>

Zipper::Zipper(DataPool<QString> &filesPool, DataPool<DataBuffer> &zippedFilesPool, const QString &rootDir):
    _filesPool(filesPool), _zippedFilesPool(zippedFilesPool), _rootDir(rootDir)
{
}

void Zipper::run(){
    QPair<bool, QString> fileName;
    fileName = _filesPool.tryGet();

    while (fileName.first) {
        processFile(fileName.second);
        fileName = _filesPool.tryGet();
    }
}

void Zipper::processFile(const QString &fileName) {
    QFile file(fileName);

    if (file.open(QFile::ReadOnly) == true){
        DataBuffer zb = DataBuffer();
        QString relativeName = fileName;
        relativeName.replace(_rootDir, "");
        zb.setFileName(relativeName);

        QByteArray fileData = qCompress(file.readAll());
        zb.setData(fileData);

        _zippedFilesPool.put(zb);
    }
}

