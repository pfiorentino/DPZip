#ifndef UNZIPPER_H
#define UNZIPPER_H

#include <QThread>
#include <QString>

class FilePool;
class ZippedBufferPool;

class UnZipper : public QThread
{
public:
    UnZipper(const QString &ecfFile, ZippedBufferPool &unzippedPool, const QString &outDir);
};

#endif // UNZIPPER_H
