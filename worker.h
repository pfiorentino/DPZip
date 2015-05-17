#ifndef WORKER_H
#define WORKER_H
#include <QString>
#include <QThread>
class FilePool;
/**
 * @brief La classe Worker prend un à un les fichiers contenus dans
 * un pool et recherche la présence d'une chaine de caractères
 * dans chacun
 */
class Worker: public QThread
{
public:
    /**
     * @brief Worker initialise un workder pour un pool et un chaine donnée
     * @param pool le pool permettant d'obtenir les fichiers à traiter
     * @param toFind la chaine à rechercher dans les fichiers
     * @param displayResult active l'affichage des résultats si "true"
     */
    Worker(FilePool &pool, const QString &toFind, bool displayResult = true);
    /**
     * @brief run est appelé au démarrage du thread. Elle appelle pour chaque fichier
     * la méthode processFile et retourne quand il n'y a plus de fichier dans le pool.
     */
    virtual void run();
private:
    /**
     * @brief processFile lit le contenu du fichier passé en paramètre et recherche la
     * présence de la chaine dans chaque ligne. Si la chaine est trouvé au moins une fois,
     * le nom du fichier est affiché dans la console ainsi que le nombre de lignes contenant
     * la chaine
     * @param file_name le nom du fichier à traiter
     */
    void processFile(const QString &file_name);
    FilePool &pool_;
    QString toFind_;
    bool displayResult_;

};


#endif // WORKER_H
