#ifndef ZIPPER_H
#define ZIPPER_H

#include <QThread>
#include <QString>

#include "databuffer.h"
#include "datapool.h"

/**
 * @brief La classe Zipper permet de compresser les données d'un DataPool et de les stocker dans un second DataPool
 */
class Zipper : public QThread
{
public:
    /**
     * @brief Zipper constructeur de la classe
     * @param filesPool DataPool de fichiers non compressés
     * @param zippedFilesPool DataPool de fichiers compressés
     * @param rootDir répertoire à compresser
     */
    Zipper(DataPool<QString> &filesPool, DataPool<DataBuffer> &zippedFilesPool, const QString &rootDir);
    virtual void run();
private:
    /**
     * @brief processFile ouvre un fichier, le lit, compresse les données et l'ajoute au DataPool compressé
     * @param fileName chemin relatif vers le fichier à compresser
     */
    void processFile(const QString &fileName);
    /**
     * @brief _filesPool DataPool de fichiers à compresser
     */
    DataPool<QString> &_filesPool;
    /**
     * @brief _zippedFilesPool DataPool de fichiers compressés
     */
    DataPool<DataBuffer> &_zippedFilesPool;
    /**
     * @brief _rootDir répertoire à compresser
     */
    const QString &_rootDir;
};

#endif // ZIPPER_H
