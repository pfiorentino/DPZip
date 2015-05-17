#ifndef ZIPPEDBUFFER_H
#define ZIPPEDBUFFER_H

#include <QByteArray>

class ZippedBuffer
{
public:
    ZippedBuffer();
    void write(QDataStream &stream);
    void read(const QDataStream &stream);
private:
    QString fileName;
    QByteArray compressedFileContent;
};

#endif // ZIPPEDBUFFER_H
