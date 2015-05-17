#ifndef ZIPPER_H
#define ZIPPER_H

#include <QThread>
#include <QString>

class FilePool;
class ZippedBufferPool;

class Zipper : public QThread
{
public:
    Zipper(FilePool &filePool, ZippedBufferPool &zippedPool);
    virtual void run();
private:
    void processFile(const QString &fileName);
    FilePool &_filePool;
    ZippedBufferPool &_zippedPool;
};

#endif // ZIPPER_H
