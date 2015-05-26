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
    const QByteArray getCFileContent();
    void write(QDataStream &stream);
    void read(QDataStream &stream);
private:
    QString _fileName;
    QByteArray _cFileContent;
};

#endif // ZIPPEDBUFFER_H
