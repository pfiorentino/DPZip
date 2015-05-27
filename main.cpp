#include "dpzip.h"
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QFile>
#include <iostream>

using namespace std;

void displayRessource(const QString &resourceName) {
    QFile file(":/resources/"+resourceName);
    if (file.open(QFile::ReadOnly)) {
        QString str(file.readAll());
        cout << str.toStdString() << endl;
        file.close();
    }
}

int main() {
    int threadsNumber = 4;
    bool compressHiddenFiles = false;
    string input;

    displayRessource("banner");

    while (input != "quit") {
        cout << "#: ";
        getline(cin, input);

        if (input != "quit"){
            if (input == "answer"){
                cout << "42" << endl;
            } else if (input == "help") {
                displayRessource("help");
            } else {
                QStringList splittedInput = QString::fromStdString(input).split(" ", QString::SkipEmptyParts);
                if (splittedInput.size() == 3 && (splittedInput.at(0) == "compress" || splittedInput.at(0) == "uncompress")) {
                    DPZip app(threadsNumber);

                    if (splittedInput.at(0) == "compress") {
                        app.compress(splittedInput.at(1), splittedInput.at(2), compressHiddenFiles);
                    } else if (splittedInput.at(0) == "uncompress") {
                        app.uncompress(splittedInput.at(1), splittedInput.at(2));
                    }
                } else if (splittedInput.size() == 2 && splittedInput.at(0) == "setThreadsNumber") {
                    threadsNumber = splittedInput.at(1).toInt();
                    if (threadsNumber < 1 || threadsNumber > 48){
                        threadsNumber = 4;
                        cout << "Invalid threads number (min: 1, max: 48)" << endl;
                    } else {
                        cout << "Threads number successfuly set to " << threadsNumber << endl;
                    }
                } else if (splittedInput.size() == 2 && splittedInput.at(0) == "compressHiddenFiles") {
                    compressHiddenFiles = splittedInput.at(1) == "true" || splittedInput.at(1) == "1";
                    cout << "Compress hidden files successfuly set to " << compressHiddenFiles << endl;
                } else {
                    cout << "Invalid input. Type \"help\" to see all supported commands." << endl;
                }
            }
        }
    }

    cout << "Bye" << endl;

    //DPZip app(4);
    //app.compress("/Users/paul/test_cpp/", "/Users/paul/pipo.ecf");
    //app.compress("/Users/paul/Downloads/", "/Users/paul/pipo.ecf");
    //app.compress("/Users/paul/Documents/", "/Users/paul/pipo.ecf");
    //app.uncompress("/Users/paul/pipo.ecf", "/Users/paul/test_cpp_u/");

    return 0;
}

