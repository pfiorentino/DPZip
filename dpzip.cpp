#include "dpzip.h"

#include <QDebug>

#include "filepool.h"
#include "zippedbufferpool.h"
#include "zipper.h"
#include "writer.h"

DPZip::DPZip(const int numThread):
    _numThreads(numThread)
{
}

bool DPZip::compress(const QString &folder, const QString &ecfFileName) {
    qDebug() << endl << "-> Building pools...";
    FilePool pool(folder);
    ZippedBufferPool cPool;
    qDebug() << "Pools built (" << pool.count() << "files )";

    qDebug() << endl << "-> Launching writer...";
    Writer w(cPool, ecfFileName);
    w.start();

    qDebug() << endl << "-> Launching zippers...";
    typedef std::unique_ptr<Zipper> ZipperPtr;
    std::list<ZipperPtr> zippers;
    for(int i = 0;i < _numThreads;++i) {
        auto ptr = new Zipper(pool, cPool, folder);
        zippers.push_back(ZipperPtr(ptr));
        zippers.back()->start();
        qDebug() << "Zipper" << i << "launched";
    }

    qDebug() << " ";

    while(zippers.empty() == false) {
        zippers.front()->wait();
        zippers.pop_front();
    }

    cPool.done();

    w.wait();

    qDebug() << "Done :)";

    return true;
}

void DPZip::uncompress(const QString &ecfFileName, const QString &folder) {
    QString pipo = ecfFileName;
    pipo = folder;
}
