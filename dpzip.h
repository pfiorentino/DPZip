#ifndef DPZIP_H
#define DPZIP_H

#include <QString>

#include "datapool.h"

class DPZip
{
public:
    DPZip(const int numThreads);
    void compress(const QString &folder, const QString &ecfFileName, bool compressHiddenFiles = false);
    void uncompress(const QString &ecfFileName, const QString &outFolder);
private:
    int _numThreads;
    void findFileInFolderAndSubfolders(const QString &folder, DataPool<QString> &pool, bool zipHiddenFiles = false);
};

#endif // DPZIP_H
