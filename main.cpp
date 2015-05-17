#include <iostream>
#include "filepool.h"

#include <QElapsedTimer>

using namespace std;

int main()
{
    cout << "Building pool" << endl;

    FilePool pool("/Users/paul/test_cpp");

    cout << "Done" << endl;
    cout << "Number of files: " << pool.count() << endl;

    QElapsedTimer timer;
    timer.start();

    cout << " done in " << timer.elapsed() << "ms" << endl;

    return 0;
}

