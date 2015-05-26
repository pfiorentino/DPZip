#include "unzipper.h"
#include <QDebug>

Unzipper::Unzipper(DataPool<DataBuffer> &zippedFilesPool, DataPool<DataBuffer> &unzippedFilesPool):
    _zippedFilesPool(zippedFilesPool), _unzippedFilesPool(unzippedFilesPool)
{
}

void Unzipper::run() {
    QPair<bool, DataBuffer> pairToUnzip;
    pairToUnzip = _zippedFilesPool.tryGet();

    while (pairToUnzip.first) {
        DataBuffer zippedFile = pairToUnzip.second;

        DataBuffer unzippedFile;
        unzippedFile.setFileName(zippedFile.getFileName());
        unzippedFile.setData(qUncompress(zippedFile.getData()));

        _unzippedFilesPool.put(unzippedFile);

        pairToUnzip = _zippedFilesPool.tryGet();
    }
}
