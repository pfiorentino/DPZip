#ifndef ZIPPER_H
#define ZIPPER_H

#include <QThread>
#include <QString>

class FilePool;
class ZippedBufferPool;

class Zipper : public QThread
{
public:
    Zipper(FilePool &filePool, ZippedBufferPool &zippedPool, const QString &rootDir);
    virtual void run();
private:
    void processFile(const QString &fileName);
    FilePool &_filePool;
    ZippedBufferPool &_zippedPool;
    const QString &_rootDir;
};

#endif // ZIPPER_H
