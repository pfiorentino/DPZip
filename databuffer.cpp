#include "databuffer.h"

#include <QDebug>

DataBuffer::DataBuffer()
{
}

void DataBuffer::setFileName(const QString &fileName) {
    _fileName = fileName;
}

const QString DataBuffer::getFileName() {
    return _fileName;
}

void DataBuffer::setData(const QByteArray &data) {
    _data = data;
}

const QByteArray DataBuffer::getData() {
    return _data;
}

void DataBuffer::read(QDataStream &stream) {
    stream >> _fileName >> _data;
}

void DataBuffer::write(QDataStream &stream) {
    stream << _fileName << _data;
}

void DataBuffer::writeRawData(QDataStream &stream) {
    stream.writeRawData(_data.data(), _data.size());
}

