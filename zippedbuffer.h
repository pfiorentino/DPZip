#ifndef ZIPPEDBUFFER_H
#define ZIPPEDBUFFER_H

#include <QByteArray>
#include <QString>

class ZippedBuffer
{
public:
    ZippedBuffer();
    void setFileName(const QString &fileName);
    const QString getFileName();
    void setCFileContent(const QByteArray &cFileContent);
    void write(QDataStream &stream);
    void read(const QDataStream &stream);
private:
    QString _fileName;
    QByteArray _cFileContent;
};

#endif // ZIPPEDBUFFER_H
