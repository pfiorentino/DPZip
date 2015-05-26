#include "ucfilewriter.h"

#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDebug>

UCFileWriter::UCFileWriter(DataPool<DataBuffer> &unzippedFilesPool, const QString &destFolder):
    _unzippedFilesPool(unzippedFilesPool), _destFolder(destFolder)
{
}

void UCFileWriter::run() {
    int count = 0;

    QPair<bool, DataBuffer> fileToWrite = _unzippedFilesPool.tryGet();

    while (fileToWrite.first) {
        QFile file(_destFolder+fileToWrite.second.getFileName());
        QDir dir("/");
        dir.mkpath(QFileInfo(file).dir().absolutePath());

        if(file.open(QFile::WriteOnly) == true) {
            QDataStream stream(&file);
            fileToWrite.second.writeRawData(stream);

            ++count;
            file.close();
        }

        fileToWrite = _unzippedFilesPool.tryGet();
    }

    qDebug() << count << "file(s) written";
}
