#include "zippedbuffer.h"

ZippedBuffer::ZippedBuffer(QString fileName, QByteArray cfileContent):
    _fileName(fileName), _cFileContent(cfileContent)
{
}

void ZippedBuffer::write(QDataStream &stream) {

}

void ZippedBuffer::read(const QDataStream &stream) {

}

