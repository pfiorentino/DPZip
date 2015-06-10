#ifndef DATABUFFER_H
#define DATABUFFER_H

#include <QByteArray>
#include <QString>
#include <QDataStream>

/**
 * @brief La classe DataBuffer représente un fichier de données
 * qu'il soit compressé ou à compresser il sera stocké de la
 * même manière dans cette structure
 */
class DataBuffer {
public:
    /**
     * @brief DataBuffer contruit un nouveau fichier en mémoire
     */
    DataBuffer();

    /**
     * @brief setFileName définit le nom du fichier
     * @param fileName le nom du fichier
     */
    void setFileName(const QString &fileName);
    /**
     * @brief getFileName retourne le nom du fichier
     * @return
     */
    const QString getFileName();

    /**
     * @brief setData stocke les données brutes du fichier
     * @param data données du fichier
     */
    void setData(const QByteArray &data);
    /**
     * @brief getData retourne les données brutes du fichier
     * @return
     */
    const QByteArray getData();

    /**
     * @brief read récupère et désérialise un objet DataBuffer
     * contenu dans le QDataStream passé en paramètre
     * @param stream QDataStream contenant les Buffers sérialisés
     */
    void read(QDataStream &stream);
    /**
     * @brief write sérialise un objet DataBuffer
     * dans un QDataStream passé en paramètre
     * @param stream QDataStream cible
     */
    void write(QDataStream &stream);
    /**
     * @brief write écrit les données brutes dans un QDataStream
     * Se différencie de write par le fait qu'elle écrive directement
     * les données brutes et non l'objet sérialisé
     * @param stream QDataStream cible
     */
    void writeRawData(QDataStream &stream);

private:
    /**
     * @brief _fileName nom du fichier d'entrée/de sortie
     */
    QString _fileName;
    /**
     * @brief _data données brutes compressées ou non
     */
    QByteArray _data;
};

#endif // DATABUFFER_H
