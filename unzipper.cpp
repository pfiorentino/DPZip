#include "unzipper.h"

Unzipper::Unzipper(DataPool<ZippedBuffer> &cFiles, DataPool<ZippedBuffer> &ucFiles):
    _cFiles(cFiles), _ucFiles(ucFiles)
{

}

void Unzipper::run() {
    QPair<bool, ZippedBuffer> fileToUncompress;
    fileToUncompress = _cFiles.tryGet();

    while (fileToUncompress.first) {
        ZippedBuffer uncompressedFile;
        uncompressedFile.setFileName(fileToUncompress.second.getFileName());
        uncompressedFile.setCFileContent(qUncompress(fileToUncompress.second.getCFileContent()));
        _ucFiles.put(uncompressedFile);
        fileToUncompress = _cFiles.tryGet();
    }
}
