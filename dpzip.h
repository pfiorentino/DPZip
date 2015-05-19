#ifndef DPZIP_H
#define DPZIP_H

#include <QString>

class DPZip
{
public:
    DPZip(const int numThreads);
    bool compress(const QString &folder, const QString &ecfFileName);
    void uncompress(const QString &ecfFileName, const QString &folder);
private:
    int _numThreads;
};

#endif // DPZIP_H
