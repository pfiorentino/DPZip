#ifndef READER_H
#define READER_H

#include <QThread>
#include <QString>

#include "databuffer.h"
#include "datapool.h"

/**
 * @brief La classe Reader permet de désérialiser le contenu d'un fichier .ecf
 * et de stocker les objets obtenus (compressés) dans un DataPool
 */
class Reader : public QThread
{
public:
    /**
     * @brief Reader constructeur de la classe
     * @param ecfFileName fichier à désérialiser
     * @param _zippedFilesPool DataPool d'objets désérialisés (mais compressées)
     */
    Reader(const QString ecfFileName, DataPool<DataBuffer> &_zippedFilesPool);
    virtual void run();
private:
    /**
     * @brief _ecfFileName fichier .ecf à désérialiser
     */
    QString _ecfFileName;
    /**
     * @brief _zippedFilesPool DataPool de données désérialisées (mais compressées)
     */
    DataPool<DataBuffer> &_zippedFilesPool;
};

#endif // READER_H
