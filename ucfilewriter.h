#ifndef UCFILEWRITER_H
#define UCFILEWRITER_H

#include <QThread>
#include <QString>

#include "datapool.h"
#include "databuffer.h"

/**
 * @brief La classe UCFileWriter permet d'écrire sur le disque tous les fichiers d'un DataPool passé en paramètre
 */
class UCFileWriter : public QThread
{
public:
    /**
     * @brief UCFileWriter constructeur de la classe
     * @param unzippedFilesPool DataPool de données décompressées à écrire
     * @param destFolder dossier racine de destination (chaque fichier contient son path relatif à ce dossier)
     */
    UCFileWriter(DataPool<DataBuffer> &unzippedFilesPool, const QString &destFolder);
    virtual void run();
private:
    /**
     * @brief _unzippedFilesPool DataPool de données décompressées à écrire
     */
    DataPool<DataBuffer> &_unzippedFilesPool;
    /**
     * @brief _destFolder dossier racine de destination (chaque fichier contient son path relatif à ce dossier)
     */
    QString _destFolder;
};

#endif // UCFILEWRITER_H
