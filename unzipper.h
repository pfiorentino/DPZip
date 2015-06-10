#ifndef UNZIPPER_H
#define UNZIPPER_H

#include <QThread>
#include <QString>

#include "databuffer.h"
#include "datapool.h"

/**
 * @brief La classe Unzipper récupère des données compressées d'un DataPool, les décompresse et les ajoute à un second DataPool
 */
class Unzipper : public QThread
{
public:
    /**
     * @brief Unzipper Constructeur de la classe
     * @param zippedFilesPool DataPool de données compressées
     * @param unzippedFilesPool DataPool de données décompressées
     */
    Unzipper(DataPool<DataBuffer> &zippedFilesPool, DataPool<DataBuffer> &unzippedFilesPool);
    virtual void run();
private:
    /**
     * @brief _zippedFilesPool DataPool de données compressées
     */
    DataPool<DataBuffer> &_zippedFilesPool;
    /**
     * @brief _unzippedFilesPool DataPool de données compressées
     */
    DataPool<DataBuffer> &_unzippedFilesPool;
};

#endif // UNZIPPER_H
