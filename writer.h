#ifndef WRITER_H
#define WRITER_H

#include <QThread>
#include <QString>

#include "databuffer.h"
#include "datapool.h"

/**
 * @brief La classe Writer écrit un fichier .ecf à partir d'un DataPool de donées compressées
 */
class Writer : public QThread
{
public:
    /**
     * @brief Writer constructeur de la classe
     * @param zippedFilesPool DataPool de fichiers compressés
     * @param ecfFileName fichier .ecf de destination
     */
    Writer(DataPool<DataBuffer> &zippedFilesPool, const QString ecfFileName);
    virtual void run();
private:
    /**
     * @brief _zippedFilesPool DataPool de fichiers compressés
     */
    DataPool<DataBuffer> &_zippedFilesPool;
    /**
     * @brief _ecfFileName fichier .ecf de destination
     */
    QString _ecfFileName;
};

#endif // WRITER_H
