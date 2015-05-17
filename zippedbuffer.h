#ifndef ZIPPEDBUFFER_H
#define ZIPPEDBUFFER_H

#include <QByteArray>

class ZippedBuffer
{
public:
    ZippedBuffer(QString fileName, QByteArray cfileContent);
    void write(QDataStream &stream);
    void read(const QDataStream &stream);
private:
    QString _fileName;
    QByteArray _cFileContent;
};

#endif // ZIPPEDBUFFER_H
