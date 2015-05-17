#include "worker.h"
#include "filepool.h"
#include <QFile>
#include <QTextStream>

#include <iostream>
Worker::Worker(FilePool &pool, const QString &toFind, bool displayResult):
        pool_(pool), toFind_(toFind),displayResult_(displayResult)
{
}
void Worker::run()
{
    QString filename;
    filename = pool_.tryGetFile();
    // Tant qu'il y a des fichiers dans le pool
    while(filename != "") {
        // traite le fichier
        processFile(filename);
        // essaye de prendre un autre fichier
        // à traiter
        filename = pool_.tryGetFile();
    }
}

void Worker::processFile(const QString &filename) {
    QFile file(filename);
    int count = 0;
    // Ouvertue du fichier en mode lecture seule
    if( file.open(QFile::ReadOnly) == true) {
        QTextStream stream(&file);
        // Tant qu'on n'est pas à la fin du fichier
        while(stream.atEnd() == false) {
            // On lit une ligne et on cherche la chaine
            if(stream.readLine().contains(toFind_) == true ) {
                ++count;
            }
        }
    }
    if(displayResult_ == true && count != 0 ) {
        std::cout << filename.toStdString() << " : " << count << " times" << std::endl;
    }
}



