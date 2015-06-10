#ifndef DPZIP_H
#define DPZIP_H

#include <QString>

#include "datapool.h"

/**
 * @brief La classe DPZip est la classe principale de l'application
 * elle permet la compression et la décompression de fichiers
 */
class DPZip
{
public:
    /**
     * @brief DPZip contructeur de la classe
     * @param numThreads nombre de threads de zipper ou de unzipper à lancer
     */
    DPZip(const int numThreads);
    /**
     * @brief compress compresse un dossier dans un fichier .ecf
     * @param folder dossier à compresser
     * @param ecfFileName fichier .ecf de destination
     * @param compressHiddenFiles ajouter ou non les fichiers cachés du système d'exploitation
     * à l'archive
     */
    void compress(const QString &folder, const QString &ecfFileName, bool compressHiddenFiles = false);
    /**
     * @brief uncompress décompresse un fichier .ecf dans un répertoire donné
     * @param ecfFileName fichier à décompresser
     * @param outFolder répertoire de destination, s'il n'existe pas il sera créé
     */
    void uncompress(const QString &ecfFileName, const QString &outFolder);
private:
    /**
     * @brief _numThreads nombre de threads de zipper ou de unzipper à lancer
     */
    int _numThreads;
    /**
     * @brief findFileInFolderAndSubfolders recherche récusivement tous les fichiers d'un
     * répertoire
     * @param folder répertoire source
     * @param pool DataPool de fichiers trouvés
     * @param zipHiddenFiles ajouter ou non les fichiers cachés du système d'exploitation
     * au pool
     */
    void findFileInFolderAndSubfolders(const QString &folder, DataPool<QString> &pool, bool zipHiddenFiles = false);
};

#endif // DPZIP_H
