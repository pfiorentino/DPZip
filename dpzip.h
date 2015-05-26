#ifndef DPZIP_H
#define DPZIP_H

#include <QString>

#include "datapool.h"

class DPZip
{
public:
    DPZip(const int numThreads);
    void compress(const QString &folder, const QString &ecfFileName);
    void uncompress(const QString &ecfFileName, const QString &folder);
private:
    int _numThreads;
    void findFileInFolderAndSubfolders(const QString &folder, DataPool<QString> &pool);
};

#endif // DPZIP_H
