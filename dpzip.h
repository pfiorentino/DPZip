#ifndef DPZIP_H
#define DPZIP_H


class DPZip
{
public:
    DPZip();
    void compress(const QString &folder, const QString &ecfFileName);
    void uncompress(const QString &ecfFileName, const QString &folder);
};

#endif // DPZIP_H
