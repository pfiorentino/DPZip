#ifndef DATAPOOL_H
#define DATAPOOL_H

#include <QPair>
#include <QList>
#include <QMutex>
#include <QWaitCondition>

/**
 * @brief La classe DataPool est une structure de donnée qui
 * peut contenir des données de type spécifié par <template %T>
 * Toutes les méthodes de cette classe sont thread-safe
 */
template<typename T>
class DataPool
{
public:
    /**
     * @brief DataPool contruit un nouveau DataPool de données
     * thread-safe
     */
    DataPool();

    /**
     * @brief put ajoute un nouvel élément au DataPool
     * thread-safe
     * @param element élément à ajouter
     */
    void put(T &element);
    /**
     * @brief tryeGet tente de récupérer un élément du DataPool
     * thread-safe
     * @return QPair<bool, T>\n
     * bool: true si l'élément récupéré est valide\n
     * T: élément récupéré
     */
    QPair<bool, T> tryGet();

    /**
     * @brief count retourne le nombre d'éléments encore présents
     * dans le DataPool
     * thread-safe
     * @return nombre d'éléments contenus dans le pool
     */
    int count();
    /**
     * @brief done signale au DataPool qu'aucun nouvel élément sera ajouté
     * permet de libérer la QWaitCondition
     */
    void done();
private:
    /**
     * @brief _done true si plus aucun élément ne sera ajouté au DataPool
     */
    bool _done = false;
    /**
     * @brief _elements éléments du DataPool
     */
    QList<T> _elements;
    /**
     * @brief _mutex exclusion mutuelle permettant la synchronisation
     * des threads
     */
    QMutex _mutex;
    /**
     * @brief _waitCondition condition de bloquage permettant la
     * synchronisation des threads. Bloque sur un tryGet si aucun élément
     * n'est présent dans le DataPool et que _done = false
     */
    QWaitCondition _waitCondition;
};

#endif // DATAPOOL_H
