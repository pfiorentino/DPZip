#ifndef DATABUFFER_H
#define DATABUFFER_H

#include <QByteArray>
#include <QString>
#include <QDataStream>

class DataBuffer {
public:
    DataBuffer();

    void setFileName(const QString &fileName);
    const QString getFileName();

    void setData(const QByteArray &data);
    const QByteArray getData();

    void read(QDataStream &stream);
    void write(QDataStream &stream);
    void writeRawData(QDataStream &stream);

private:
    QString _fileName;
    QByteArray _data;
};

#endif // DATABUFFER_H
