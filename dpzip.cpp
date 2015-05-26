#include "dpzip.h"

#include <QDebug>
#include <QDir>

#include "zipper.h"
#include "unzipper.h"
#include "writer.h"
#include "reader.h"
#include "ucfilewriter.h"

DPZip::DPZip(const int numThread):
    _numThreads(numThread)
{
}

void DPZip::compress(const QString &folder, const QString &ecfFileName, bool compressHiddenFiles) {
    qDebug() << endl << "-> Building pools...";
    DataPool<QString> inPool;
    DataPool<DataBuffer> outPool;
    findFileInFolderAndSubfolders(folder, inPool, compressHiddenFiles);
    inPool.done();
    qDebug() << "Pools built (" << inPool.count() << "files )";

    qDebug() << endl << "-> Launching writer...";
    Writer w(outPool, ecfFileName);
    w.start();

    qDebug() << endl << "-> Launching zippers...";
    typedef std::unique_ptr<Zipper> ZipperPtr;
    std::list<ZipperPtr> zippers;
    for(int i = 0;i < _numThreads;++i) {
        auto ptr = new Zipper(inPool, outPool, folder);
        zippers.push_back(ZipperPtr(ptr));
        zippers.back()->start();
        qDebug() << "Zipper" << i << "launched";
    }

    qDebug() << " ";

    while(zippers.empty() == false) {
        zippers.front()->wait();
        zippers.pop_front();
    }

    outPool.done();

    w.wait();

    qDebug() << "Done =)";
}

void DPZip::uncompress(const QString &ecfFileName, const QString &outFolder) {
    DataPool<DataBuffer> zippedPool;
    DataPool<DataBuffer> unzippedPool;

    qDebug() << endl << "-> Launching reader...";
    Reader r(ecfFileName, zippedPool);
    r.start();

    qDebug() << endl << "-> Launching writer...";
    UCFileWriter fw(unzippedPool, outFolder);
    fw.start();

    qDebug() << endl << "-> Launching unzippers...";
    typedef std::unique_ptr<Unzipper> UnZipperPtr;
    std::list<UnZipperPtr> unZippers;
    for(int i = 0;i < _numThreads;++i) {
        auto ptr = new Unzipper(zippedPool, unzippedPool);
        unZippers.push_back(UnZipperPtr(ptr));
        unZippers.back()->start();
        qDebug() << "Unzipper" << i << "launched";
    }

    qDebug() << " ";

    while(unZippers.empty() == false) {
        unZippers.front()->wait();
        unZippers.pop_front();
    }

    unzippedPool.done();

    r.wait();
    fw.wait();

    qDebug() << "Done =)";
}

void DPZip::findFileInFolderAndSubfolders(const QString &folder, DataPool<QString> &pool, bool zipHiddenFiles)
{
    QDir dir(folder);
    // list all the entries of the current folder
    QFileInfoList filesList;
    if (zipHiddenFiles){
        filesList = dir.entryInfoList(QDir::AllEntries | QDir::Hidden | QDir::NoDotAndDotDot);
    } else {
        filesList = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    }

    foreach (const QFileInfo &entry, filesList) {
        if( entry.isDir() == true )
        {
            // it is a folder, recursive call to fill the files_
            // member with the files contained in the subfolder
            findFileInFolderAndSubfolders(entry.filePath(), pool, zipHiddenFiles);
        }
        else if(entry.isFile() == true) {
            // it is a file
            // Store it in the files_ member
            QString filePath = entry.absoluteFilePath();
            pool.put(filePath);
        }
    }
}
