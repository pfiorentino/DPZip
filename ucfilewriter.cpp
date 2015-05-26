#include "ucfilewriter.h"

#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDebug>

UCFileWriter::UCFileWriter(DataPool<ZippedBuffer> &ucFilesPool, const QString &rootFolder):
    _ucFilesPool(ucFilesPool), _rootFolder(rootFolder)
{
}

void UCFileWriter::run() {
    int count = 0;

    QPair<bool, ZippedBuffer> fileToWrite = _ucFilesPool.tryGet();

    while (fileToWrite.first) {
        QFile file(_rootFolder+fileToWrite.second.getFileName());
        QDir dir("/");
        dir.mkpath(QFileInfo(file).dir().absolutePath());

        if(file.open(QFile::WriteOnly) == true) {
            QDataStream stream(&file);
            fileToWrite.second.write(stream);
            ++count;
            file.close();
        }

        fileToWrite = _ucFilesPool.tryGet();
    }

    qDebug() << count << "file(s) written";
}
